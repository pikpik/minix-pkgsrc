/*
 * tg3.c: Broadcom Tigon3 ethernet driver.
 *
 * Copyright (C) 2001, 2002, 2003, 2004 David S. Miller (davem@redhat.com)
 * Copyright (C) 2001, 2002, 2003 Jeff Garzik (jgarzik@pobox.com)
 * Copyright (C) 2004 Sun Microsystems Inc.
 * Copyright (C) 2005-2009 Broadcom Corporation.
 *
 * Firmware is:
 *	Derived from proprietary unpublished source code,
 *	Copyright (C) 2000-2003 Broadcom Corporation.
 *
 *	Permission is hereby granted for the distribution of this firmware
 *	data in hexadecimal or equivalent format, provided this copyright
 *	notice is accompanying it.
 *
 *	Minix port by Colin Fowler (elethiomel@gmail.com)
 */

#include <minix/drivers.h>
#include <minix/netdriver.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stddef.h>
#include <minix/com.h>
#include <minix/ds.h>
#include <minix/keymap.h>
#include <minix/syslib.h>
#include <minix/type.h>
#include <minix/sysutil.h>
#include <minix/endpoint.h>
#include <timers.h>
#include <net/hton.h>
#include <net/gen/ether.h>
#include <net/gen/eth_io.h>
#include <machine/pci.h>

#include <sys/types.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/ioc_memory.h>
#include <sys/mman.h>

#include "tg3.h"

#define DRV_MODULE_NAME		"tg3"
#define DRV_MODULE_VERSION	"3.99"
#define DRV_MODULE_RELDATE	"April 20, 2009"

#define TG3_DEF_MAC_MODE	0
#define TG3_DEF_RX_MODE		0
#define TG3_DEF_TX_MODE		0

/* These numbers seem to be hard coded in the NIC firmware somehow.
 * You can't change the ring sizes, but you can change where you place
 * them in the NIC onboard memory.
 */
#define TG3_RX_RING_SIZE		512
#define TG3_DEF_RX_RING_PENDING		200
#define TG3_RX_JUMBO_RING_SIZE		256
#define TG3_DEF_RX_JUMBO_RING_PENDING	100

/* Do not place this n-ring entries value into the tp struct itself,
 * we really want to expose these constants to GCC so that modulo et
 * al.  operations are done with shifts and masks instead of with
 * hw multiply/modulo instructions.  Another solution would be to
 * replace things like '% foo' with '& (foo - 1)'.
 */
#define TG3_RX_RCB_RING_SIZE(tp)	\
	((tp->tg3_flags2 & TG3_FLG2_5705_PLUS) ?  512 : 1024)

#define TG3_TX_RING_SIZE		512
#define TG3_DEF_TX_RING_PENDING		(TG3_TX_RING_SIZE - 1)

#define TG3_RX_RING_BYTES	(sizeof(struct tg3_rx_buffer_desc) * \
				 TG3_RX_RING_SIZE)
#define TG3_RX_JUMBO_RING_BYTES	(sizeof(struct tg3_rx_buffer_desc) * \
			         TG3_RX_JUMBO_RING_SIZE)
#define TG3_RX_RCB_RING_BYTES(tp) (sizeof(struct tg3_rx_buffer_desc) * \
			           TG3_RX_RCB_RING_SIZE(tp))
#define TG3_TX_RING_BYTES	(sizeof(struct tg3_tx_buffer_desc) * \
				 TG3_TX_RING_SIZE)
#define NEXT_TX(N)		(((N) + 1) & (TG3_TX_RING_SIZE - 1))

#define RX_PKT_BUF_SZ		(1536 + tp->rx_offset + 64)
#define RX_JUMBO_PKT_BUF_SZ	(9046 + tp->rx_offset + 64)

#define FIRMWARE_TG3		"tigon/tg3.bin"
#define FIRMWARE_TG3TSO		"tigon/tg3_tso.bin"
#define FIRMWARE_TG3TSO5	"tigon/tg3_tso5.bin"

PRIVATE char version[] =
DRV_MODULE_NAME ".c:v" DRV_MODULE_VERSION " (" DRV_MODULE_RELDATE ")\n";

#define swab32(x) \
         ((unsigned int)( \
                 (((unsigned int)(x) & (unsigned int)0x000000ffUL) << 24) | \
                 (((unsigned int)(x) & (unsigned int)0x0000ff00UL) <<  8) | \
                 (((unsigned int)(x) & (unsigned int)0x00ff0000UL) >>  8) | \
                 (((unsigned int)(x) & (unsigned int)0xff000000UL) >> 24) ))


#define swab16(x) \
         ((unsigned short)( \
                 (((unsigned short)(x) & (unsigned short)0x00ffU) << 8) | \
                 (((unsigned short)(x) & (unsigned short)0xff00U) >> 8) ))

#define be32_to_cpu(A) ((((u32_t)(A) & 0xff000000) >> 24) | \
                    	(((u32_t)(A) & 0x00ff0000) >> 8)  | \
                    	(((u32_t)(A) & 0x0000ff00) << 8)  | \
                    	(((u32_t)(A) & 0x000000ff) << 24))

#define cpu_to_be32(x) be32_to_cpu(x)
#define cpu_to_le32(x) x

#define tw32_mailbox(reg, val)	tp->write32_mbox(tp, reg, val)
#define tw32_mailbox_f(reg, val)	tw32_mailbox_flush(tp, (reg), (val))
#define tw32_rx_mbox(reg, val)	tp->write32_rx_mbox(tp, reg, val)
#define tw32_tx_mbox(reg, val)	tp->write32_tx_mbox(tp, reg, val)
#define tr32_mailbox(reg)	tp->read32_mbox(tp, reg)

#define tw32(reg,val)		tp->write32(tp, reg, val)
#define tw32_f(reg,val)		_tw32_flush(tp,(reg),(val), 0)
#define tw32_wait_f(reg,val,us)	_tw32_flush(tp,(reg),(val), (us))
#define tr32(reg)		tp->read32(tp, reg)

#define tg3_mdio_stop(tp)
#define tg3_mdio_fini(tp)
#define tg3_phy_init(tp)  0
#define tg3_phy_start(tp)
#define tg3_phy_stop(tp)
#define tg3_phy_fini(tp)


#define TG3_ENVVAR	"TG3ETH"

PRIVATE struct pcitab {
	u16_t vid;
	u16_t did;
	int checkclass;
} pcitab[] = {

	{ 0x14e4, 0x1644, 0 },	/* BCM5700 */
	{ 0x14e4, 0x1600, 0 },	/* BCM5752 */

	{ 0x0000, 0x0000, 0 }
};

PRIVATE tg3_t tg3_state;
PRIVATE int tg3_instance;
PRIVATE u32_t system_hz;
EXTERN int env_argc;
EXTERN char **env_argv;

_PROTOTYPE(PRIVATE int tg3_close, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_init_one, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_open, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_poll, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_rx, (message * mp, tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_set_mac_addr, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_start_transmit, (message * mp, tg3_t * tp));
_PROTOTYPE(PRIVATE iovec_t * alloc_iovec, (int iovec_size, phys_bytes * p));
_PROTOTYPE(PRIVATE char *tg3_bus_string, (tg3_t * tp, char *str));
_PROTOTYPE(PRIVATE char *tg3_phy_string, (tg3_t * tp));
_PROTOTYPE(PRIVATE int carrier_ok, (tg3_t * tp));
_PROTOTYPE(PRIVATE int fiber_autoneg, (tg3_t * tp, u32_t * txflags, 
			u32_t * rxflags));
_PROTOTYPE(PRIVATE int is_multicast_ether_addr, (const u8_t * addr));
_PROTOTYPE(PRIVATE int is_valid_ether_addr, (const u8_t * addr));
_PROTOTYPE(PRIVATE int is_zero_ether_addr, (const u8_t * addr));
_PROTOTYPE(PRIVATE int pci_find_cap, (int devind, int cap, int *addr));
_PROTOTYPE(PRIVATE int sef_cb_init_fresh, (int type, sef_init_info_t * info));
_PROTOTYPE(PRIVATE int tg3_5700_link_polarity, (tg3_t * tp, u32_t speed));
_PROTOTYPE(PRIVATE int tg3_abort_hw, (tg3_t * tp, int silent));
_PROTOTYPE(PRIVATE int tg3_adv_1000T_flowctrl_ok, (tg3_t * tp, u32_t * lcladv,
			u32_t * rmtadv));
_PROTOTYPE(PRIVATE int tg3_alloc_consistent, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_alloc_rx_iovec, (tg3_t * tp, u32_t opaque_key,
			int src_idx, u32_t dest_idx_unmasked));
_PROTOTYPE(PRIVATE int tg3_ape_lock, (tg3_t * tp, int locknum));
_PROTOTYPE(PRIVATE int tg3_bmcr_reset, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_chip_reset, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_copper_is_advertising_all, (tg3_t * tp, u32_t mask));
_PROTOTYPE(PRIVATE int tg3_do_mem_test, (tg3_t * tp, u32_t offset, u32_t len));
_PROTOTYPE(PRIVATE int tg3_do_test_dma, (tg3_t * tp, u32_t * buf,
			vir_bytes buf_dma, int size, int to_device));
_PROTOTYPE(PRIVATE int tg3_enabled, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_fiber_aneg_smachine, (tg3_t * tp,
			struct tg3_fiber_aneginfo * ap));
_PROTOTYPE(PRIVATE int tg3_fw_img_is_valid, (tg3_t * tp, u32_t offset));
_PROTOTYPE(PRIVATE int tg3_get_device_address, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_get_invariants, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_halt_cpu, (tg3_t * tp, u32_t offset));
_PROTOTYPE(PRIVATE int tg3_halt, (tg3_t * tp, int kind, int silent));
_PROTOTYPE(PRIVATE int tg3_init_5401phy_dsp, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_init_hw, (tg3_t * tp, int reset_phy));
_PROTOTYPE(PRIVATE int tg3_init_rings, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_irq_sync, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_issue_otp_command, (tg3_t * tp, u32_t cmd));
_PROTOTYPE(PRIVATE int tg3_load_5701_a0_firmware_fix, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_load_tso_firmware, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_mdio_init, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_nvram_exec_cmd, (tg3_t * tp, u32_t nvram_cmd));
_PROTOTYPE(PRIVATE int tg3_nvram_lock, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_nvram_read_be32, (tg3_t * tp, u32_t offset,
			u32_t * val));
_PROTOTYPE(PRIVATE int tg3_nvram_read, (tg3_t * tp, u32_t offset, u32_t * val));
_PROTOTYPE(PRIVATE int tg3_nvram_read_using_eeprom, (tg3_t * tp, u32_t offset,
			u32_t * val));
_PROTOTYPE(PRIVATE int tg3_phy_probe, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_phy_reset_5703_4_5, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_phy_reset_chanpat, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_phy_reset, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_phy_write_and_check_testpat, (tg3_t * tp,
			int *resetp));
_PROTOTYPE(PRIVATE int tg3_poll_fw, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_poll_work, (tg3_t * tp, int work_done));
_PROTOTYPE(PRIVATE int tg3_probe, (tg3_t * db, int skip));
_PROTOTYPE(PRIVATE int tg3_readphy, (tg3_t * tp, int reg, u32_t * val));
_PROTOTYPE(PRIVATE int tg3_request_irq, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_reset_hw, (tg3_t * tp, int reset_phy));
_PROTOTYPE(PRIVATE int tg3_restart_hw, (tg3_t * tp, int reset_phy));
_PROTOTYPE(PRIVATE int tg3_run_loopback, (tg3_t * tp, int loopback_mode));
_PROTOTYPE(PRIVATE int tg3_set_power_state, (tg3_t * tp, unsigned int state));
_PROTOTYPE(PRIVATE int tg3_setup_copper_phy, (tg3_t * tp, int force_reset));
_PROTOTYPE(PRIVATE int tg3_setup_fiber_by_hand, (tg3_t * tp, u32_t mac_status));
_PROTOTYPE(PRIVATE int tg3_setup_fiber_hw_autoneg, (tg3_t * tp,
			u32_t mac_status));
_PROTOTYPE(PRIVATE int tg3_setup_fiber_mii_phy, (tg3_t * tp, int force_reset));
_PROTOTYPE(PRIVATE int tg3_setup_fiber_phy, (tg3_t * tp, int force_reset));
_PROTOTYPE(PRIVATE int tg3_setup_phy, (tg3_t * tp, int force_reset));
_PROTOTYPE(PRIVATE int tg3_stop_block, (tg3_t * tp, unsigned long ofs,
			u32_t enable_bit, int silent));
_PROTOTYPE(PRIVATE int tg3_test_dma, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_test_interrupt, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_test_link, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_test_loopback, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_test_memory, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_test_nvram, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_test_registers, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_wait_macro_done, (tg3_t * tp));
_PROTOTYPE(PRIVATE int tg3_writephy, (tg3_t * tp, int reg, u32_t val));
_PROTOTYPE(PRIVATE struct subsys_tbl_ent * lookup_by_subsys, (tg3_t * tp));
_PROTOTYPE(PRIVATE u16_t tg3_advert_flowctrl_1000T, (u8_t flow_ctrl));
_PROTOTYPE(PRIVATE u16_t tg3_advert_flowctrl_1000X, (u8_t flow_ctrl));
_PROTOTYPE(PRIVATE u32_t calc_crc, (unsigned char *buf, int len));
_PROTOTYPE(PRIVATE u32_t readl, (u8_t * off));
_PROTOTYPE(PRIVATE u32_t tg3_ape_read32, (tg3_t * tp, u32_t off));
_PROTOTYPE(PRIVATE u32_t tg3_nvram_logical_addr, (tg3_t * tp, u32_t addr));
_PROTOTYPE(PRIVATE u32_t tg3_nvram_phys_addr, (tg3_t * tp, u32_t addr));
_PROTOTYPE(PRIVATE u32_t tg3_read32_mbox_5906, (tg3_t * tp, u32_t off));
_PROTOTYPE(PRIVATE u32_t tg3_read32, (tg3_t * tp, u32_t off));
_PROTOTYPE(PRIVATE u32_t tg3_read_indirect_mbox, (tg3_t * tp, u32_t off));
_PROTOTYPE(PRIVATE u32_t tg3_read_indirect_reg32, (tg3_t * tp, u32_t off));
_PROTOTYPE(PRIVATE u32_t tg3_read_otp_phycfg, (tg3_t * tp));
_PROTOTYPE(PRIVATE u8_t mii_resolve_flowctrl_fdx, (u16_t lcladv, u16_t rmtadv));
_PROTOTYPE(PRIVATE u8_t tg3_resolve_flowctrl_1000X, (u16_t lcladv,
			u16_t rmtadv));
_PROTOTYPE(PRIVATE unsigned int hweight8, (unsigned int w));
_PROTOTYPE(PRIVATE unsigned int tg3_has_work, (tg3_t * tp));
_PROTOTYPE(PRIVATE void carrier_off, (tg3_t * tp));
_PROTOTYPE(PRIVATE void carrier_on, (tg3_t * tp));
_PROTOTYPE(PRIVATE void do_hard_int, (void));
_PROTOTYPE(PRIVATE void mess_reply, (message * req, message * reply_mess));
_PROTOTYPE(PRIVATE void pcie_set_readrq, (int devind, int rq));
_PROTOTYPE(PRIVATE void sef_local_startup, (void));
_PROTOTYPE(PRIVATE void tg3_ape_driver_state_change, (tg3_t * tp, int kind));
_PROTOTYPE(PRIVATE void tg3_ape_lock_init, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_ape_send_event, (tg3_t * tp, u32_t event));
_PROTOTYPE(PRIVATE void tg3_ape_unlock, (tg3_t * tp, int locknum));
_PROTOTYPE(PRIVATE void tg3_ape_write32, (tg3_t * tp, u32_t off, u32_t val));
_PROTOTYPE(PRIVATE void tg3_aux_stat_to_speed_duplex, (tg3_t * tp, u32_t val,
			u16_t * speed, u8_t * duplex));
_PROTOTYPE(PRIVATE void tg3_cond_int, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_confaddr, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_conf_hw, (tg3_t * db));
_PROTOTYPE(PRIVATE void tg3_disable_ints, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_disable_nvram_access, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_dump_flags, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_dump, (message * m));
_PROTOTYPE(PRIVATE void tg3_dump_short_state, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_enable_ints, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_enable_nvram_access, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_free_consistent, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_full_lock, (tg3_t * tp, int irq_sync));
_PROTOTYPE(PRIVATE void tg3_full_unlock, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_generate_fw_event, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_get_5752_nvram_info, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_get_5755_nvram_info, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_get_5761_nvram_info, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_get_57780_nvram_info, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_get_5787_nvram_info, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_get_5906_nvram_info, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_get_eeprom_hw_cfg, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_get_eeprom_size, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_get_nvram_info, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_get_nvram_size, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_getstat_s, (message * mp));
_PROTOTYPE(PRIVATE void tg3_init_bcm8002, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_init_bufmgr_config, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_init_coal, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_init_hw_and_addr, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_init_link_config, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_init, (message * mp));
_PROTOTYPE(PRIVATE void tg3_irq_quiesce, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_link_report, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_mdio_start, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_nvram_init, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_nvram_unlock, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_pci_conf, (void));
_PROTOTYPE(PRIVATE void tg3_periodic_fetch_stats, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_phy_apply_otp, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_phy_copper_begin, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_phydsp_write, (tg3_t * tp, u32_t reg, u32_t val));
_PROTOTYPE(PRIVATE void tg3_phy_set_wirespeed, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_phy_toggle_apd, (tg3_t * tp, int enable));
_PROTOTYPE(PRIVATE void tg3_phy_toggle_automdix, (tg3_t * tp, int enable));
_PROTOTYPE(PRIVATE void tg3_read_bc_ver, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_read_dash_ver, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_read_fw_ver, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_read_hwsb_ver, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_read_mem, (tg3_t * tp, u32_t off, u32_t * val));
_PROTOTYPE(PRIVATE void tg3_read_mgmtfw_ver, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_read_partno, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_read_sb_ver, (tg3_t * tp, u32_t val));
_PROTOTYPE(PRIVATE void tg3_readv_s, (message * mp, int from_int));
_PROTOTYPE(PRIVATE void tg3_restart_ints, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_restore_pci_state, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_save_pci_state, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_serdes_parallel_detect, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_set_bdinfo, (tg3_t * tp, u32_t bdinfo_addr,
			vir_bytes mapping, u32_t maxlen_flags, u32_t nic_addr));
_PROTOTYPE(PRIVATE void __tg3_set_coalesce, (tg3_t * tp, struct coalesce * ec));
_PROTOTYPE(PRIVATE void __tg3_set_mac_addr, (tg3_t * tp, int skip_mac_1));
_PROTOTYPE(PRIVATE void tg3_set_multi, (tg3_t * tp, unsigned int accept_all));
_PROTOTYPE(PRIVATE void __tg3_set_rx_mode, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_setup_flow_control, (tg3_t * tp, u32_t lcladv,
			u32_t rmtadv));
_PROTOTYPE(PRIVATE void tg3_start, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_stop_fw, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_stop, (void));
_PROTOTYPE(PRIVATE void tg3_switch_clocks, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_tx_recover, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_tx, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_ump_link_report, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_wait_for_event_ack, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_write32_mbox_5906, (tg3_t * tp, u32_t off,
			u32_t val));
_PROTOTYPE(PRIVATE void tg3_write32, (tg3_t * tp, u32_t off, u32_t val));
_PROTOTYPE(PRIVATE void tg3_write32_tx_mbox, (tg3_t * tp, u32_t off,
			u32_t val));
_PROTOTYPE(PRIVATE void tg3_write_flush_reg32, (tg3_t * tp, u32_t off,
			u32_t val));
_PROTOTYPE(PRIVATE void tg3_write_indirect_mbox, (tg3_t * tp, u32_t off,
			u32_t val));
_PROTOTYPE(PRIVATE void tg3_write_indirect_reg32, (tg3_t * tp, u32_t off,
			u32_t val));
_PROTOTYPE(PRIVATE void tg3_write_mem, (tg3_t * tp, u32_t off, u32_t val));
_PROTOTYPE(PRIVATE void tg3_write_sig_legacy, (tg3_t * tp, int kind));
_PROTOTYPE(PRIVATE void tg3_write_sig_post_reset, (tg3_t * tp, int kind));
_PROTOTYPE(PRIVATE void tg3_write_sig_pre_reset, (tg3_t * tp, int kind));
_PROTOTYPE(PRIVATE void tg3_writev_s, (message * mp, int from_int));
_PROTOTYPE(PRIVATE void _tw32_flush, (tg3_t * tp, u32_t off, u32_t val,
			u32_t usec_wait));
_PROTOTYPE(PRIVATE void tw32_mailbox_flush, (tg3_t * tp, u32_t off, u32_t val));
_PROTOTYPE(PRIVATE void writel, (u32_t val, u8_t * off));
_PROTOTYPE(PRIVATE u32_t tg3_interrupt_tagged, (tg3_t * tp));
_PROTOTYPE(PRIVATE u32_t tg3_interrupt, (tg3_t * tp));
_PROTOTYPE(PRIVATE u32_t tg3_tx_avail, (tg3_t * tp));
_PROTOTYPE(PRIVATE unsigned int tg3_has_rx_work, (tg3_t * tp));
_PROTOTYPE(PRIVATE void upload_packet, (tg3_t * tp, message * mp,
			iovec_t * iovec, int len));
_PROTOTYPE(PRIVATE void tg3_dump_state, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_recycle_rx, (tg3_t * tp, u32_t opaque_key,
			int src_idx, u32_t dest_idx_unmasked));
_PROTOTYPE(PRIVATE void tg3_remove_one, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_reset_task, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_self_test, (tg3_t * tp));
_PROTOTYPE(PRIVATE void tg3_set_txd, (tg3_t * tp, int entry, vir_bytes mapping,
			int len, u32_t flags, u32_t mss_and_is_end));
_PROTOTYPE(PRIVATE void tg3_timer, (tg3_t * tp));


/* SEF functions and variables. */
_PROTOTYPE(PRIVATE void sef_local_startup, (void));
_PROTOTYPE(PRIVATE int sef_cb_init_fresh, (int type, sef_init_info_t * info));

/*===========================================================================*
 *				main					     *
 *===========================================================================*/
int main(int argc, char *argv[])
{
	message m;
	int r;
	int ipc_status;

	/* SEF local startup. */
	env_setargs(argc, argv);
	sef_local_startup();

	while (TRUE) {
		if ((r = netdriver_receive(ANY, &m, &ipc_status)) != OK)
			panic("netdriver_receive failed: %d", r);

		if (is_ipc_notify(ipc_status)) {
			switch (_ENDPOINT_P(m.m_source)) {
			case CLOCK:
				/* Under MINIX, synchronous alarms are used
				 * instead of watchdog functions. The approach
				 * is very different: MINIX VMD timeouts are
				 * handled within the kernel (the watchdog is
				 * executed by CLOCK), and notify() the driver
				 * in some cases.  MINIX timeouts result in a
				 * SYN_ALARM message to the driver and thus are
				 * handled where they should be handled.
				 * Locally, watchdog functions are used again.*/
				tg3_timer(&tg3_state);
				break;
			case HARDWARE:
				do_hard_int();
				break;
			case TTY_PROC_NR:
				tg3_dump(&m);
				break;
			case PM_PROC_NR:
				{
					break;
				}

			default:
				panic("illegal notify from: %d",
				      m.m_source);
			}

			/* done, get new message */
			continue;
		}
		switch (m.m_type) {
		case DL_WRITEV_S:
			tg3_writev_s(&m, FALSE);
			break;
		case DL_READV_S:
			tg3_readv_s(&m, FALSE);
			break;
		case DL_CONF:
			tg3_init(&m);
			break;
		case DL_GETSTAT_S:
			tg3_getstat_s(&m);
			break;
		default:
			panic("illegal message: %d", m.m_type);
		}
	}
}

/*===========================================================================*
 *			      sef_local_startup				     *
 *===========================================================================*/
PRIVATE void sef_local_startup()
{
	/* Register init callbacks. */
	sef_setcb_init_fresh(sef_cb_init_fresh);
	sef_setcb_init_restart(sef_cb_init_fresh);

	/* Let SEF perform startup. */
	sef_startup();
}

/*===========================================================================*
 *		       	   sef_cb_init_fresh   	                             *
 *===========================================================================*/
PRIVATE int sef_cb_init_fresh(int type, sef_init_info_t * info)
{
	long v;
	int r, fkeys, sfkeys;
	tg3_t *tp;

	system_hz = sys_hz();

	v = 0;
	(void) env_parse("instance", "d", 0, &v, 0, 255);
	tg3_instance = (int) v;

	/* Observe some function key for debug dumps. */
	fkeys = sfkeys = 0;
	bit_set(sfkeys, 10);
	if ((r = fkey_map(&fkeys, &sfkeys)) != OK)
		printf("Warning: TG3 couldn't observe Shift+F10 key: %d\n", r);

	tp = &tg3_state;
	tp->flags = TG3_EMPTY;
	tp->carrier = 1;

	/* Announce we are up! */
	netdriver_announce();

	return (OK);
}

/*===========================================================================*
 *				tg3_stop				     *
 *===========================================================================*/
PRIVATE void tg3_stop()
{
	tg3_t *db = &tg3_state;

	if (db->flags & TG3_ENABLED) {
		tg3_close(db);
		tg3_remove_one(db);
	}
	printf("TG3: Driver closing down cleanly\n");
	exit(0);
}

/*===========================================================================*
 *				tg3_dump				     *
 *===========================================================================*/
PRIVATE void tg3_dump(message * m)
{
	tg3_t *db = &tg3_state;

	if (!(db->flags & TG3_ENABLED)) {
		printf("TG3: instance %d is disabled\n", tg3_instance);
		return;
	}
	tg3_dump_state(db);
}


/*===========================================================================*
 *				do_init					     *
 *===========================================================================*/
PRIVATE void tg3_init(message * mp)
{
	static int first_time = 1;

	tg3_t *db = &tg3_state;
	message reply_mess;

	if (first_time) {
		first_time = 0;
		tg3_pci_conf();	/* Configure PCI devices. */

		/* Use a synchronous alarm instead of a watchdog timer. */
		sys_setalarm(system_hz, 0);
	}
	if (!(db->flags & TG3_ENABLED)) {
		/* This is the default, try to (re)locate the device. */
		tg3_conf_hw(db);
		if (!(db->flags & TG3_ENABLED)) {
			/* Probe failed, or the device is configured off. */
			reply_mess.m_type = DL_CONF_REPLY;
			reply_mess.m3_i1 = ENXIO;
			mess_reply(mp, &reply_mess);
			return;
		}
		if (db->flags & TG3_ENABLED)
			tg3_init_hw_and_addr(db);


	}
	assert(db->flags & TG3_ENABLED);

	db->flags &= ~(TG3_PROMISC | TG3_MULTI | TG3_BROAD);

	if (mp->DL_MODE & DL_PROMISC_REQ)
		db->flags |= TG3_PROMISC;
	if (mp->DL_MODE & DL_MULTI_REQ)
		db->flags |= TG3_MULTI;
	if (mp->DL_MODE & DL_BROAD_REQ)
		db->flags |= TG3_BROAD;


	reply_mess.m_type = DL_CONF_REPLY;
	reply_mess.DL_STAT = OK;
	*(ether_addr_t *) reply_mess.DL_HWADDR = (ether_addr_t) db->mac_address;

	mess_reply(mp, &reply_mess);
}


/*===========================================================================*
 *				tg3_pci_conf				     *
 *===========================================================================*/
PRIVATE void tg3_pci_conf()
{
	tg3_t *db;
	static char envvar[] = TG3_ENVVAR "#";
	static char envfmt[] = "*:d.d.d";
	static char val[128];
	long v;

	db = &tg3_state;

	strcpy(db->name, "tg3#0");
	db->name[4] += tg3_instance;
	db->pci_seen = FALSE;
	envvar[sizeof(TG3_ENVVAR) - 1] = '0' + tg3_instance;
	if (0 == env_get_param(envvar, val, sizeof(val)) &&
	    !env_prefix(envvar, "pci")) {
		env_panic(envvar);
	}
	v = 0;
	(void) env_parse(envvar, envfmt, 1, &v, 0, 255);
	db->pci_bus = v;
	v = 0;
	(void) env_parse(envvar, envfmt, 2, &v, 0, 255);
	db->pci_dev = v;
	v = 0;
	(void) env_parse(envvar, envfmt, 3, &v, 0, 255);
	db->pci_func = v;

	pci_init();

	if (tg3_probe(db, tg3_instance))
		db->pci_seen = TRUE;

}


/*===========================================================================*
 *				tg3_probe				     *
 *===========================================================================*/
PRIVATE int tg3_probe(tg3_t * db, int skip)
{
	int i, r, devind, just_one;
	u16_t vid, did;
	u32_t bar;
	u8_t ilr;
	char *dname;

	if ((db->pci_bus | db->pci_dev | db->pci_func) != 0) {
		/* Look for specific PCI device */
		r = pci_find_dev(db->pci_bus, db->pci_dev,
				 db->pci_func, &devind);
		if (r == 0) {
			printf("%s: no PCI found at %d.%d.%d\n",
			       db->name, db->pci_bus,
			       db->pci_dev, db->pci_func);
			return 0;
		}
		pci_ids(devind, &vid, &did);
		just_one = TRUE;
	} else {
		r = pci_first_dev(&devind, &vid, &did);
		if (r == 0)
			return 0;
		just_one = FALSE;
	}

	for (;;) {
		for (i = 0; pcitab[i].vid != 0; i++) {
			if (pcitab[i].vid != vid)
				continue;
			if (pcitab[i].did != did)
				continue;
			if (pcitab[i].checkclass) {
				panic("class check not implemented");
			}
			break;
		}
		if (pcitab[i].vid != 0) {
			if (just_one || !skip)
				break;
			skip--;
		}
		if (just_one) {
			printf(
			"%s: wrong PCI device (%04x/%04x) found at %d.%d.%d\n",
			       db->name, vid, did,
			       db->pci_bus,
			       db->pci_dev, db->pci_func);
			return 0;
		}
		r = pci_next_dev(&devind, &vid, &did);
		if (!r)
			return 0;
	}

	dname = pci_dev_name(vid, did);
	if (!dname)
		dname = "unknown device";
	printf("%s: ", db->name);
	printf("%s (%x/%x) at %s\n", dname, vid, did, pci_slot_name(devind));

	pci_reserve(devind);

	bar = pci_attr_r32(devind, PCI_BAR) & 0xffffffe0;
	if (bar < 0x400) {
		panic("base address is not properly configured");
	}
	db->bar = bar;

	ilr = pci_attr_r8(devind, PCI_ILR);
	db->irq = ilr;

	db->devind = devind;

	printf("%s: using I/O address 0x%lx, IRQ %d\n",
	       db->name, (unsigned long) bar, ilr);

	return TRUE;
}

/*===========================================================================*
 *			tg3_conf_hw					     *
 *===========================================================================*/
PRIVATE void tg3_conf_hw(tg3_t * db)
{
	static eth_stat_t empty_stat = {0, 0, 0, 0, 0, 0 /* ,... */ };

	if (db->pci_seen) {
		/* PCI device is present */
		db->flags |= TG3_ENABLED;
	}
	if (!(db->flags & TG3_ENABLED))
		return;

	db->stat = empty_stat;
}

/*===========================================================================*
 *			tg3_init_hw_and_addr				     *
 *===========================================================================*/
PRIVATE void tg3_init_hw_and_addr(tg3_t * tp)
{
	int s, i;

	tp->flags |= TG3_ENABLED;

	/* Set the interrupt handler. The policy is to only send HARD_INT
	 * notifications. Don't reenable interrupts automatically. The id that
	 * is passed back is the interrupt line number. */

	tp->hook_id = tp->irq;
	if ((s = sys_irqsetpolicy(tp->irq, 0, &tp->hook_id)) != OK)
		printf("TG3: error, couldn't set IRQ policy: %d\n", s);

	tg3_init_one(tp);
	tg3_open(tp);

	if ((s = sys_irqenable(&tp->hook_id)) != OK)
		printf("TG3: error, couldn't enable interrupts: %d\n", s);

	tg3_confaddr(tp);
	printf("%s: Ethernet address ", tp->name);
	for (i = 0; i < 6; i++) {
		printf("%x%c", tp->mac_address.ea_addr[i], i < 5 ? ':' : '\n');
	}
}

/*===========================================================================*
 *				tg3_confaddr				     *
 *===========================================================================*/
PRIVATE void tg3_confaddr(tg3_t * tp)
{
	static char eakey[] = TG3_ENVVAR "#_EA";
	static char eafmt[] = "x:x:x:x:x:x";

	int i;
	long v;

	/* User defined ethernet address? */
	eakey[sizeof(TG3_ENVVAR) - 1] = '0' + tg3_instance;

	for (i = 0; i < 6; i++) {
		if (env_parse(eakey, eafmt, i, &v, 0x00L, 0xFFL) != EP_SET)
			break;
		tp->mac_address.ea_addr[i] = v;
	}

	if (i != 0 && i != 6)
		env_panic(eakey);	/* It's all or nothing */

	/* update ethernet address in hardware */
	if (i == 6)
		tg3_set_mac_addr(tp);


}


/*===========================================================================*
 *			tg3_readv_s					     *
 *===========================================================================*/
PRIVATE void tg3_readv_s(message * mp, int from_int)
{
	int r;
	tg3_t *tp;
	message reply;

	tp = &tg3_state;

	assert(tp->flags & TG3_ENABLED);

	reply.m_type = DL_TASK_REPLY;
	reply.DL_FLAGS = DL_NOFLAGS;
	reply.DL_COUNT = 0;

	if (!from_int) {
		tp->rx_mess = *mp;
		tp->flags |= TG3_GOTREADV;
	}
	if ((tp->flags & TG3_GOTREADV) && tg3_has_rx_work(tp)) {

		int bytes = tg3_rx(mp, tp);

		tp->flags ^= TG3_GOTREADV;
		reply.DL_FLAGS = DL_PACK_RECV;
		reply.DL_COUNT = bytes;
	}
	r = send(mp->m_source, &reply);

	if (r < 0) {
		printf("TG3: tried sending to %d, type %d\n", 
					mp->m_source, reply.m_type);
		panic("TG3", "send failed:", r);
	}
}


/*===========================================================================*
 *			tg3_writev_s					     *
 *===========================================================================*/
PRIVATE void tg3_writev_s(message * mp, int from_int)
{
	int r;
	tg3_t *tp;
	message reply;

	tp = &tg3_state;

	assert(tp->flags & TG3_ENABLED);

	reply.m_type = DL_TASK_REPLY;
	reply.DL_COUNT = 0;
	reply.DL_FLAGS = DL_NOFLAGS;

	if (!from_int) {
		tp->tx_mess = *mp;
		tp->flags |= TG3_GOTWRITEV;
	}
	if ((tp->flags & TG3_GOTWRITEV) && tg3_tx_avail(tp)) {
		tg3_start_transmit(mp, tp);

		tp->flags ^= TG3_GOTWRITEV;
		reply.DL_FLAGS = DL_PACK_SEND;
	}
	r = send(mp->m_source, &reply);

	if (r < 0) {
		printf("TG3 tried sending to %d, type %d\n", 
					mp->m_source, reply.m_type);
		panic("TG3", "send failed:", r);
	}
}

/*===========================================================================*
 *			tg3_getstat_s					     *
 *===========================================================================*/
PRIVATE void tg3_getstat_s(message * mp)
{
	int r;
	eth_stat_t stats;
	tg3_t *tp;

	tp = &tg3_state;

	assert(tp->flags & TG3_ENABLED);

	stats = tp->stat;

	r = sys_safecopyto(mp->m_source, mp->DL_GRANT, 0,
			   (vir_bytes) & stats, sizeof(stats), D);
	if (r != OK)
		panic("tg3", "tg3_getstat_s: sys_safecopyto failed", r);

	mp->m_type = DL_STAT_REPLY;
	mp->DL_STAT = OK;
	r = send(mp->m_source, mp);
	if (r != OK)
		panic("TG3", "tg3_getstat_s: send failed: %d\n", r);
}

/*===========================================================================*
 *			mess_reply					     *
 *===========================================================================*/
PRIVATE void mess_reply(message * req, message * reply_mess)
{
	if (send(req->m_source, reply_mess) != OK)
		panic("unable to mess_reply");
}

/*===========================================================================*
 *			do_hard_int					     *
 *===========================================================================*/
PRIVATE void do_hard_int(void)
{
	int s, r;
	tg3_t *tp = &tg3_state;


	/* Run interrupt handler at driver level. */

	r = tp->irq_handler(tp);

	if (tg3_has_rx_work(tp) == 1) {
		tg3_readv_s(&tp->rx_mess, TRUE);
	}
	/* Write pending and space available */
	if ((tp->flags & TG3_GOTWRITEV) && tg3_tx_avail(tp)) {
		tg3_writev_s(&tp->tx_mess, TRUE);
	}
	if ((r == 1))
		tg3_poll(tp);

	/* Reenable interrupts for this hook. */
	if ((s = sys_irqenable(&tp->hook_id)) != OK)
		printf("TG3: error, couldn't enable interrupts: %d\n",
		       s);
}

PRIVATE int tg3_start_transmit(message * mp, struct tg3 * tp)
{
	int r, i, size, offset;
	iovec_s_t vecs[NR_IOREQS];
	cp_grant_id_t grant;

	int count = mp->DL_COUNT;
	u32_t entry = tp->tx_prod;
	struct tx_ring_info *ri = &tp->tx_buffers[entry];
	vir_bytes buf = ri->iovec.iov_addr;

	r = sys_safecopyfrom(mp->m_source,
			     mp->DL_GRANT,
			   0, (vir_bytes) vecs, count * sizeof(iovec_s_t), D);
	if (r != OK)
		panic("tg3", "tg3_writev_s: sys_safecopyfrom failed", r);

	offset = 0;

	for (i = 0; i < count; i++) {
		grant = vecs[i].iov_grant;
		size = vecs[i].iov_size;

		if ((offset + size) > ETH_MAX_PACK_SIZE_TAGGED)
			panic("tg3",
			"tg3_writev_s: packet size > ETH_MAX_PACK_SIZE_TAGGED",
			      offset + size);

		r = sys_safecopyfrom(mp->m_source,
				     grant,
				     0, (vir_bytes) (buf + offset), size, D);
		if (r != OK) {
			printf("client %d\n\
				grant %d\n\
				buf+offset %x\n\
				size\n", 
				mp->m_source, grant, buf + offset, size);
			panic("tg3",
			      "tg3_writev_s: sys_safecopyto failed", r);
		}
		offset += size;
	}
	ri->iovec.iov_size = offset;
	ri->in_use = 1;
	tg3_set_txd(tp, entry, ri->mapping, offset, 0, 1);

	entry = NEXT_TX(entry);

	/* Packets are ready, update Tx producer idx local and on card. */
	tw32_tx_mbox((MAILBOX_SNDHOST_PROD_IDX_0 + TG3_64BIT_REG_LOW), entry);

	tp->tx_prod = entry;

	return 1;
}

PRIVATE iovec_t *alloc_iovec(int iovec_size, phys_bytes * p)
{
	phys_bytes dummy;

	iovec_t *r = alloc_contig(sizeof(iovec_t), 0, &dummy);
	assert(r != 0);

	r->iov_addr = (phys_bytes) alloc_contig(iovec_size, 0, p);
	assert(r->iov_addr != 0);

	r->iov_size = 0;

	return r;
}

PRIVATE void upload_packet(tg3_t * tp, message * mp, iovec_t * iovec, int len)
{
	int r, offset, remaining, i, size;
	iovec_s_t vecs[NR_IOREQS];
	cp_grant_id_t grant;

	r = sys_safecopyfrom(mp->m_source,
			     mp->DL_GRANT,
			     0,
			     (vir_bytes) vecs,
			     mp->DL_COUNT * sizeof(iovec_s_t), D);
	if (r != OK) {
		printf("Client was %d\nGrant was %d\nCount was %d\n", 
				mp->m_source, mp->DL_GRANT, mp->DL_COUNT);
		panic("tg3", "tg3_do_write: sys_safecopyto failed", r);

	}
	offset = 0;
	remaining = len;
	i = 0;

	while ((i < mp->DL_COUNT) && (remaining > 0)) {
		grant = vecs[i].iov_grant;
		size = vecs[i].iov_size;

		if ((offset + size) > ETH_MAX_PACK_SIZE_TAGGED)
			panic("tg3",
			"tg3_do_read: packet size > ETH_MAX_PACK_SIZE_TAGGED",
			      offset + size);

		r = sys_safecopyto(mp->m_source,
				   grant,
				   0,
				   (vir_bytes) iovec->iov_addr + offset,
				   size < remaining ? size : remaining, D);
		remaining -= size < remaining ? size : remaining;

		if (r != OK)
			panic("tg3", "tg3_writev_s: sys_safecopyto failed", r);

		offset += size;
		i++;
	}

	if (remaining > 0)
		printf("buffer exhausted. Packet truncated\n");

}



/* The RX ring scheme is composed of multiple rings which post fresh
 * buffers to the chip, and one special ring the chip uses to report
 * status back to the host.
 *
 * The special ring reports the status of received packets to the
 * host.  The chip does not write into the original descriptor the
 * RX buffer was obtained from.  The chip simply takes the original
 * descriptor as provided by the host, updates the status and length
 * field, then writes this into the next status ring entry.
 *
 * Each ring the host uses to post buffers to the chip is described
 * by a TG3_BDINFO entry in the chips SRAM area.  When a packet arrives,
 * it is first placed into the on-chip ram.  When the packet's length
 * is known, it walks down the TG3_BDINFO entries to select the ring.
 * Each TG3_BDINFO specifies a MAXLEN field and the first TG3_BDINFO
 * which is within the range of the new packet's length is chosen.
 *
 * The "separate ring for rx status" scheme may sound queer, but it makes
 * sense from a cache coherency perspective.  If only the host writes
 * to the buffer post rings, and only the chip writes to the rx status
 * rings, then cache lines never move beyond shared-modified state.
 * If both the host and chip were to write into the same ring, cache line
 * eviction could occur since both entities want it in an exclusive state.
 */
PRIVATE int tg3_rx(message * mp, struct tg3 * tp)
{
	u32_t work_mask, rx_std_posted = 0;
	u32_t sw_idx = tp->rx_rcb_ptr;
	u16_t hw_idx;
	int received;
	unsigned int len = 0;
	iovec_t *iovec;
	u32_t opaque_key, desc_idx, *post_ptr;
	struct tg3_rx_buffer_desc *desc;

	hw_idx = tp->hw_status->idx[0].rx_producer;

	work_mask = 0;
	received = 0;

	assert(sw_idx != hw_idx);

	desc = &tp->rx_rcb[sw_idx];

	desc_idx = desc->opaque & RXD_OPAQUE_INDEX_MASK;
	opaque_key = desc->opaque & RXD_OPAQUE_RING_MASK;
	if (opaque_key == RXD_OPAQUE_RING_STD) {

		iovec = tp->rx_std_buffers[desc_idx].iovec;
		post_ptr = &tp->rx_std_ptr;
		rx_std_posted++;
	} else if (opaque_key == RXD_OPAQUE_RING_JUMBO) {
		iovec = tp->rx_jumbo_buffers[desc_idx].iovec;
		post_ptr = &tp->rx_jumbo_ptr;
	} else {
		goto next_pkt_nopost;
	}

	work_mask |= opaque_key;

	if ((desc->err_vlan & RXD_ERR_MASK) != 0 &&
	    (desc->err_vlan != RXD_ERR_ODD_NIBBLE_RCVD_MII)) {

		tg3_recycle_rx(tp, opaque_key, desc_idx, *post_ptr);
		/* Dropping packet */
		goto next_pkt;
	}
	len = ((desc->idx_len & RXD_LEN_MASK) >> RXD_LEN_SHIFT) - ETH_FCS_LEN;

	tg3_recycle_rx(tp, opaque_key, desc_idx, *post_ptr);

	upload_packet(tp, mp, iovec, len);

next_pkt:
	(*post_ptr)++;

	if (rx_std_posted >= tp->rx_std_max_post) {
		u32_t idx = *post_ptr % TG3_RX_RING_SIZE;

		tw32_rx_mbox(MAILBOX_RCV_STD_PROD_IDX + TG3_64BIT_REG_LOW, idx);
		work_mask &= ~RXD_OPAQUE_RING_STD;
		rx_std_posted = 0;
	}
next_pkt_nopost:
	sw_idx++;
	sw_idx &= (TG3_RX_RCB_RING_SIZE(tp) - 1);

	/* Refresh hw_idx to see if there is new work */
	if (sw_idx == hw_idx) {
		hw_idx = tp->hw_status->idx[0].rx_producer;
	}
	/* ACK the status ring. */
	tp->rx_rcb_ptr = sw_idx;
	tw32_rx_mbox(MAILBOX_RCVRET_CON_IDX_0 + TG3_64BIT_REG_LOW, sw_idx);

	/* Refill RX ring(s). */
	if (work_mask & RXD_OPAQUE_RING_STD) {
		sw_idx = tp->rx_std_ptr % TG3_RX_RING_SIZE;
		tw32_rx_mbox(MAILBOX_RCV_STD_PROD_IDX + TG3_64BIT_REG_LOW,
			     sw_idx);
	}
	if (work_mask & RXD_OPAQUE_RING_JUMBO) {
		sw_idx = tp->rx_jumbo_ptr % TG3_RX_JUMBO_RING_SIZE;
		tw32_rx_mbox(MAILBOX_RCV_JUMBO_PROD_IDX + TG3_64BIT_REG_LOW,
			     sw_idx);
	}

	return len;
}

PRIVATE unsigned int tg3_has_rx_work(struct tg3 * tp)
{
	struct tg3_hw_status *sblk = tp->hw_status;

	/* check for RX work to do */
	if (sblk->idx[0].rx_producer != tp->rx_rcb_ptr)
		return 1;

	return 0;
}


/**
 * is_zero_ether_addr - Determine if give Ethernet address is all zeros.
 * @addr: Pointer to a six-byte array containing the Ethernet address
 *
 * Return true if the address is all zeroes.
 */
PRIVATE int is_zero_ether_addr(const u8_t * addr)
{
	return !(addr[0] | addr[1] | addr[2] | addr[3] | addr[4] | addr[5]);
}

/**
 * is_multicast_ether_addr - Determine if the Ethernet address is a multicast.
 * @addr: Pointer to a six-byte array containing the Ethernet address
 *
 * Return true if the address is a multicast address.
 * By definition the broadcast address is also a multicast address.
 */
PRIVATE int is_multicast_ether_addr(const u8_t * addr)
{
	return (0x01 & addr[0]);
}

/**
 * is_valid_ether_addr - Determine if the given Ethernet address is valid
 * @addr: Pointer to a six-byte array containing the Ethernet address
 *
 * Check that the Ethernet address (MAC) is not 00:00:00:00:00:00, is not
 * a multicast address, and is not FF:FF:FF:FF:FF:FF.
 *
 * Return true if the address is valid.
 */

PRIVATE int is_valid_ether_addr(const u8_t * addr)
{
	/* FF:FF:FF:FF:FF:FF is a multicast address so we don't need to
	 * explicitly check for it here. */
	return !is_multicast_ether_addr(addr) && !is_zero_ether_addr(addr);
}

/**
 * mii_resolve_flowctrl_fdx
 * @lcladv: value of MII ADVERTISE register
 * @rmtadv: value of MII LPA register
 *
 * Resolve full duplex flow control as per IEEE 802.3-2005 table 28B-3
 */
PRIVATE u8_t mii_resolve_flowctrl_fdx(u16_t lcladv, u16_t rmtadv)
{
	u8_t cap = 0;

	if (lcladv & ADVERTISE_PAUSE_CAP) {
		if (lcladv & ADVERTISE_PAUSE_ASYM) {
			if (rmtadv & LPA_PAUSE_CAP)
				cap = FLOW_CTRL_TX | FLOW_CTRL_RX;
			else if (rmtadv & LPA_PAUSE_ASYM)
				cap = FLOW_CTRL_RX;
		} else {
			if (rmtadv & LPA_PAUSE_CAP)
				cap = FLOW_CTRL_TX | FLOW_CTRL_RX;
		}
	} else if (lcladv & ADVERTISE_PAUSE_ASYM) {
		if ((rmtadv & LPA_PAUSE_CAP) && (rmtadv & LPA_PAUSE_ASYM))
			cap = FLOW_CTRL_TX;
	}
	return cap;
}

/**
 * hweightN - returns the hamming weight of a N-bit word
 * @x: the word to weigh
 *
 * The Hamming Weight of a number is the total number of bits set in it.
 */
PRIVATE unsigned int hweight8(unsigned int w)
{
	unsigned int res = w - ((w >> 1) & 0x55);
	res = (res & 0x33) + ((res >> 2) & 0x33);
	return (res + (res >> 4)) & 0x0F;
}

PRIVATE void carrier_on(tg3_t * tp)
{
	printf("%s: carrier up\n", tp->name);
	tp->carrier = 1;
}

PRIVATE void carrier_off(tg3_t * tp)
{
	tp->carrier = 0;
	printf("%s: carrier down\n", tp->name);
}

PRIVATE int tg3_enabled(tg3_t * tp)
{
	return (tp->flags & TG3_ENABLED);
}

PRIVATE int pci_find_cap(int devind, int cap, int *addr)
{
	u8_t status, capptr, type, next;

	/* Check capabilities bit in the device status register */
	status = pci_attr_r16(devind, PCI_SR);
	if (!(status & PSR_CAPPTR)) {
		return 0;
	}
	capptr = (pci_attr_r8(devind, PCI_CAPPTR) & PCI_CP_MASK);
	while (capptr != 0) {

		type = pci_attr_r8(devind, capptr + CAP_TYPE);
		next = (pci_attr_r8(devind, capptr + CAP_NEXT) & PCI_CP_MASK);
		if (type == cap) {
			*addr = capptr;
			return 1;
		}
		capptr = next;
	}

	return 0;
}


/**
 * pcie_set_readrq - set PCI Express maximum memory read request
 * @devind: PCI device to query
 * @rw: maximum memory read count in bytes
 * valid values are 128, 256, 512, 1024, 2048, 4096
 *
 * If possible sets maximum read byte count
 */
PRIVATE void pcie_set_readrq(int devind, int rq)
{
#define PCI_EXP_DEVCTL          8	/* Device Control */
#define  PCI_EXP_DEVCTL_READRQ  0x7000	/* Max_Read_Request_Size */

	int cap, r;
	u16_t ctl, v;

	if (rq < 128 || rq > 4096 || (rq & (rq - 1)))
		return;

	v = (ffs(rq) - 8) << 12;

	r = pci_find_cap(devind, PCI_CAP_ID_EXP, &cap);

	if (!r)
		return;

	ctl = pci_attr_r16(devind, cap + PCI_EXP_DEVCTL);

	if ((ctl & PCI_EXP_DEVCTL_READRQ) != v) {
		ctl &= ~PCI_EXP_DEVCTL_READRQ;
		ctl |= v;

		pci_attr_w32(devind, cap + PCI_EXP_DEVCTL, ctl);
	}
}

PRIVATE int carrier_ok(tg3_t * tp)
{
	return tp->carrier;
}

PRIVATE u32_t readl(u8_t * off)
{
	return *(u32_t *) off;
}

PRIVATE void writel(u32_t val, u8_t * off)
{
	*(u32_t *) off = val;
}

PRIVATE void tg3_dump_flags(tg3_t * tp)
{
	printf("TG3_FLAG_TAGGED_STATUS\t\t is %d\n", 
			!!(TG3_FLAG_TAGGED_STATUS & tp->tg3_flags));
	printf("TG3_FLAG_TXD_MBOX_HWBUG\t\t is %d\n", 
			!!(TG3_FLAG_TXD_MBOX_HWBUG & tp->tg3_flags));
	printf("TG3_FLAG_RX_CHECKSUMS\t\t is %d\n", 
			!!(TG3_FLAG_RX_CHECKSUMS & tp->tg3_flags));
	printf("TG3_FLAG_USE_LINKCHG_REG\t is %d\n", 
			!!(TG3_FLAG_USE_LINKCHG_REG & tp->tg3_flags));
	printf("TG3_FLAG_USE_MI_INTERRUPT\t is %d\n", 
			!!(TG3_FLAG_USE_MI_INTERRUPT & tp->tg3_flags));
	printf("TG3_FLAG_ENABLE_ASF\t\t is %d\n", 
			!!(TG3_FLAG_ENABLE_ASF & tp->tg3_flags));
	printf("TG3_FLAG_ASPM_WORKAROUND\t is %d\n", 
			!!(TG3_FLAG_ASPM_WORKAROUND & tp->tg3_flags));
	printf("TG3_FLAG_POLL_SERDES\t\t is %d\n", 
			!!(TG3_FLAG_POLL_SERDES & tp->tg3_flags));
	printf("TG3_FLAG_MBOX_WRITE_REORDER\t is %d\n",
			!!(TG3_FLAG_MBOX_WRITE_REORDER & tp->tg3_flags));
	printf("TG3_FLAG_PCIX_TARGET_HWBUG\t is %d\n",
			!!(TG3_FLAG_PCIX_TARGET_HWBUG & tp->tg3_flags));
	printf("TG3_FLAG_WOL_SPEED_100MB\t is %d\n",
			!!(TG3_FLAG_WOL_SPEED_100MB & tp->tg3_flags));
	printf("TG3_FLAG_WOL_ENABLE\t\t is %d\n",
			!!(TG3_FLAG_WOL_ENABLE & tp->tg3_flags));
	printf("TG3_FLAG_EEPROM_WRITE_PROT\t is %d\n",
			!!(TG3_FLAG_EEPROM_WRITE_PROT & tp->tg3_flags));
	printf("TG3_FLAG_NVRAM\t\t\t is %d\n",
			!!(TG3_FLAG_NVRAM & tp->tg3_flags));
	printf("TG3_FLAG_NVRAM_BUFFERED\t\t is %d\n",
			!!(TG3_FLAG_NVRAM_BUFFERED & tp->tg3_flags));
	printf("TG3_FLAG_PCIX_MODE\t\t is %d\n",
			!!(TG3_FLAG_PCIX_MODE & tp->tg3_flags));
	printf("TG3_FLAG_PCI_HIGH_SPEED\t\t is %d\n",
			!!(TG3_FLAG_PCI_HIGH_SPEED & tp->tg3_flags));
	printf("TG3_FLAG_PCI_32BIT\t\t is %d\n",
			!!(TG3_FLAG_PCI_32BIT & tp->tg3_flags));
	printf("TG3_FLAG_SRAM_USE_CONFIG\t is %d\n",
			!!(TG3_FLAG_SRAM_USE_CONFIG & tp->tg3_flags));
	printf("TG3_FLAG_TX_RECOVERY_PENDING\t is %d\n",
			!!(TG3_FLAG_TX_RECOVERY_PENDING & tp->tg3_flags));
	printf("TG3_FLAG_WOL_CAP\t\t is %d\n",
			!!(TG3_FLAG_WOL_CAP & tp->tg3_flags));
	printf("TG3_FLAG_JUMBO_RING_ENABLE\t is %d\n",
			!!(TG3_FLAG_JUMBO_RING_ENABLE & tp->tg3_flags));
	printf("TG3_FLAG_10_100_ONLY\t\t is %d\n",
			!!(TG3_FLAG_10_100_ONLY & tp->tg3_flags));
	printf("TG3_FLAG_PAUSE_AUTONEG\t\t is %d\n",
			!!(TG3_FLAG_PAUSE_AUTONEG & tp->tg3_flags));
	printf("TG3_FLAG_CPMU_PRESENT\t\t is %d\n",
			!!(TG3_FLAG_CPMU_PRESENT & tp->tg3_flags));
	printf("TG3_FLAG_40BIT_DMA_BUG\t\t is %d\n",
			!!(TG3_FLAG_40BIT_DMA_BUG & tp->tg3_flags));
	printf("TG3_FLAG_BROKEN_CHECKSUMS\t is %d\n",
			!!(TG3_FLAG_BROKEN_CHECKSUMS & tp->tg3_flags));
	printf("TG3_FLAG_SUPPORT_MSI\t\t is %d\n",
			!!(TG3_FLAG_SUPPORT_MSI & tp->tg3_flags));
	printf("TG3_FLAG_CHIP_RESETTING\t\t is %d\n",
			!!(TG3_FLAG_CHIP_RESETTING & tp->tg3_flags));
	printf("TG3_FLAG_INIT_COMPLETE\t\t is %d\n",
			!!(TG3_FLAG_INIT_COMPLETE & tp->tg3_flags));
	printf("-\n");
	printf("TG3_FLG2_RESTART_TIMER\t\t is %d\n",
			!!(TG3_FLG2_RESTART_TIMER & tp->tg3_flags2));
	printf("TG3_FLG2_TSO_BUG\t\t is %d\n",
			!!(TG3_FLG2_TSO_BUG & tp->tg3_flags2));
	printf("TG3_FLG2_NO_ETH_WIRE_SPEED\t is %d\n",
			!!(TG3_FLG2_NO_ETH_WIRE_SPEED & tp->tg3_flags2));
	printf("TG3_FLG2_IS_5788\t\t is %d\n",
			!!(TG3_FLG2_IS_5788 & tp->tg3_flags2));
	printf("TG3_FLG2_MAX_RXPEND_64\t\t is %d\n",
			!!(TG3_FLG2_MAX_RXPEND_64 & tp->tg3_flags2));
	printf("TG3_FLG2_TSO_CAPABLE\t\t is %d\n",
			!!(TG3_FLG2_TSO_CAPABLE & tp->tg3_flags2));
	printf("TG3_FLG2_PHY_ADC_BUG\t\t is %d\n",
			!!(TG3_FLG2_PHY_ADC_BUG & tp->tg3_flags2));
	printf("TG3_FLG2_PHY_5704_A0_BUG\t is %d\n",
			!!(TG3_FLG2_PHY_5704_A0_BUG & tp->tg3_flags2));
	printf("TG3_FLG2_PHY_BER_BUG\t\t is %d\n",
			!!(TG3_FLG2_PHY_BER_BUG & tp->tg3_flags2));
	printf("TG3_FLG2_PCI_EXPRESS\t\t is %d\n",
			!!(TG3_FLG2_PCI_EXPRESS & tp->tg3_flags2));
	printf("TG3_FLG2_ASF_NEW_HANDSHAKE\t is %d\n",
			!!(TG3_FLG2_ASF_NEW_HANDSHAKE & tp->tg3_flags2));
	printf("TG3_FLG2_HW_AUTONEG\t\t is %d\n",
			!!(TG3_FLG2_HW_AUTONEG & tp->tg3_flags2));
	printf("TG3_FLG2_IS_NIC\t\t\t is %d\n",
			!!(TG3_FLG2_IS_NIC & tp->tg3_flags2));
	printf("TG3_FLG2_PHY_SERDES\t\t is %d\n",
			!!(TG3_FLG2_PHY_SERDES & tp->tg3_flags2));
	printf("TG3_FLG2_CAPACITIVE_COUPLING\t is %d\n",
			!!(TG3_FLG2_CAPACITIVE_COUPLING & tp->tg3_flags2));
	printf("TG3_FLG2_FLASH\t\t\t is %d\n",
			!!(TG3_FLG2_FLASH & tp->tg3_flags2));
	printf("TG3_FLG2_HW_TSO_1\t\t is %d\n",
			!!(TG3_FLG2_HW_TSO_1 & tp->tg3_flags2));
	printf("TG3_FLG2_SERDES_PREEMPHASIS\t is %d\n",
			!!(TG3_FLG2_SERDES_PREEMPHASIS & tp->tg3_flags2));
	printf("TG3_FLG2_5705_PLUS\t\t is %d\n",
			!!(TG3_FLG2_5705_PLUS & tp->tg3_flags2));
	printf("TG3_FLG2_5750_PLUS\t\t is %d\n",
			!!(TG3_FLG2_5750_PLUS & tp->tg3_flags2));
	printf("TG3_FLG2_PROTECTED_NVRAM\t is %d\n",
			!!(TG3_FLG2_PROTECTED_NVRAM & tp->tg3_flags2));
	printf("TG3_FLG2_USING_MSI\t\t is %d\n",
			!!(TG3_FLG2_USING_MSI & tp->tg3_flags2));
	printf("TG3_FLG2_JUMBO_CAPABLE\t\t is %d\n",
			!!(TG3_FLG2_JUMBO_CAPABLE & tp->tg3_flags2));
	printf("TG3_FLG2_MII_SERDES\t\t is %d\n",
			!!(TG3_FLG2_MII_SERDES & tp->tg3_flags2));
	printf("TG3_FLG2_ANY_SERDES\t\t is %d\n",
			!!(TG3_FLG2_ANY_SERDES & tp->tg3_flags2));
	printf("TG3_FLG2_PARALLEL_DETECT\t is %d\n",
			!!(TG3_FLG2_PARALLEL_DETECT & tp->tg3_flags2));
	printf("TG3_FLG2_ICH_WORKAROUND\t\t is %d\n",
			!!(TG3_FLG2_ICH_WORKAROUND & tp->tg3_flags2));
	printf("TG3_FLG2_5780_CLASS\t\t is %d\n",
			!!(TG3_FLG2_5780_CLASS & tp->tg3_flags2));
	printf("TG3_FLG2_HW_TSO_2\t\t is %d\n",
			!!(TG3_FLG2_HW_TSO_2 & tp->tg3_flags2));
	printf("TG3_FLG2_HW_TSO\t\t\t is %d\n",
			!!(TG3_FLG2_HW_TSO & tp->tg3_flags2));
	printf("TG3_FLG2_1SHOT_MSI\t\t is %d\n",
			!!(TG3_FLG2_1SHOT_MSI & tp->tg3_flags2));
	printf("TG3_FLG2_PHY_JITTER_BUG\t\t is %d\n",
			!!(TG3_FLG2_PHY_JITTER_BUG & tp->tg3_flags2));
	printf("TG3_FLG2_NO_FWARE_REPORTED\t is %d\n",
			!!(TG3_FLG2_NO_FWARE_REPORTED & tp->tg3_flags2));
	printf("TG3_FLG2_PHY_ADJUST_TRIM\t is %d\n",
			!!(TG3_FLG2_PHY_ADJUST_TRIM & tp->tg3_flags2));
	printf("-\n");
	printf("TG3_FLG3_NO_NVRAM_ADDR_TRANS\t is %d\n",
			!!(TG3_FLG3_NO_NVRAM_ADDR_TRANS & tp->tg3_flags3));
	printf("TG3_FLG3_ENABLE_APE\t\t is %d\n",
			!!(TG3_FLG3_ENABLE_APE & tp->tg3_flags3));
	printf("TG3_FLG3_5701_DMA_BUG\t\t is %d\n",
			!!(TG3_FLG3_5701_DMA_BUG & tp->tg3_flags3));
	printf("TG3_FLG3_USE_PHYLIB\t\t is %d\n",
			!!(TG3_FLG3_USE_PHYLIB & tp->tg3_flags3));
	printf("TG3_FLG3_MDIOBUS_INITED\t\t is %d\n",
			!!(TG3_FLG3_MDIOBUS_INITED & tp->tg3_flags3));
	printf("TG3_FLG3_MDIOBUS_PAUSED\t\t is %d\n",
			!!(TG3_FLG3_MDIOBUS_PAUSED & tp->tg3_flags3));
	printf("TG3_FLG3_PHY_CONNECTED\t\t is %d\n",
			!!(TG3_FLG3_PHY_CONNECTED & tp->tg3_flags3));
	printf("TG3_FLG3_RGMII_STD_IBND_DISABLE\t is %d\n",
			!!(TG3_FLG3_RGMII_STD_IBND_DISABLE & tp->tg3_flags3));
	printf("TG3_FLG3_RGMII_EXT_IBND_RX_EN\t is %d\n",
			!!(TG3_FLG3_RGMII_EXT_IBND_RX_EN & tp->tg3_flags3));
	printf("TG3_FLG3_RGMII_EXT_IBND_TX_EN\t is %d\n",
			!!(TG3_FLG3_RGMII_EXT_IBND_TX_EN & tp->tg3_flags3));
	printf("TG3_FLG3_CLKREQ_BUG\t\t is %d\n",
			!!(TG3_FLG3_CLKREQ_BUG & tp->tg3_flags3));
	printf("TG3_FLG3_PHY_ENABLE_APD\t\t is %d\n",
			!!(TG3_FLG3_PHY_ENABLE_APD & tp->tg3_flags3));
	printf("TG3_FLG3_5755_PLUS\t\t is %d\n",
			!!(TG3_FLG3_5755_PLUS & tp->tg3_flags3));
	printf("TG3_FLG3_NO_NVRAM\t\t is %d\n",
			!!(TG3_FLG3_NO_NVRAM & tp->tg3_flags3));
}

PRIVATE void tg3_write32(tg3_t * tp, u32_t off, u32_t val)
{
	writel(val, tp->regs + off);
}

PRIVATE u32_t tg3_read32(tg3_t * tp, u32_t off)
{
	return readl(tp->regs + off);
}

PRIVATE void tg3_ape_write32(tg3_t * tp, u32_t off, u32_t val)
{
	writel(val, tp->aperegs + off);
}

PRIVATE u32_t tg3_ape_read32(tg3_t * tp, u32_t off)
{
	return (readl(tp->aperegs + off));
}

PRIVATE void tg3_write_indirect_reg32(tg3_t * tp, u32_t off, u32_t val)
{
	pci_attr_w32(tp->devind, TG3PCI_REG_BASE_ADDR, off);
	pci_attr_w32(tp->devind, TG3PCI_REG_DATA, val);
}

PRIVATE void tg3_write_flush_reg32(tg3_t * tp, u32_t off, u32_t val)
{
	writel(val, tp->regs + off);
	readl(tp->regs + off);
}

PRIVATE u32_t tg3_read_indirect_reg32(tg3_t * tp, u32_t off)
{
	u32_t val;

	pci_attr_w32(tp->devind, TG3PCI_REG_BASE_ADDR, off);
	val = pci_attr_r32(tp->devind, TG3PCI_REG_DATA);

	return val;
}

PRIVATE void tg3_write_indirect_mbox(tg3_t * tp, u32_t off, u32_t val)
{
	if (off == (MAILBOX_RCVRET_CON_IDX_0 + TG3_64BIT_REG_LOW)) {
		pci_attr_w32(tp->devind, TG3PCI_RCV_RET_RING_CON_IDX +
			     TG3_64BIT_REG_LOW, val);

		return;
	}
	if (off == (MAILBOX_RCV_STD_PROD_IDX + TG3_64BIT_REG_LOW)) {
		pci_attr_w32(tp->devind, TG3PCI_STD_RING_PROD_IDX +
			     TG3_64BIT_REG_LOW, val);

		return;
	}
	pci_attr_w32(tp->devind, TG3PCI_REG_BASE_ADDR, off + 0x5600);
	pci_attr_w32(tp->devind, TG3PCI_REG_DATA, val);

	/* In indirect mode when disabling interrupts, we also need to clear
	 * the interrupt bit in the GRC local ctrl register. */
	if ((off == (MAILBOX_INTERRUPT_0 + TG3_64BIT_REG_LOW)) &&
	    (val == 0x1)) {
		pci_attr_w32(tp->devind, TG3PCI_MISC_LOCAL_CTRL,
			     tp->grc_local_ctrl | GRC_LCLCTRL_CLEARINT);
	}
}

PRIVATE u32_t tg3_read_indirect_mbox(tg3_t * tp, u32_t off)
{
	u32_t val;

	pci_attr_w32(tp->devind, TG3PCI_REG_BASE_ADDR, off + 0x5600);
	val = pci_attr_r32(tp->devind, TG3PCI_REG_DATA);

	return val;
}

/* usec_wait specifies the wait time in usec when writing to certain registers
 * where it is unsafe to read back the register without some delay.
 * GRC_LOCAL_CTRL is one example if the GPIOs are toggled to switch power.
 * TG3PCI_CLOCK_CTRL is another example if the clock frequencies are changed.
 */
PRIVATE void _tw32_flush(tg3_t * tp, u32_t off, u32_t val, u32_t usec_wait)
{
	if ((tp->tg3_flags & TG3_FLAG_PCIX_TARGET_HWBUG) ||
	    (tp->tg3_flags2 & TG3_FLG2_ICH_WORKAROUND)) {
		/* Non-posted methods */
		tp->write32(tp, off, val);
	} else {
		/* Posted method */
		tg3_write32(tp, off, val);
		if (usec_wait)
			micro_delay(usec_wait);
		tp->read32(tp, off);
	}
	/* Wait again after the read for the posted method to guarantee that
	 * the wait time is met. */
	if (usec_wait)
		micro_delay(usec_wait);
}

PRIVATE void tw32_mailbox_flush(tg3_t * tp, u32_t off, u32_t val)
{
	tp->write32_mbox(tp, off, val);
	if (!(tp->tg3_flags & TG3_FLAG_MBOX_WRITE_REORDER) &&
	    !(tp->tg3_flags2 & TG3_FLG2_ICH_WORKAROUND))
		tp->read32_mbox(tp, off);
}

PRIVATE void tg3_write32_tx_mbox(tg3_t * tp, u32_t off, u32_t val)
{
	u8_t *mbox = tp->regs + off;

	writel(val, mbox);
	if (tp->tg3_flags & TG3_FLAG_TXD_MBOX_HWBUG)
		writel(val, mbox);
	if (tp->tg3_flags & TG3_FLAG_MBOX_WRITE_REORDER)
		readl(mbox);
}

PRIVATE u32_t tg3_read32_mbox_5906(tg3_t * tp, u32_t off)
{
	return (readl(tp->regs + off + GRCMBOX_BASE));
}

PRIVATE void tg3_write32_mbox_5906(tg3_t * tp, u32_t off, u32_t val)
{
	writel(val, tp->regs + off + GRCMBOX_BASE);
}

PRIVATE void tg3_write_mem(tg3_t * tp, u32_t off, u32_t val)
{
	if ((GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) &&
	    (off >= NIC_SRAM_STATS_BLK) && (off < NIC_SRAM_TX_BUFFER_DESC))
		return;

	if (tp->tg3_flags & TG3_FLAG_SRAM_USE_CONFIG) {
		pci_attr_w32(tp->devind, TG3PCI_MEM_WIN_BASE_ADDR, off);
		pci_attr_w32(tp->devind, TG3PCI_MEM_WIN_DATA, val);

		/* Always leave this as zero. */
		pci_attr_w32(tp->devind, TG3PCI_MEM_WIN_BASE_ADDR, 0);
	} else {
		tw32_f(TG3PCI_MEM_WIN_BASE_ADDR, off);
		tw32_f(TG3PCI_MEM_WIN_DATA, val);

		/* Always leave this as zero. */
		tw32_f(TG3PCI_MEM_WIN_BASE_ADDR, 0);
	}
}

PRIVATE void tg3_read_mem(tg3_t * tp, u32_t off, u32_t * val)
{
	if ((GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) &&
	    (off >= NIC_SRAM_STATS_BLK) && (off < NIC_SRAM_TX_BUFFER_DESC)) {
		*val = 0;
		return;
	}
	if (tp->tg3_flags & TG3_FLAG_SRAM_USE_CONFIG) {
		pci_attr_w32(tp->devind, TG3PCI_MEM_WIN_BASE_ADDR, off);
		*val = pci_attr_r32(tp->devind, TG3PCI_MEM_WIN_DATA);

		/* Always leave this as zero. */
		pci_attr_w32(tp->devind, TG3PCI_MEM_WIN_BASE_ADDR, 0);
	} else {
		tw32_f(TG3PCI_MEM_WIN_BASE_ADDR, off);
		*val = tr32(TG3PCI_MEM_WIN_DATA);

		/* Always leave this as zero. */
		tw32_f(TG3PCI_MEM_WIN_BASE_ADDR, 0);
	}
}

PRIVATE void tg3_ape_lock_init(tg3_t * tp)
{
	int i;

	/* Make sure the driver hasn't any stale locks. */
	for (i = 0; i < 8; i++)
		tg3_ape_write32(tp, TG3_APE_LOCK_GRANT + 4 * i,
				APE_LOCK_GRANT_DRIVER);
}

PRIVATE int tg3_ape_lock(tg3_t * tp, int locknum)
{
	int i, off;
	int ret = 0;
	u32_t status;

	if (!(tp->tg3_flags3 & TG3_FLG3_ENABLE_APE))
		return 0;

	switch (locknum) {
	case TG3_APE_LOCK_GRC:
	case TG3_APE_LOCK_MEM:
		break;
	default:
		return -EINVAL;
	}

	off = 4 * locknum;

	tg3_ape_write32(tp, TG3_APE_LOCK_REQ + off, APE_LOCK_REQ_DRIVER);

	/* Wait for up to 1 millisecond to acquire lock. */
	for (i = 0; i < 100; i++) {
		status = tg3_ape_read32(tp, TG3_APE_LOCK_GRANT + off);
		if (status == APE_LOCK_GRANT_DRIVER)
			break;
		micro_delay(10);
	}

	if (status != APE_LOCK_GRANT_DRIVER) {
		/* Revoke the lock request. */
		tg3_ape_write32(tp, TG3_APE_LOCK_GRANT + off,
				APE_LOCK_GRANT_DRIVER);

		ret = -EBUSY;
	}
	return ret;
}

PRIVATE void tg3_ape_unlock(tg3_t * tp, int locknum)
{
	int off;

	if (!(tp->tg3_flags3 & TG3_FLG3_ENABLE_APE))
		return;

	switch (locknum) {
	case TG3_APE_LOCK_GRC:
	case TG3_APE_LOCK_MEM:
		break;
	default:
		return;
	}

	off = 4 * locknum;
	tg3_ape_write32(tp, TG3_APE_LOCK_GRANT + off, APE_LOCK_GRANT_DRIVER);
}

PRIVATE void tg3_disable_ints(tg3_t * tp)
{
	tw32(TG3PCI_MISC_HOST_CTRL,
	     (tp->misc_host_ctrl | MISC_HOST_CTRL_MASK_PCI_INT));
	tw32_mailbox_f(MAILBOX_INTERRUPT_0 + TG3_64BIT_REG_LOW, 0x00000001);
}

PRIVATE void tg3_cond_int(tg3_t * tp)
{
	if (!(tp->tg3_flags & TG3_FLAG_TAGGED_STATUS) &&
	    (tp->hw_status->status & SD_STATUS_UPDATED))
		tw32(GRC_LOCAL_CTRL, tp->grc_local_ctrl | GRC_LCLCTRL_SETINT);
	else
		tw32(HOSTCC_MODE, tp->coalesce_mode |
		     (HOSTCC_MODE_ENABLE | HOSTCC_MODE_NOW));
}


PRIVATE void tg3_enable_ints(tg3_t * tp)
{
	tp->irq_sync = 0;

	tw32(TG3PCI_MISC_HOST_CTRL,
	     (tp->misc_host_ctrl & ~MISC_HOST_CTRL_MASK_PCI_INT));
	tw32_mailbox_f(MAILBOX_INTERRUPT_0 + TG3_64BIT_REG_LOW,
		       (tp->last_tag << 24));
	if (tp->tg3_flags2 & TG3_FLG2_1SHOT_MSI)
		tw32_mailbox_f(MAILBOX_INTERRUPT_0 + TG3_64BIT_REG_LOW,
			       (tp->last_tag << 24));
	tg3_cond_int(tp);
}

PRIVATE unsigned int tg3_has_work(tg3_t * tp)
{
	struct tg3_hw_status *sblk = tp->hw_status;
	unsigned int work_exists = 0;

	/* check for phy events */
	if (!(tp->tg3_flags &
	      (TG3_FLAG_USE_LINKCHG_REG |
	       TG3_FLAG_POLL_SERDES))) {
		if (sblk->status & SD_STATUS_LINK_CHG)
			work_exists = 1;
	}
	/* check for RX/TX work to do */
	if (sblk->idx[0].tx_consumer != tp->tx_cons)	/* || */
		/* sblk->idx[0].rx_producer != tp->rx_rcb_ptr) */
		work_exists = 1;

	return work_exists;
}

/* tg3_restart_ints
 *  similar to tg3_enable_ints, but it accurately determines whether there
 *  is new work pending and can return without flushing the PIO write
 *  which reenables interrupts
 */
PRIVATE void tg3_restart_ints(tg3_t * tp)
{
	tw32_mailbox(MAILBOX_INTERRUPT_0 + TG3_64BIT_REG_LOW,
		     tp->last_tag << 24);

	/* When doing tagged status, this work check is unnecessary. The
	 * last_tag we write above tells the chip which piece of work we've
	 * completed. */
	if (!(tp->tg3_flags & TG3_FLAG_TAGGED_STATUS) &&
	    tg3_has_work(tp))
		tw32(HOSTCC_MODE, tp->coalesce_mode |
		     (HOSTCC_MODE_ENABLE | HOSTCC_MODE_NOW));
}

PRIVATE void tg3_start(tg3_t * tp)
{
	tp->hw_status->status |= SD_STATUS_UPDATED;
	tg3_enable_ints(tp);
}

PRIVATE void tg3_switch_clocks(tg3_t * tp)
{
	u32_t clock_ctrl = tr32(TG3PCI_CLOCK_CTRL);
	u32_t orig_clock_ctrl;

	if ((tp->tg3_flags & TG3_FLAG_CPMU_PRESENT) ||
	    (tp->tg3_flags2 & TG3_FLG2_5780_CLASS))
		return;

	orig_clock_ctrl = clock_ctrl;
	clock_ctrl &= (CLOCK_CTRL_FORCE_CLKRUN |
		       CLOCK_CTRL_CLKRUN_OENABLE |
		       0x1f);
	tp->pci_clock_ctrl = clock_ctrl;

	if (tp->tg3_flags2 & TG3_FLG2_5705_PLUS) {
		if (orig_clock_ctrl & CLOCK_CTRL_625_CORE) {
			tw32_wait_f(TG3PCI_CLOCK_CTRL,
				    clock_ctrl | CLOCK_CTRL_625_CORE, 40);
		}
	} else if ((orig_clock_ctrl & CLOCK_CTRL_44MHZ_CORE) != 0) {
		tw32_wait_f(TG3PCI_CLOCK_CTRL,
			    clock_ctrl |
			    (CLOCK_CTRL_44MHZ_CORE | CLOCK_CTRL_ALTCLK),
			    40);
		tw32_wait_f(TG3PCI_CLOCK_CTRL,
			    clock_ctrl | (CLOCK_CTRL_ALTCLK),
			    40);
	}
	tw32_wait_f(TG3PCI_CLOCK_CTRL, clock_ctrl, 40);
}

#define PHY_BUSY_LOOPS	5000

PRIVATE int tg3_readphy(tg3_t * tp, int reg, u32_t * val)
{
	u32_t frame_val;
	unsigned int loops;
	int ret;

	if ((tp->mi_mode & MAC_MI_MODE_AUTO_POLL) != 0) {
		tw32_f(MAC_MI_MODE,
		       (tp->mi_mode & ~MAC_MI_MODE_AUTO_POLL));
		micro_delay(80);
	}
	*val = 0x0;

	frame_val = ((PHY_ADDR << MI_COM_PHY_ADDR_SHIFT) &
		     MI_COM_PHY_ADDR_MASK);
	frame_val |= ((reg << MI_COM_REG_ADDR_SHIFT) &
		      MI_COM_REG_ADDR_MASK);
	frame_val |= (MI_COM_CMD_READ | MI_COM_START);

	tw32_f(MAC_MI_COM, frame_val);

	loops = PHY_BUSY_LOOPS;
	while (loops != 0) {
		micro_delay(10);
		frame_val = tr32(MAC_MI_COM);

		if ((frame_val & MI_COM_BUSY) == 0) {
			micro_delay(5);
			frame_val = tr32(MAC_MI_COM);
			break;
		}
		loops -= 1;
	}

	ret = -EBUSY;
	if (loops != 0) {
		*val = frame_val & MI_COM_DATA_MASK;
		ret = 0;
	}
	if ((tp->mi_mode & MAC_MI_MODE_AUTO_POLL) != 0) {
		tw32_f(MAC_MI_MODE, tp->mi_mode);
		micro_delay(80);
	}
	return ret;
}

PRIVATE int tg3_writephy(tg3_t * tp, int reg, u32_t val)
{
	u32_t frame_val;
	unsigned int loops;
	int ret;

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906 &&
	    (reg == MII_TG3_CTRL || reg == MII_TG3_AUX_CTRL))
		return 0;

	if ((tp->mi_mode & MAC_MI_MODE_AUTO_POLL) != 0) {
		tw32_f(MAC_MI_MODE,
		       (tp->mi_mode & ~MAC_MI_MODE_AUTO_POLL));
		micro_delay(80);
	}
	frame_val = ((PHY_ADDR << MI_COM_PHY_ADDR_SHIFT) &
		     MI_COM_PHY_ADDR_MASK);
	frame_val |= ((reg << MI_COM_REG_ADDR_SHIFT) &
		      MI_COM_REG_ADDR_MASK);
	frame_val |= (val & MI_COM_DATA_MASK);
	frame_val |= (MI_COM_CMD_WRITE | MI_COM_START);

	tw32_f(MAC_MI_COM, frame_val);

	loops = PHY_BUSY_LOOPS;
	while (loops != 0) {
		micro_delay(10);
		frame_val = tr32(MAC_MI_COM);
		if ((frame_val & MI_COM_BUSY) == 0) {
			micro_delay(5);
			frame_val = tr32(MAC_MI_COM);
			break;
		}
		loops -= 1;
	}

	ret = -EBUSY;
	if (loops != 0)
		ret = 0;

	if ((tp->mi_mode & MAC_MI_MODE_AUTO_POLL) != 0) {
		tw32_f(MAC_MI_MODE, tp->mi_mode);
		micro_delay(80);
	}
	return ret;
}

PRIVATE int tg3_bmcr_reset(tg3_t * tp)
{
	u32_t phy_control;
	int limit, err;

	/* OK, reset it, and poll the BMCR_RESET bit until it clears or we time
	 * out. */
	phy_control = BMCR_RESET;
	err = tg3_writephy(tp, MII_BMCR, phy_control);
	if (err != 0)
		return -EBUSY;

	limit = 5000;
	while (limit--) {
		err = tg3_readphy(tp, MII_BMCR, &phy_control);
		if (err != 0)
			return -EBUSY;

		if ((phy_control & BMCR_RESET) == 0) {
			micro_delay(40);
			break;
		}
		micro_delay(10);
	}
	if (limit < 0)
		return -EBUSY;

	return 0;
}

PRIVATE void tg3_mdio_start(tg3_t * tp)
{
	u32_t val;

	tp->mi_mode &= ~MAC_MI_MODE_AUTO_POLL;
	tw32_f(MAC_MI_MODE, tp->mi_mode);
	micro_delay(80);

	if (GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5785)
		return;

	if ((tp->phy_id & PHY_ID_MASK) == PHY_ID_BCMAC131) {
		tw32(MAC_PHYCFG2, MAC_PHYCFG2_AC131_LED_MODES);

		val = tr32(MAC_PHYCFG1);
		val &= ~(MAC_PHYCFG1_RGMII_INT |
		       MAC_PHYCFG1_RXCLK_TO_MASK | MAC_PHYCFG1_TXCLK_TO_MASK);
		val |= MAC_PHYCFG1_RXCLK_TIMEOUT | MAC_PHYCFG1_TXCLK_TIMEOUT;
		tw32(MAC_PHYCFG1, val);

		return;
	}
	val = MAC_PHYCFG2_50610_LED_MODES;

	if (!(tp->tg3_flags3 & TG3_FLG3_RGMII_STD_IBND_DISABLE))
		val |= MAC_PHYCFG2_EMODE_MASK_MASK |
			MAC_PHYCFG2_FMODE_MASK_MASK |
			MAC_PHYCFG2_GMODE_MASK_MASK |
			MAC_PHYCFG2_ACT_MASK_MASK |
			MAC_PHYCFG2_QUAL_MASK_MASK |
			MAC_PHYCFG2_INBAND_ENABLE;

	tw32(MAC_PHYCFG2, val);

	val = tr32(MAC_PHYCFG1);
	val &= ~(MAC_PHYCFG1_RXCLK_TO_MASK | MAC_PHYCFG1_TXCLK_TO_MASK |
		 MAC_PHYCFG1_RGMII_EXT_RX_DEC | MAC_PHYCFG1_RGMII_SND_STAT_EN);
	if (!(tp->tg3_flags3 & TG3_FLG3_RGMII_STD_IBND_DISABLE)) {
		if (tp->tg3_flags3 & TG3_FLG3_RGMII_EXT_IBND_RX_EN)
			val |= MAC_PHYCFG1_RGMII_EXT_RX_DEC;
		if (tp->tg3_flags3 & TG3_FLG3_RGMII_EXT_IBND_TX_EN)
			val |= MAC_PHYCFG1_RGMII_SND_STAT_EN;
	}
	val |= MAC_PHYCFG1_RXCLK_TIMEOUT | MAC_PHYCFG1_TXCLK_TIMEOUT |
		MAC_PHYCFG1_RGMII_INT | MAC_PHYCFG1_TXC_DRV;
	tw32(MAC_PHYCFG1, val);

	val = tr32(MAC_EXT_RGMII_MODE);
	val &= ~(MAC_RGMII_MODE_RX_INT_B |
		 MAC_RGMII_MODE_RX_QUALITY |
		 MAC_RGMII_MODE_RX_ACTIVITY |
		 MAC_RGMII_MODE_RX_ENG_DET |
		 MAC_RGMII_MODE_TX_ENABLE |
		 MAC_RGMII_MODE_TX_LOWPWR |
		 MAC_RGMII_MODE_TX_RESET);
	if (!(tp->tg3_flags3 & TG3_FLG3_RGMII_STD_IBND_DISABLE)) {
		if (tp->tg3_flags3 & TG3_FLG3_RGMII_EXT_IBND_RX_EN)
			val |= MAC_RGMII_MODE_RX_INT_B |
				MAC_RGMII_MODE_RX_QUALITY |
				MAC_RGMII_MODE_RX_ACTIVITY |
				MAC_RGMII_MODE_RX_ENG_DET;
		if (tp->tg3_flags3 & TG3_FLG3_RGMII_EXT_IBND_TX_EN)
			val |= MAC_RGMII_MODE_TX_ENABLE |
				MAC_RGMII_MODE_TX_LOWPWR |
				MAC_RGMII_MODE_TX_RESET;
	}
	tw32(MAC_EXT_RGMII_MODE, val);
}
PRIVATE int tg3_mdio_init(struct tg3 * tp)
{
	tg3_mdio_start(tp);
	return 0;
}

PRIVATE void tg3_generate_fw_event(tg3_t * tp)
{
	u32_t val;

	val = tr32(GRC_RX_CPU_EVENT);
	val |= GRC_RX_CPU_DRIVER_EVENT;
	tw32_f(GRC_RX_CPU_EVENT, val);
}



PRIVATE void tg3_wait_for_event_ack(tg3_t * tp)
{
/*#define TG3_FW_EVENT_TIMEOUT_USEC 2500*/
	/* In Minix we currently we don't need this. */
}

PRIVATE void tg3_ump_link_report(tg3_t * tp)
{
	u32_t reg;
	u32_t val;

	if (!(tp->tg3_flags2 & TG3_FLG2_5780_CLASS) ||
	    !(tp->tg3_flags & TG3_FLAG_ENABLE_ASF))
		return;

	tg3_wait_for_event_ack(tp);

	tg3_write_mem(tp, NIC_SRAM_FW_CMD_MBOX, FWCMD_NICDRV_LINK_UPDATE);

	tg3_write_mem(tp, NIC_SRAM_FW_CMD_LEN_MBOX, 14);

	val = 0;
	if (!tg3_readphy(tp, MII_BMCR, &reg))
		val = reg << 16;
	if (!tg3_readphy(tp, MII_BMSR, &reg))
		val |= (reg & 0xffff);
	tg3_write_mem(tp, NIC_SRAM_FW_CMD_DATA_MBOX, val);

	val = 0;
	if (!tg3_readphy(tp, MII_ADVERTISE, &reg))
		val = reg << 16;
	if (!tg3_readphy(tp, MII_LPA, &reg))
		val |= (reg & 0xffff);
	tg3_write_mem(tp, NIC_SRAM_FW_CMD_DATA_MBOX + 4, val);

	val = 0;
	if (!(tp->tg3_flags2 & TG3_FLG2_MII_SERDES)) {
		if (!tg3_readphy(tp, MII_CTRL1000, &reg))
			val = reg << 16;
		if (!tg3_readphy(tp, MII_STAT1000, &reg))
			val |= (reg & 0xffff);
	}
	tg3_write_mem(tp, NIC_SRAM_FW_CMD_DATA_MBOX + 8, val);

	if (!tg3_readphy(tp, MII_PHYADDR, &reg))
		val = reg << 16;
	else
		val = 0;
	tg3_write_mem(tp, NIC_SRAM_FW_CMD_DATA_MBOX + 12, val);

	tg3_generate_fw_event(tp);
}

PRIVATE void tg3_link_report(tg3_t * tp)
{
	if (!carrier_ok(tp)) {
		printf("%s: Link is down.\n", tp->name);
		tg3_ump_link_report(tp);
	} else {
		printf("%s: Link is up at %d Mbps, %s duplex.\n",
		       tp->name,
		       (tp->link_config.active_speed == SPEED_1000 ?
			1000 :
			(tp->link_config.active_speed == SPEED_100 ?
			 100 : 10)),
		       (tp->link_config.active_duplex == DUPLEX_FULL ?
			"full" : "half"));

		printf(
		       "%s: Flow control is %s for TX and %s for RX.\n",
		       tp->name,
		       (tp->link_config.active_flowctrl & FLOW_CTRL_TX) ?
		       "on" : "off",
		       (tp->link_config.active_flowctrl & FLOW_CTRL_RX) ?
		       "on" : "off");
		tg3_ump_link_report(tp);
	}
}

PRIVATE u16_t tg3_advert_flowctrl_1000T(u8_t flow_ctrl)
{
	u16_t miireg;

	if ((flow_ctrl & FLOW_CTRL_TX) && (flow_ctrl & FLOW_CTRL_RX))
		miireg = ADVERTISE_PAUSE_CAP;
	else if (flow_ctrl & FLOW_CTRL_TX)
		miireg = ADVERTISE_PAUSE_ASYM;
	else if (flow_ctrl & FLOW_CTRL_RX)
		miireg = ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM;
	else
		miireg = 0;

	return miireg;
}

PRIVATE u16_t tg3_advert_flowctrl_1000X(u8_t flow_ctrl)
{
	u16_t miireg;

	if ((flow_ctrl & FLOW_CTRL_TX) && (flow_ctrl & FLOW_CTRL_RX))
		miireg = ADVERTISE_1000XPAUSE;
	else if (flow_ctrl & FLOW_CTRL_TX)
		miireg = ADVERTISE_1000XPSE_ASYM;
	else if (flow_ctrl & FLOW_CTRL_RX)
		miireg = ADVERTISE_1000XPAUSE | ADVERTISE_1000XPSE_ASYM;
	else
		miireg = 0;

	return miireg;
}

PRIVATE u8_t tg3_resolve_flowctrl_1000X(u16_t lcladv, u16_t rmtadv)
{
	u8_t cap = 0;

	if (lcladv & ADVERTISE_1000XPAUSE) {
		if (lcladv & ADVERTISE_1000XPSE_ASYM) {
			if (rmtadv & LPA_1000XPAUSE)
				cap = FLOW_CTRL_TX | FLOW_CTRL_RX;
			else if (rmtadv & LPA_1000XPAUSE_ASYM)
				cap = FLOW_CTRL_RX;
		} else {
			if (rmtadv & LPA_1000XPAUSE)
				cap = FLOW_CTRL_TX | FLOW_CTRL_RX;
		}
	} else if (lcladv & ADVERTISE_1000XPSE_ASYM) {
		if ((rmtadv & LPA_1000XPAUSE) && (rmtadv & LPA_1000XPAUSE_ASYM))
			cap = FLOW_CTRL_TX;
	}
	return cap;
}

PRIVATE void tg3_setup_flow_control(tg3_t * tp, u32_t lcladv, u32_t rmtadv)
{
	u8_t autoneg;
	u8_t flowctrl = 0;
	u32_t old_rx_mode = tp->rx_mode;
	u32_t old_tx_mode = tp->tx_mode;

	autoneg = tp->link_config.autoneg;

	if (autoneg == AUTONEG_ENABLE &&
	    (tp->tg3_flags & TG3_FLAG_PAUSE_AUTONEG)) {
		if (tp->tg3_flags2 & TG3_FLG2_ANY_SERDES)
			flowctrl = tg3_resolve_flowctrl_1000X(lcladv, rmtadv);
		else
			flowctrl = mii_resolve_flowctrl_fdx(lcladv, rmtadv);
	} else
		flowctrl = tp->link_config.flowctrl;

	tp->link_config.active_flowctrl = flowctrl;

	if (flowctrl & FLOW_CTRL_RX)
		tp->rx_mode |= RX_MODE_FLOW_CTRL_ENABLE;
	else
		tp->rx_mode &= ~RX_MODE_FLOW_CTRL_ENABLE;

	if (old_rx_mode != tp->rx_mode)
		tw32_f(MAC_RX_MODE, tp->rx_mode);

	if (flowctrl & FLOW_CTRL_TX)
		tp->tx_mode |= TX_MODE_FLOW_CTRL_ENABLE;
	else
		tp->tx_mode &= ~TX_MODE_FLOW_CTRL_ENABLE;

	if (old_tx_mode != tp->tx_mode)
		tw32_f(MAC_TX_MODE, tp->tx_mode);
}

PRIVATE void tg3_phydsp_write(tg3_t * tp, u32_t reg, u32_t val)
{
	tg3_writephy(tp, MII_TG3_DSP_ADDRESS, reg);
	tg3_writephy(tp, MII_TG3_DSP_RW_PORT, val);
}

PRIVATE void tg3_phy_toggle_apd(tg3_t * tp, int enable)
{
	u32_t reg;

	if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS) ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906)
		return;

	reg = MII_TG3_MISC_SHDW_WREN |
		MII_TG3_MISC_SHDW_SCR5_SEL |
		MII_TG3_MISC_SHDW_SCR5_LPED |
		MII_TG3_MISC_SHDW_SCR5_DLPTLM |
		MII_TG3_MISC_SHDW_SCR5_SDTL |
		MII_TG3_MISC_SHDW_SCR5_C125OE;
	if (GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5784 || !enable)
		reg |= MII_TG3_MISC_SHDW_SCR5_DLLAPD;

	tg3_writephy(tp, MII_TG3_MISC_SHDW, reg);


	reg = MII_TG3_MISC_SHDW_WREN |
		MII_TG3_MISC_SHDW_APD_SEL |
		MII_TG3_MISC_SHDW_APD_WKTM_84MS;
	if (enable)
		reg |= MII_TG3_MISC_SHDW_APD_ENABLE;

	tg3_writephy(tp, MII_TG3_MISC_SHDW, reg);
}

PRIVATE void tg3_phy_toggle_automdix(tg3_t * tp, int enable)
{
	u32_t phy;

	if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS) ||
	    (tp->tg3_flags2 & TG3_FLG2_ANY_SERDES))
		return;

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) {
		u32_t ephy;

		if (!tg3_readphy(tp, MII_TG3_EPHY_TEST, &ephy)) {
			tg3_writephy(tp, MII_TG3_EPHY_TEST,
				     ephy | MII_TG3_EPHY_SHADOW_EN);
			if (!tg3_readphy(tp, MII_TG3_EPHYTST_MISCCTRL, &phy)) {
				if (enable)
					phy |= MII_TG3_EPHYTST_MISCCTRL_MDIX;
				else
					phy &= ~MII_TG3_EPHYTST_MISCCTRL_MDIX;
				tg3_writephy(tp, MII_TG3_EPHYTST_MISCCTRL, phy);
			}
			tg3_writephy(tp, MII_TG3_EPHY_TEST, ephy);
		}
	} else {
		phy = MII_TG3_AUXCTL_MISC_RDSEL_MISC |
			MII_TG3_AUXCTL_SHDWSEL_MISC;
		if (!tg3_writephy(tp, MII_TG3_AUX_CTRL, phy) &&
		    !tg3_readphy(tp, MII_TG3_AUX_CTRL, &phy)) {
			if (enable)
				phy |= MII_TG3_AUXCTL_MISC_FORCE_AMDIX;
			else
				phy &= ~MII_TG3_AUXCTL_MISC_FORCE_AMDIX;
			phy |= MII_TG3_AUXCTL_MISC_WREN;
			tg3_writephy(tp, MII_TG3_AUX_CTRL, phy);
		}
	}
}

PRIVATE void tg3_phy_set_wirespeed(tg3_t * tp)
{
	u32_t val;

	if (tp->tg3_flags2 & TG3_FLG2_NO_ETH_WIRE_SPEED)
		return;

	if (!tg3_writephy(tp, MII_TG3_AUX_CTRL, 0x7007) &&
	    !tg3_readphy(tp, MII_TG3_AUX_CTRL, &val))
		tg3_writephy(tp, MII_TG3_AUX_CTRL,
			     (val | (1 << 15) | (1 << 4)));
}

PRIVATE void tg3_phy_apply_otp(tg3_t * tp)
{
	u32_t otp, phy;

	if (!tp->phy_otp)
		return;

	otp = tp->phy_otp;

	/* Enable SM_DSP clock and tx 6dB coding. */
	phy = MII_TG3_AUXCTL_SHDWSEL_AUXCTL |
		MII_TG3_AUXCTL_ACTL_SMDSP_ENA |
		MII_TG3_AUXCTL_ACTL_TX_6DB;
	tg3_writephy(tp, MII_TG3_AUX_CTRL, phy);

	phy = ((otp & TG3_OTP_AGCTGT_MASK) >> TG3_OTP_AGCTGT_SHIFT);
	phy |= MII_TG3_DSP_TAP1_AGCTGT_DFLT;
	tg3_phydsp_write(tp, MII_TG3_DSP_TAP1, phy);

	phy = ((otp & TG3_OTP_HPFFLTR_MASK) >> TG3_OTP_HPFFLTR_SHIFT) |
		((otp & TG3_OTP_HPFOVER_MASK) >> TG3_OTP_HPFOVER_SHIFT);
	tg3_phydsp_write(tp, MII_TG3_DSP_AADJ1CH0, phy);

	phy = ((otp & TG3_OTP_LPFDIS_MASK) >> TG3_OTP_LPFDIS_SHIFT);
	phy |= MII_TG3_DSP_AADJ1CH3_ADCCKADJ;
	tg3_phydsp_write(tp, MII_TG3_DSP_AADJ1CH3, phy);

	phy = ((otp & TG3_OTP_VDAC_MASK) >> TG3_OTP_VDAC_SHIFT);
	tg3_phydsp_write(tp, MII_TG3_DSP_EXP75, phy);

	phy = ((otp & TG3_OTP_10BTAMP_MASK) >> TG3_OTP_10BTAMP_SHIFT);
	tg3_phydsp_write(tp, MII_TG3_DSP_EXP96, phy);

	phy = ((otp & TG3_OTP_ROFF_MASK) >> TG3_OTP_ROFF_SHIFT) |
		((otp & TG3_OTP_RCOFF_MASK) >> TG3_OTP_RCOFF_SHIFT);
	tg3_phydsp_write(tp, MII_TG3_DSP_EXP97, phy);

	/* Turn off SM_DSP clock. */
	phy = MII_TG3_AUXCTL_SHDWSEL_AUXCTL |
		MII_TG3_AUXCTL_ACTL_TX_6DB;
	tg3_writephy(tp, MII_TG3_AUX_CTRL, phy);
}

PRIVATE int tg3_wait_macro_done(tg3_t * tp)
{
	int limit = 100;

	while (limit--) {
		u32_t tmp32;

		if (!tg3_readphy(tp, 0x16, &tmp32)) {
			if ((tmp32 & 0x1000) == 0)
				break;
		}
	}
	if (limit < 0)
		return -EBUSY;

	return 0;
}

PRIVATE int tg3_phy_write_and_check_testpat(tg3_t * tp, int *resetp)
{
	static const u32_t test_pat[4][6] = {
	  {0x00005555, 0x00000005, 0x00002aaa, 0x0000000a, 0x00003456, 0x00000003},
	  {0x00002aaa, 0x0000000a, 0x00003333, 0x00000003, 0x0000789a, 0x00000005},
	  {0x00005a5a, 0x00000005, 0x00002a6a, 0x0000000a, 0x00001bcd, 0x00000003},
	  {0x00002a5a, 0x0000000a, 0x000033c3, 0x00000003, 0x00002ef1, 0x00000005}
	};
	int chan;

	for (chan = 0; chan < 4; chan++) {
		int i;

		tg3_writephy(tp, MII_TG3_DSP_ADDRESS,
			     (chan * 0x2000) | 0x0200);
		tg3_writephy(tp, 0x16, 0x0002);

		for (i = 0; i < 6; i++)
			tg3_writephy(tp, MII_TG3_DSP_RW_PORT,
				     test_pat[chan][i]);

		tg3_writephy(tp, 0x16, 0x0202);
		if (tg3_wait_macro_done(tp)) {
			*resetp = 1;
			return -EBUSY;
		}
		tg3_writephy(tp, MII_TG3_DSP_ADDRESS,
			     (chan * 0x2000) | 0x0200);
		tg3_writephy(tp, 0x16, 0x0082);
		if (tg3_wait_macro_done(tp)) {
			*resetp = 1;
			return -EBUSY;
		}
		tg3_writephy(tp, 0x16, 0x0802);
		if (tg3_wait_macro_done(tp)) {
			*resetp = 1;
			return -EBUSY;
		}
		for (i = 0; i < 6; i += 2) {
			u32_t low, high;

			if (tg3_readphy(tp, MII_TG3_DSP_RW_PORT, &low) ||
			    tg3_readphy(tp, MII_TG3_DSP_RW_PORT, &high) ||
			    tg3_wait_macro_done(tp)) {
				*resetp = 1;
				return -EBUSY;
			}
			low &= 0x7fff;
			high &= 0x000f;
			if (low != test_pat[chan][i] ||
			    high != test_pat[chan][i + 1]) {
				tg3_writephy(tp, MII_TG3_DSP_ADDRESS, 0x000b);
				tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x4001);
				tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x4005);

				return -EBUSY;
			}
		}
	}

	return 0;
}

PRIVATE int tg3_phy_reset_chanpat(tg3_t * tp)
{
	int chan;

	for (chan = 0; chan < 4; chan++) {
		int i;

		tg3_writephy(tp, MII_TG3_DSP_ADDRESS,
			     (chan * 0x2000) | 0x0200);
		tg3_writephy(tp, 0x16, 0x0002);
		for (i = 0; i < 6; i++)
			tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x000);
		tg3_writephy(tp, 0x16, 0x0202);
		if (tg3_wait_macro_done(tp))
			return -EBUSY;
	}

	return 0;
}

PRIVATE int tg3_phy_reset_5703_4_5(tg3_t * tp)
{
	u32_t reg32, phy9_orig;
	int retries, do_phy_reset, err;

	retries = 10;
	do_phy_reset = 1;
	do {
		if (do_phy_reset) {
			err = tg3_bmcr_reset(tp);
			if (err)
				return err;
			do_phy_reset = 0;
		}
		/* Disable transmitter and interrupt. */
		if (tg3_readphy(tp, MII_TG3_EXT_CTRL, &reg32))
			continue;

		reg32 |= 0x3000;
		tg3_writephy(tp, MII_TG3_EXT_CTRL, reg32);

		/* Set full-duplex, 1000 mbps.  */
		tg3_writephy(tp, MII_BMCR,
			     BMCR_FULLDPLX | TG3_BMCR_SPEED1000);

		/* Set to master mode.  */
		if (tg3_readphy(tp, MII_TG3_CTRL, &phy9_orig))
			continue;

		tg3_writephy(tp, MII_TG3_CTRL,
			     (MII_TG3_CTRL_AS_MASTER |
			      MII_TG3_CTRL_ENABLE_AS_MASTER));

		/* Enable SM_DSP_CLOCK and 6dB.  */
		tg3_writephy(tp, MII_TG3_AUX_CTRL, 0x0c00);

		/* Block the PHY control access.  */
		tg3_writephy(tp, MII_TG3_DSP_ADDRESS, 0x8005);
		tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x0800);

		err = tg3_phy_write_and_check_testpat(tp, &do_phy_reset);
		if (!err)
			break;
	} while (--retries);

	err = tg3_phy_reset_chanpat(tp);
	if (err)
		return err;

	tg3_writephy(tp, MII_TG3_DSP_ADDRESS, 0x8005);
	tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x0000);

	tg3_writephy(tp, MII_TG3_DSP_ADDRESS, 0x8200);
	tg3_writephy(tp, 0x16, 0x0000);

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5703 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5704) {
		/* Set Extended packet length bit for jumbo frames */
		tg3_writephy(tp, MII_TG3_AUX_CTRL, 0x4400);
	} else {
		tg3_writephy(tp, MII_TG3_AUX_CTRL, 0x0400);
	}

	tg3_writephy(tp, MII_TG3_CTRL, phy9_orig);

	if (!tg3_readphy(tp, MII_TG3_EXT_CTRL, &reg32)) {
		reg32 &= ~0x3000;
		tg3_writephy(tp, MII_TG3_EXT_CTRL, reg32);
	} else if (!err)
		err = -EBUSY;

	return err;
}

/* This will reset the tigon3 PHY if there is no valid
 * link unless the FORCE argument is non-zero.
 */
PRIVATE int tg3_phy_reset(tg3_t * tp)
{
	u32_t cpmuctrl;
	u32_t phy_status;
	int err;

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) {
		u32_t val;

		val = tr32(GRC_MISC_CFG);
		tw32_f(GRC_MISC_CFG, val & ~GRC_MISC_CFG_EPHY_IDDQ);
		micro_delay(40);
	}
	err = tg3_readphy(tp, MII_BMSR, &phy_status);
	err |= tg3_readphy(tp, MII_BMSR, &phy_status);
	if (err != 0)
		return -EBUSY;

	if (tg3_enabled(tp) && carrier_ok(tp)) {
		carrier_off(tp);
		tg3_link_report(tp);
	}
	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5703 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5704 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5705) {
		err = tg3_phy_reset_5703_4_5(tp);
		if (err)
			return err;
		goto out;
	}
	cpmuctrl = 0;
	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5784 &&
	    GET_CHIP_REV(tp->pci_chip_rev_id) != CHIPREV_5784_AX) {
		cpmuctrl = tr32(TG3_CPMU_CTRL);
		if (cpmuctrl & CPMU_CTRL_GPHY_10MB_RXONLY)
			tw32(TG3_CPMU_CTRL,
			     cpmuctrl & ~CPMU_CTRL_GPHY_10MB_RXONLY);
	}
	err = tg3_bmcr_reset(tp);
	if (err)
		return err;

	if (cpmuctrl & CPMU_CTRL_GPHY_10MB_RXONLY) {
		u32_t phy;

		phy = MII_TG3_DSP_EXP8_AEDW | MII_TG3_DSP_EXP8_REJ2MHz;
		tg3_phydsp_write(tp, MII_TG3_DSP_EXP8, phy);

		tw32(TG3_CPMU_CTRL, cpmuctrl);
	}
	if (GET_CHIP_REV(tp->pci_chip_rev_id) == CHIPREV_5784_AX ||
	    GET_CHIP_REV(tp->pci_chip_rev_id) == CHIPREV_5761_AX) {
		u32_t val;

		val = tr32(TG3_CPMU_LSPD_1000MB_CLK);
		if ((val & CPMU_LSPD_1000MB_MACCLK_MASK) ==
		    CPMU_LSPD_1000MB_MACCLK_12_5) {
			val &= ~CPMU_LSPD_1000MB_MACCLK_MASK;
			micro_delay(40);
			tw32_f(TG3_CPMU_LSPD_1000MB_CLK, val);
		}
	}
	tg3_phy_apply_otp(tp);

	if (tp->tg3_flags3 & TG3_FLG3_PHY_ENABLE_APD)
		tg3_phy_toggle_apd(tp, TRUE);
	else
		tg3_phy_toggle_apd(tp, FALSE);

out:
	if (tp->tg3_flags2 & TG3_FLG2_PHY_ADC_BUG) {
		tg3_writephy(tp, MII_TG3_AUX_CTRL, 0x0c00);
		tg3_writephy(tp, MII_TG3_DSP_ADDRESS, 0x201f);
		tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x2aaa);
		tg3_writephy(tp, MII_TG3_DSP_ADDRESS, 0x000a);
		tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x0323);
		tg3_writephy(tp, MII_TG3_AUX_CTRL, 0x0400);
	}
	if (tp->tg3_flags2 & TG3_FLG2_PHY_5704_A0_BUG) {
		tg3_writephy(tp, 0x1c, 0x8d68);
		tg3_writephy(tp, 0x1c, 0x8d68);
	}
	if (tp->tg3_flags2 & TG3_FLG2_PHY_BER_BUG) {
		tg3_writephy(tp, MII_TG3_AUX_CTRL, 0x0c00);
		tg3_writephy(tp, MII_TG3_DSP_ADDRESS, 0x000a);
		tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x310b);
		tg3_writephy(tp, MII_TG3_DSP_ADDRESS, 0x201f);
		tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x9506);
		tg3_writephy(tp, MII_TG3_DSP_ADDRESS, 0x401f);
		tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x14e2);
		tg3_writephy(tp, MII_TG3_AUX_CTRL, 0x0400);
	} else if (tp->tg3_flags2 & TG3_FLG2_PHY_JITTER_BUG) {
		tg3_writephy(tp, MII_TG3_AUX_CTRL, 0x0c00);
		tg3_writephy(tp, MII_TG3_DSP_ADDRESS, 0x000a);
		if (tp->tg3_flags2 & TG3_FLG2_PHY_ADJUST_TRIM) {
			tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x110b);
			tg3_writephy(tp, MII_TG3_TEST1,
				     MII_TG3_TEST1_TRIM_EN | 0x4);
		} else
			tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x010b);
		tg3_writephy(tp, MII_TG3_AUX_CTRL, 0x0400);
	}
	/* Set Extended packet length bit (bit 14) on all chips that support
	 * jumbo frames */
	if ((tp->phy_id & PHY_ID_MASK) == PHY_ID_BCM5401) {
		/* Cannot do read-modify-write on 5401 */
		tg3_writephy(tp, MII_TG3_AUX_CTRL, 0x4c20);
	} else if (tp->tg3_flags2 & TG3_FLG2_JUMBO_CAPABLE) {
		u32_t phy_reg;

		/* Set bit 14 with read-modify-write to preserve other bits */
		if (!tg3_writephy(tp, MII_TG3_AUX_CTRL, 0x0007) &&
		    !tg3_readphy(tp, MII_TG3_AUX_CTRL, &phy_reg))
			tg3_writephy(tp, MII_TG3_AUX_CTRL, phy_reg | 0x4000);
	}
	/* Set phy register 0x10 bit 0 to high fifo elasticity to support jumbo
	 * frames transmission. */
	if (tp->tg3_flags2 & TG3_FLG2_JUMBO_CAPABLE) {
		u32_t phy_reg;

		if (!tg3_readphy(tp, MII_TG3_EXT_CTRL, &phy_reg))
			tg3_writephy(tp, MII_TG3_EXT_CTRL,
				     phy_reg | MII_TG3_EXT_CTRL_FIFO_ELASTIC);
	}
	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) {
		/* adjust output voltage */
		tg3_writephy(tp, MII_TG3_EPHY_PTEST, 0x12);
	}
	tg3_phy_toggle_automdix(tp, 1);
	tg3_phy_set_wirespeed(tp);
	return 0;
}

PRIVATE int tg3_5700_link_polarity(tg3_t * tp, u32_t speed)
{
	if (tp->led_ctrl == LED_CTRL_MODE_PHY_2)
		return 1;
	else if ((tp->phy_id & PHY_ID_MASK) == PHY_ID_BCM5411) {
		if (speed != SPEED_10)
			return 1;
	} else if (speed == SPEED_10)
		return 1;

	return 0;
}

#define RESET_KIND_SHUTDOWN	0
#define RESET_KIND_INIT		1
#define RESET_KIND_SUSPEND	2

PRIVATE int tg3_nvram_lock(tg3_t * tp)
{
	if (tp->tg3_flags & TG3_FLAG_NVRAM) {
		int i;

		if (tp->nvram_lock_cnt == 0) {
			tw32(NVRAM_SWARB, SWARB_REQ_SET1);
			for (i = 0; i < 8000; i++) {
				if (tr32(NVRAM_SWARB) & SWARB_GNT1)
					break;

				micro_delay(20);
			}
			if (i == 8000) {
				tw32(NVRAM_SWARB, SWARB_REQ_CLR1);
				return -ENODEV;
			}
		}
		tp->nvram_lock_cnt++;
	}
	return 0;
}


PRIVATE void tg3_nvram_unlock(tg3_t * tp)
{
	if (tp->tg3_flags & TG3_FLAG_NVRAM) {
		if (tp->nvram_lock_cnt > 0)
			tp->nvram_lock_cnt--;
		if (tp->nvram_lock_cnt == 0)
			tw32_f(NVRAM_SWARB, SWARB_REQ_CLR1);
	}
}

PRIVATE void tg3_enable_nvram_access(tg3_t * tp)
{
	if ((tp->tg3_flags2 & TG3_FLG2_5750_PLUS) &&
	    !(tp->tg3_flags2 & TG3_FLG2_PROTECTED_NVRAM)) {
		u32_t nvaccess = tr32(NVRAM_ACCESS);

		tw32(NVRAM_ACCESS, nvaccess | ACCESS_ENABLE);
	}
}

PRIVATE void tg3_disable_nvram_access(tg3_t * tp)
{
	if ((tp->tg3_flags2 & TG3_FLG2_5750_PLUS) &&
	    !(tp->tg3_flags2 & TG3_FLG2_PROTECTED_NVRAM)) {
		u32_t nvaccess = tr32(NVRAM_ACCESS);

		tw32(NVRAM_ACCESS, nvaccess & ~ACCESS_ENABLE);
	}
}

PRIVATE int tg3_nvram_read_using_eeprom(tg3_t * tp,
					 u32_t offset, u32_t * val)
{
	u32_t tmp;
	int i;

	if (offset > EEPROM_ADDR_ADDR_MASK || (offset % 4) != 0)
		return -EINVAL;

	tmp = tr32(GRC_EEPROM_ADDR) & ~(EEPROM_ADDR_ADDR_MASK |
					EEPROM_ADDR_DEVID_MASK |
					EEPROM_ADDR_READ);
	tw32(GRC_EEPROM_ADDR,
	     tmp |
	     (0 << EEPROM_ADDR_DEVID_SHIFT) |
	     ((offset << EEPROM_ADDR_ADDR_SHIFT) &
	      EEPROM_ADDR_ADDR_MASK) |
	     EEPROM_ADDR_READ | EEPROM_ADDR_START);

	for (i = 0; i < 1000; i++) {
		tmp = tr32(GRC_EEPROM_ADDR);

		if (tmp & EEPROM_ADDR_COMPLETE)
			break;
		micro_delay(1000);
	}
	if (!(tmp & EEPROM_ADDR_COMPLETE))
		return -EBUSY;

	tmp = tr32(GRC_EEPROM_DATA);


	/* The data will always be opposite the native endian format. Perform a
	 * blind byteswap to compensate. */
	*val = swab32(tmp);

	return 0;
}

#define NVRAM_CMD_TIMEOUT 10000

PRIVATE int tg3_nvram_exec_cmd(tg3_t * tp, u32_t nvram_cmd)
{
	int i;

	tw32(NVRAM_CMD, nvram_cmd);
	for (i = 0; i < NVRAM_CMD_TIMEOUT; i++) {
		micro_delay(10);
		if (tr32(NVRAM_CMD) & NVRAM_CMD_DONE) {
			micro_delay(10);
			break;
		}
	}

	if (i == NVRAM_CMD_TIMEOUT)
		return -EBUSY;

	return 0;
}

PRIVATE u32_t tg3_nvram_phys_addr(tg3_t * tp, u32_t addr)
{
	if ((tp->tg3_flags & TG3_FLAG_NVRAM) &&
	    (tp->tg3_flags & TG3_FLAG_NVRAM_BUFFERED) &&
	    (tp->tg3_flags2 & TG3_FLG2_FLASH) &&
	    !(tp->tg3_flags3 & TG3_FLG3_NO_NVRAM_ADDR_TRANS) &&
	    (tp->nvram_jedecnum == JEDEC_ATMEL))
		addr = ((addr / tp->nvram_pagesize) <<
			ATMEL_AT45DB0X1B_PAGE_POS) +
		(addr % tp->nvram_pagesize);

	return addr;
}

PRIVATE u32_t tg3_nvram_logical_addr(tg3_t * tp, u32_t addr)
{
	if ((tp->tg3_flags & TG3_FLAG_NVRAM) &&
	    (tp->tg3_flags & TG3_FLAG_NVRAM_BUFFERED) &&
	    (tp->tg3_flags2 & TG3_FLG2_FLASH) &&
	    !(tp->tg3_flags3 & TG3_FLG3_NO_NVRAM_ADDR_TRANS) &&
	    (tp->nvram_jedecnum == JEDEC_ATMEL))
		addr = ((addr >> ATMEL_AT45DB0X1B_PAGE_POS) *
			tp->nvram_pagesize) +
		(addr & ((1 << ATMEL_AT45DB0X1B_PAGE_POS) - 1));

	return addr;
}

/* NOTE: Data read in from NVRAM is byteswapped according to
 * the byteswapping settings for all other register accesses.
 * tg3 devices are BE devices, so on a BE machine, the data
 * returned will be exactly as it is seen in NVRAM.  On a LE
 * machine, the 32-bit value will be byteswapped.
 */
PRIVATE int tg3_nvram_read(tg3_t * tp, u32_t offset, u32_t * val)
{
	int ret;

	if (!(tp->tg3_flags & TG3_FLAG_NVRAM))
		return tg3_nvram_read_using_eeprom(tp, offset, val);

	offset = tg3_nvram_phys_addr(tp, offset);

	if (offset > NVRAM_ADDR_MSK)
		return -EINVAL;

	ret = tg3_nvram_lock(tp);
	if (ret)
		return ret;

	tg3_enable_nvram_access(tp);

	tw32(NVRAM_ADDR, offset);
	ret = tg3_nvram_exec_cmd(tp, NVRAM_CMD_RD | NVRAM_CMD_GO |
			   NVRAM_CMD_FIRST | NVRAM_CMD_LAST | NVRAM_CMD_DONE);

	if (ret == 0)
		*val = tr32(NVRAM_RDDATA);

	tg3_disable_nvram_access(tp);

	tg3_nvram_unlock(tp);

	return ret;
}

/* Ensures NVRAM data is in bytestream format. */
PRIVATE int tg3_nvram_read_be32(tg3_t * tp, u32_t offset, u32_t * val)
{
	u32_t v;
	int res = tg3_nvram_read(tp, offset, &v);
	if (!res)
		*val = cpu_to_be32(v);
	return res;
}

PRIVATE void __tg3_set_mac_addr(tg3_t * tp, int skip_mac_1)
{

	u32_t addr_high, addr_low;
	int i;

	addr_high = ((tp->mac_address.ea_addr[0] << 8) |
		     tp->mac_address.ea_addr[1]);
	addr_low = ((tp->mac_address.ea_addr[2] << 24) |
		    (tp->mac_address.ea_addr[3] << 16) |
		    (tp->mac_address.ea_addr[4] << 8) |
		    (tp->mac_address.ea_addr[5] << 0));
	for (i = 0; i < 4; i++) {
		if (i == 1 && skip_mac_1)
			continue;
		tw32(MAC_ADDR_0_HIGH + (i * 8), addr_high);
		tw32(MAC_ADDR_0_LOW + (i * 8), addr_low);
	}

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5703 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5704) {
		for (i = 0; i < 12; i++) {
			tw32(MAC_EXTADDR_0_HIGH + (i * 8), addr_high);
			tw32(MAC_EXTADDR_0_LOW + (i * 8), addr_low);
		}
	}
	addr_high = (tp->mac_address.ea_addr[0] +
		     tp->mac_address.ea_addr[1] +
		     tp->mac_address.ea_addr[2] +
		     tp->mac_address.ea_addr[3] +
		     tp->mac_address.ea_addr[4] +
		     tp->mac_address.ea_addr[5]) &
		TX_BACKOFF_SEED_MASK;
	tw32(MAC_TX_BACKOFF_SEED, addr_high);
}

PRIVATE int tg3_set_power_state(tg3_t * tp, unsigned int state)
{
	u32_t misc_host_ctrl;

	/* Make sure register accesses (indirect or otherwise) will function
	 * correctly. */

	pci_attr_w32(tp->devind,
		     TG3PCI_MISC_HOST_CTRL,
		     tp->misc_host_ctrl);

	switch (state) {
	case PCI_D0:
		/* Switch out of Vaux if it is a NIC */
		if (tp->tg3_flags2 & TG3_FLG2_IS_NIC)
			tw32_wait_f(GRC_LOCAL_CTRL, tp->grc_local_ctrl, 100);

		return 0;

	case PCI_D1:
	case PCI_D2:
	case PCI_D3hot:
		break;

	default:
		printf("%s: Invalid power state (D%d) requested\n",
		       tp->name, state);
		return -EINVAL;
	}

	/* Restore the CLKREQ setting. */
	if (tp->tg3_flags3 & TG3_FLG3_CLKREQ_BUG) {
		u16_t lnkctl;

		lnkctl = pci_attr_r16(tp->devind,
				      tp->cap.pcie_cap + PCI_EXP_LNKCTL);
		lnkctl |= PCI_EXP_LNKCTL_CLKREQ_EN;
		pci_attr_w16(tp->devind,
			     tp->cap.pcie_cap + PCI_EXP_LNKCTL,
			     lnkctl);
	}
	misc_host_ctrl = tr32(TG3PCI_MISC_HOST_CTRL);
	tw32(TG3PCI_MISC_HOST_CTRL,
	     misc_host_ctrl | MISC_HOST_CTRL_MASK_PCI_INT);

	return 0;
}

PRIVATE void tg3_aux_stat_to_speed_duplex(tg3_t * tp, u32_t val, u16_t * speed,
			u8_t * duplex)
{
	switch (val & MII_TG3_AUX_STAT_SPDMASK) {
		case MII_TG3_AUX_STAT_10HALF:
		*speed = SPEED_10;
		*duplex = DUPLEX_HALF;
		break;

	case MII_TG3_AUX_STAT_10FULL:
		*speed = SPEED_10;
		*duplex = DUPLEX_FULL;
		break;

	case MII_TG3_AUX_STAT_100HALF:
		*speed = SPEED_100;
		*duplex = DUPLEX_HALF;
		break;

	case MII_TG3_AUX_STAT_100FULL:
		*speed = SPEED_100;
		*duplex = DUPLEX_FULL;
		break;

	case MII_TG3_AUX_STAT_1000HALF:
		*speed = SPEED_1000;
		*duplex = DUPLEX_HALF;
		break;

	case MII_TG3_AUX_STAT_1000FULL:
		*speed = SPEED_1000;
		*duplex = DUPLEX_FULL;
		break;

	default:
		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) {
			*speed = (val & MII_TG3_AUX_STAT_100) ? SPEED_100 :
				SPEED_10;
			*duplex = (val & MII_TG3_AUX_STAT_FULL) ? DUPLEX_FULL :
				DUPLEX_HALF;
			break;
		}
		*speed = SPEED_INVALID;
		*duplex = DUPLEX_INVALID;
		break;
	}
}

PRIVATE void tg3_phy_copper_begin(tg3_t * tp)
{
	u32_t new_adv;
	int i;

	if (tp->link_config.phy_is_low_power) {
		/* Entering low power mode.  Disable gigabit and 100baseT
		 * advertisements. */
		tg3_writephy(tp, MII_TG3_CTRL, 0);

		new_adv = (ADVERTISE_10HALF | ADVERTISE_10FULL |
			   ADVERTISE_CSMA | ADVERTISE_PAUSE_CAP);
		if (tp->tg3_flags & TG3_FLAG_WOL_SPEED_100MB)
			new_adv |= (ADVERTISE_100HALF | ADVERTISE_100FULL);

		tg3_writephy(tp, MII_ADVERTISE, new_adv);
	} else if (tp->link_config.speed == SPEED_INVALID) {
		if (tp->tg3_flags & TG3_FLAG_10_100_ONLY)
			tp->link_config.advertising &=
				~(ADVERTISED_1000baseT_Half |
				  ADVERTISED_1000baseT_Full);

		new_adv = ADVERTISE_CSMA;
		if (tp->link_config.advertising & ADVERTISED_10baseT_Half)
			new_adv |= ADVERTISE_10HALF;
		if (tp->link_config.advertising & ADVERTISED_10baseT_Full)
			new_adv |= ADVERTISE_10FULL;
		if (tp->link_config.advertising & ADVERTISED_100baseT_Half)
			new_adv |= ADVERTISE_100HALF;
		if (tp->link_config.advertising & ADVERTISED_100baseT_Full)
			new_adv |= ADVERTISE_100FULL;

		new_adv |= tg3_advert_flowctrl_1000T(tp->link_config.flowctrl);

		tg3_writephy(tp, MII_ADVERTISE, new_adv);

		if (tp->link_config.advertising &
		    (ADVERTISED_1000baseT_Half | ADVERTISED_1000baseT_Full)) {
			new_adv = 0;
			if (tp->link_config.advertising & ADVERTISED_1000baseT_Half)
				new_adv |= MII_TG3_CTRL_ADV_1000_HALF;
			if (tp->link_config.advertising & ADVERTISED_1000baseT_Full)
				new_adv |= MII_TG3_CTRL_ADV_1000_FULL;
			if (!(tp->tg3_flags & TG3_FLAG_10_100_ONLY) &&
			    (tp->pci_chip_rev_id == CHIPREV_ID_5701_A0 ||
			     tp->pci_chip_rev_id == CHIPREV_ID_5701_B0))
				new_adv |= (MII_TG3_CTRL_AS_MASTER |
					    MII_TG3_CTRL_ENABLE_AS_MASTER);
			tg3_writephy(tp, MII_TG3_CTRL, new_adv);
		} else {
			tg3_writephy(tp, MII_TG3_CTRL, 0);
		}
	} else {
		new_adv = tg3_advert_flowctrl_1000T(tp->link_config.flowctrl);
		new_adv |= ADVERTISE_CSMA;

		/* Asking for a specific link mode. */
		if (tp->link_config.speed == SPEED_1000) {
			tg3_writephy(tp, MII_ADVERTISE, new_adv);

			if (tp->link_config.duplex == DUPLEX_FULL)
				new_adv = MII_TG3_CTRL_ADV_1000_FULL;
			else
				new_adv = MII_TG3_CTRL_ADV_1000_HALF;
			if (tp->pci_chip_rev_id == CHIPREV_ID_5701_A0 ||
			    tp->pci_chip_rev_id == CHIPREV_ID_5701_B0)
				new_adv |= (MII_TG3_CTRL_AS_MASTER |
					    MII_TG3_CTRL_ENABLE_AS_MASTER);
		} else {
			if (tp->link_config.speed == SPEED_100) {
				if (tp->link_config.duplex == DUPLEX_FULL)
					new_adv |= ADVERTISE_100FULL;
				else
					new_adv |= ADVERTISE_100HALF;
			} else {
				if (tp->link_config.duplex == DUPLEX_FULL)
					new_adv |= ADVERTISE_10FULL;
				else
					new_adv |= ADVERTISE_10HALF;
			}
			tg3_writephy(tp, MII_ADVERTISE, new_adv);

			new_adv = 0;
		}

		tg3_writephy(tp, MII_TG3_CTRL, new_adv);
	}

	if (tp->link_config.autoneg == AUTONEG_DISABLE &&
	    tp->link_config.speed != SPEED_INVALID) {
		u32_t bmcr, orig_bmcr;

		tp->link_config.active_speed = tp->link_config.speed;
		tp->link_config.active_duplex = tp->link_config.duplex;

		bmcr = 0;
		switch (tp->link_config.speed) {
		default:
		case SPEED_10:
			break;

		case SPEED_100:
			bmcr |= BMCR_SPEED100;
			break;

		case SPEED_1000:
			bmcr |= TG3_BMCR_SPEED1000;
			break;
		}

		if (tp->link_config.duplex == DUPLEX_FULL)
			bmcr |= BMCR_FULLDPLX;

		if (!tg3_readphy(tp, MII_BMCR, &orig_bmcr) &&
		    (bmcr != orig_bmcr)) {
			tg3_writephy(tp, MII_BMCR, BMCR_LOOPBACK);
			for (i = 0; i < 1500; i++) {
				u32_t tmp;

				micro_delay(10);
				if (tg3_readphy(tp, MII_BMSR, &tmp) ||
				    tg3_readphy(tp, MII_BMSR, &tmp))
					continue;
				if (!(tmp & BMSR_LSTATUS)) {
					micro_delay(40);
					break;
				}
			}
			tg3_writephy(tp, MII_BMCR, bmcr);
			micro_delay(40);
		}
	} else {
		tg3_writephy(tp, MII_BMCR,
			     BMCR_ANENABLE | BMCR_ANRESTART);
	}
}

PRIVATE int tg3_init_5401phy_dsp(tg3_t * tp)
{
	int err;

	/* Turn off tap power management. */
	/* Set Extended packet length bit */
	err = tg3_writephy(tp, MII_TG3_AUX_CTRL, 0x4c20);

	err |= tg3_writephy(tp, MII_TG3_DSP_ADDRESS, 0x0012);
	err |= tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x1804);

	err |= tg3_writephy(tp, MII_TG3_DSP_ADDRESS, 0x0013);
	err |= tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x1204);

	err |= tg3_writephy(tp, MII_TG3_DSP_ADDRESS, 0x8006);
	err |= tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x0132);

	err |= tg3_writephy(tp, MII_TG3_DSP_ADDRESS, 0x8006);
	err |= tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x0232);

	err |= tg3_writephy(tp, MII_TG3_DSP_ADDRESS, 0x201f);
	err |= tg3_writephy(tp, MII_TG3_DSP_RW_PORT, 0x0a20);

	micro_delay(40);

	return err;
}

PRIVATE int tg3_copper_is_advertising_all(tg3_t * tp, u32_t mask)
{
	u32_t adv_reg, all_mask = 0;

	if (mask & ADVERTISED_10baseT_Half)
		all_mask |= ADVERTISE_10HALF;
	if (mask & ADVERTISED_10baseT_Full)
		all_mask |= ADVERTISE_10FULL;
	if (mask & ADVERTISED_100baseT_Half)
		all_mask |= ADVERTISE_100HALF;
	if (mask & ADVERTISED_100baseT_Full)
		all_mask |= ADVERTISE_100FULL;

	if (tg3_readphy(tp, MII_ADVERTISE, &adv_reg))
		return 0;

	if ((adv_reg & all_mask) != all_mask)
		return 0;
	if (!(tp->tg3_flags & TG3_FLAG_10_100_ONLY)) {
		u32_t tg3_ctrl;

		all_mask = 0;
		if (mask & ADVERTISED_1000baseT_Half)
			all_mask |= ADVERTISE_1000HALF;
		if (mask & ADVERTISED_1000baseT_Full)
			all_mask |= ADVERTISE_1000FULL;

		if (tg3_readphy(tp, MII_TG3_CTRL, &tg3_ctrl))
			return 0;

		if ((tg3_ctrl & all_mask) != all_mask)
			return 0;
	}
	return 1;
}

PRIVATE int tg3_adv_1000T_flowctrl_ok(tg3_t * tp, u32_t * lcladv,
			u32_t * rmtadv)
{
	u32_t curadv, reqadv;

	if (tg3_readphy(tp, MII_ADVERTISE, lcladv))
		return 1;

	curadv = *lcladv & (ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM);
	reqadv = tg3_advert_flowctrl_1000T(tp->link_config.flowctrl);

	if (tp->link_config.active_duplex == DUPLEX_FULL) {
		if (curadv != reqadv)
			return 0;

		if (tp->tg3_flags & TG3_FLAG_PAUSE_AUTONEG)
			tg3_readphy(tp, MII_LPA, rmtadv);
	} else {
		/* Reprogram the advertisement register, even if it does not
		 * affect the current link.  If the link gets renegotiated in
		 * the future, we can save an additional renegotiation cycle by
		 * advertising it correctly in the first place. */
		if (curadv != reqadv) {
			*lcladv &= ~(ADVERTISE_PAUSE_CAP |
				     ADVERTISE_PAUSE_ASYM);
			tg3_writephy(tp, MII_ADVERTISE, *lcladv | reqadv);
		}
	}

	return 1;
}

PRIVATE int tg3_setup_copper_phy(tg3_t * tp, int force_reset)
{
	int current_link_up;
	u32_t bmsr, dummy;
	u32_t lcl_adv, rmt_adv;
	u16_t current_speed;
	u8_t current_duplex;
	int i, err;

	tw32(MAC_EVENT, 0);

	tw32_f(MAC_STATUS,
	       (MAC_STATUS_SYNC_CHANGED |
		MAC_STATUS_CFG_CHANGED |
		MAC_STATUS_MI_COMPLETION |
		MAC_STATUS_LNKSTATE_CHANGED));
	micro_delay(40);

	if ((tp->mi_mode & MAC_MI_MODE_AUTO_POLL) != 0) {
		tw32_f(MAC_MI_MODE,
		       (tp->mi_mode & ~MAC_MI_MODE_AUTO_POLL));
		micro_delay(80);
	}
	tg3_writephy(tp, MII_TG3_AUX_CTRL, 0x02);

	/* Some third-party PHYs need to be reset on link going down. */
	if ((GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5703 ||
	     GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5704 ||
	     GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5705) &&
	    carrier_ok(tp)) {
		tg3_readphy(tp, MII_BMSR, &bmsr);
		if (!tg3_readphy(tp, MII_BMSR, &bmsr) &&
		    !(bmsr & BMSR_LSTATUS))
			force_reset = 1;
	}
	if (force_reset)
		tg3_phy_reset(tp);

	if ((tp->phy_id & PHY_ID_MASK) == PHY_ID_BCM5401) {
		tg3_readphy(tp, MII_BMSR, &bmsr);
		if (tg3_readphy(tp, MII_BMSR, &bmsr) ||
		    !(tp->tg3_flags & TG3_FLAG_INIT_COMPLETE))
			bmsr = 0;

		if (!(bmsr & BMSR_LSTATUS)) {
			err = tg3_init_5401phy_dsp(tp);
			if (err)
				return err;

			tg3_readphy(tp, MII_BMSR, &bmsr);
			for (i = 0; i < 1000; i++) {
				micro_delay(10);
				if (!tg3_readphy(tp, MII_BMSR, &bmsr) &&
				    (bmsr & BMSR_LSTATUS)) {
					micro_delay(40);
					break;
				}
			}

			if ((tp->phy_id & PHY_ID_REV_MASK) == PHY_REV_BCM5401_B0 &&
			    !(bmsr & BMSR_LSTATUS) &&
			    tp->link_config.active_speed == SPEED_1000) {
				err = tg3_phy_reset(tp);
				if (!err)
					err = tg3_init_5401phy_dsp(tp);
				if (err)
					return err;
			}
		}
	} else if (tp->pci_chip_rev_id == CHIPREV_ID_5701_A0 ||
		   tp->pci_chip_rev_id == CHIPREV_ID_5701_B0) {
		/* 5701 {A0,B0} CRC bug workaround */
		tg3_writephy(tp, 0x15, 0x0a75);
		tg3_writephy(tp, 0x1c, 0x8c68);
		tg3_writephy(tp, 0x1c, 0x8d68);
		tg3_writephy(tp, 0x1c, 0x8c68);
	}
	/* Clear pending interrupts... */
	tg3_readphy(tp, MII_TG3_ISTAT, &dummy);
	tg3_readphy(tp, MII_TG3_ISTAT, &dummy);

	if (tp->tg3_flags & TG3_FLAG_USE_MI_INTERRUPT)
		tg3_writephy(tp, MII_TG3_IMASK, ~MII_TG3_INT_LINKCHG);
	else if (GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5906)
		tg3_writephy(tp, MII_TG3_IMASK, ~0);

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5700 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5701) {
		if (tp->led_ctrl == LED_CTRL_MODE_PHY_1)
			tg3_writephy(tp, MII_TG3_EXT_CTRL,
				     MII_TG3_EXT_CTRL_LNK3_LED_MODE);
		else
			tg3_writephy(tp, MII_TG3_EXT_CTRL, 0);
	}
	current_link_up = 0;
	current_speed = SPEED_INVALID;
	current_duplex = DUPLEX_INVALID;

	if (tp->tg3_flags2 & TG3_FLG2_CAPACITIVE_COUPLING) {
		u32_t val;

		tg3_writephy(tp, MII_TG3_AUX_CTRL, 0x4007);
		tg3_readphy(tp, MII_TG3_AUX_CTRL, &val);
		if (!(val & (1 << 10))) {
			val |= (1 << 10);
			tg3_writephy(tp, MII_TG3_AUX_CTRL, val);
			goto relink;
		}
	}
	bmsr = 0;
	for (i = 0; i < 100; i++) {
		tg3_readphy(tp, MII_BMSR, &bmsr);
		if (!tg3_readphy(tp, MII_BMSR, &bmsr) &&
		    (bmsr & BMSR_LSTATUS))
			break;
		micro_delay(40);
	}

	if (bmsr & BMSR_LSTATUS) {
		u32_t aux_stat, bmcr;

		tg3_readphy(tp, MII_TG3_AUX_STAT, &aux_stat);
		for (i = 0; i < 2000; i++) {
			micro_delay(10);
			if (!tg3_readphy(tp, MII_TG3_AUX_STAT, &aux_stat) &&
			    aux_stat)
				break;
		}

		tg3_aux_stat_to_speed_duplex(tp, aux_stat,
					     &current_speed,
					     &current_duplex);

		bmcr = 0;
		for (i = 0; i < 200; i++) {
			tg3_readphy(tp, MII_BMCR, &bmcr);
			if (tg3_readphy(tp, MII_BMCR, &bmcr))
				continue;
			if (bmcr && bmcr != 0x7fff)
				break;
			micro_delay(10);
		}

		lcl_adv = 0;
		rmt_adv = 0;

		tp->link_config.active_speed = current_speed;
		tp->link_config.active_duplex = current_duplex;

		if (tp->link_config.autoneg == AUTONEG_ENABLE) {
			if ((bmcr & BMCR_ANENABLE) &&
			    tg3_copper_is_advertising_all(tp,
					       tp->link_config.advertising)) {
				if (tg3_adv_1000T_flowctrl_ok(tp, &lcl_adv,
							      &rmt_adv))
					current_link_up = 1;
			}
		} else {
			if (!(bmcr & BMCR_ANENABLE) &&
			    tp->link_config.speed == current_speed &&
			    tp->link_config.duplex == current_duplex &&
			    tp->link_config.flowctrl ==
			    tp->link_config.active_flowctrl) {
				current_link_up = 1;
			}
		}

		if (current_link_up == 1 &&
		    tp->link_config.active_duplex == DUPLEX_FULL)
			tg3_setup_flow_control(tp, lcl_adv, rmt_adv);
	}
relink:
	if (current_link_up == 0 || tp->link_config.phy_is_low_power) {
		u32_t tmp;

		tg3_phy_copper_begin(tp);

		tg3_readphy(tp, MII_BMSR, &tmp);
		if (!tg3_readphy(tp, MII_BMSR, &tmp) &&
		    (tmp & BMSR_LSTATUS))
			current_link_up = 1;
	}
	tp->mac_mode &= ~MAC_MODE_PORT_MODE_MASK;
	if (current_link_up == 1) {
		if (tp->link_config.active_speed == SPEED_100 ||
		    tp->link_config.active_speed == SPEED_10)
			tp->mac_mode |= MAC_MODE_PORT_MODE_MII;
		else
			tp->mac_mode |= MAC_MODE_PORT_MODE_GMII;
	} else
		tp->mac_mode |= MAC_MODE_PORT_MODE_GMII;

	tp->mac_mode &= ~MAC_MODE_HALF_DUPLEX;
	if (tp->link_config.active_duplex == DUPLEX_HALF)
		tp->mac_mode |= MAC_MODE_HALF_DUPLEX;

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5700) {
		if (current_link_up == 1 &&
		    tg3_5700_link_polarity(tp, tp->link_config.active_speed))
			tp->mac_mode |= MAC_MODE_LINK_POLARITY;
		else
			tp->mac_mode &= ~MAC_MODE_LINK_POLARITY;
	}
	/* ??? Without this setting Netgear GA302T PHY does not ???
	 * send/receive packets... */
	if ((tp->phy_id & PHY_ID_MASK) == PHY_ID_BCM5411 &&
	    tp->pci_chip_rev_id == CHIPREV_ID_5700_ALTIMA) {
		tp->mi_mode |= MAC_MI_MODE_AUTO_POLL;
		tw32_f(MAC_MI_MODE, tp->mi_mode);
		micro_delay(80);
	}
	tw32_f(MAC_MODE, tp->mac_mode);
	micro_delay(40);

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5785) {
		if (tp->link_config.active_speed == SPEED_10)
			tw32(MAC_MI_STAT,
			     MAC_MI_STAT_10MBPS_MODE |
			     MAC_MI_STAT_LNKSTAT_ATTN_ENAB);
		else
			tw32(MAC_MI_STAT, MAC_MI_STAT_LNKSTAT_ATTN_ENAB);
	}
	if (tp->tg3_flags & TG3_FLAG_USE_LINKCHG_REG) {
		/* Polled via timer. */
		tw32_f(MAC_EVENT, 0);
	} else {
		tw32_f(MAC_EVENT, MAC_EVENT_LNKSTATE_CHANGED);
	}
	micro_delay(40);

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5700 &&
	    current_link_up == 1 &&
	    tp->link_config.active_speed == SPEED_1000 &&
	    ((tp->tg3_flags & TG3_FLAG_PCIX_MODE) ||
	     (tp->tg3_flags & TG3_FLAG_PCI_HIGH_SPEED))) {
		micro_delay(120);
		tw32_f(MAC_STATUS,
		       (MAC_STATUS_SYNC_CHANGED |
			MAC_STATUS_CFG_CHANGED));
		micro_delay(40);
		tg3_write_mem(tp,
			      NIC_SRAM_FIRMWARE_MBOX,
			      NIC_SRAM_FIRMWARE_MBOX_MAGIC2);
	}
	/* Prevent send BD corruption. */
	if (tp->tg3_flags3 & TG3_FLG3_CLKREQ_BUG) {
		u16_t oldlnkctl, newlnkctl;

		oldlnkctl = pci_attr_r16(tp->devind,
					 tp->cap.pcie_cap + PCI_EXP_LNKCTL);
		if (tp->link_config.active_speed == SPEED_100 ||
		    tp->link_config.active_speed == SPEED_10)
			newlnkctl = oldlnkctl & ~PCI_EXP_LNKCTL_CLKREQ_EN;
		else
			newlnkctl = oldlnkctl | PCI_EXP_LNKCTL_CLKREQ_EN;
		if (newlnkctl != oldlnkctl)
			pci_attr_w16(tp->devind, tp->cap.pcie_cap + PCI_EXP_LNKCTL,
				     newlnkctl);
	}
	if (current_link_up != carrier_ok(tp)) {
		if (current_link_up)
			carrier_on(tp);
		else
			carrier_off(tp);
		tg3_link_report(tp);
	}
	return 0;
}

PRIVATE int tg3_fiber_aneg_smachine(tg3_t * tp,
				     struct tg3_fiber_aneginfo * ap)
{
	u16_t flowctrl;
	unsigned long delta;
	u32_t rx_cfg_reg;
	int ret;

	if (ap->state == ANEG_STATE_UNKNOWN) {
		ap->rxconfig = 0;
		ap->link_time = 0;
		ap->cur_time = 0;
		ap->ability_match_cfg = 0;
		ap->ability_match_count = 0;
		ap->ability_match = 0;
		ap->idle_match = 0;
		ap->ack_match = 0;
	}
	ap->cur_time++;

	if (tr32(MAC_STATUS) & MAC_STATUS_RCVD_CFG) {
		rx_cfg_reg = tr32(MAC_RX_AUTO_NEG);

		if (rx_cfg_reg != ap->ability_match_cfg) {
			ap->ability_match_cfg = rx_cfg_reg;
			ap->ability_match = 0;
			ap->ability_match_count = 0;
		} else {
			if (++ap->ability_match_count > 1) {
				ap->ability_match = 1;
				ap->ability_match_cfg = rx_cfg_reg;
			}
		}
		if (rx_cfg_reg & ANEG_CFG_ACK)
			ap->ack_match = 1;
		else
			ap->ack_match = 0;

		ap->idle_match = 0;
	} else {
		ap->idle_match = 1;
		ap->ability_match_cfg = 0;
		ap->ability_match_count = 0;
		ap->ability_match = 0;
		ap->ack_match = 0;

		rx_cfg_reg = 0;
	}

	ap->rxconfig = rx_cfg_reg;
	ret = ANEG_OK;

	switch (ap->state) {
	case ANEG_STATE_UNKNOWN:
		if (ap->flags & (MR_AN_ENABLE | MR_RESTART_AN))
			ap->state = ANEG_STATE_AN_ENABLE;

		/* fallthru */
	case ANEG_STATE_AN_ENABLE:
		ap->flags &= ~(MR_AN_COMPLETE | MR_PAGE_RX);
		if (ap->flags & MR_AN_ENABLE) {
			ap->link_time = 0;
			ap->cur_time = 0;
			ap->ability_match_cfg = 0;
			ap->ability_match_count = 0;
			ap->ability_match = 0;
			ap->idle_match = 0;
			ap->ack_match = 0;

			ap->state = ANEG_STATE_RESTART_INIT;
		} else {
			ap->state = ANEG_STATE_DISABLE_LINK_OK;
		}
		break;

	case ANEG_STATE_RESTART_INIT:
		ap->link_time = ap->cur_time;
		ap->flags &= ~(MR_NP_LOADED);
		ap->txconfig = 0;
		tw32(MAC_TX_AUTO_NEG, 0);
		tp->mac_mode |= MAC_MODE_SEND_CONFIGS;
		tw32_f(MAC_MODE, tp->mac_mode);
		micro_delay(40);

		ret = ANEG_TIMER_ENAB;
		ap->state = ANEG_STATE_RESTART;

		/* fallthru */
	case ANEG_STATE_RESTART:
		delta = ap->cur_time - ap->link_time;
		if (delta > ANEG_STATE_SETTLE_TIME) {
			ap->state = ANEG_STATE_ABILITY_DETECT_INIT;
		} else {
			ret = ANEG_TIMER_ENAB;
		}
		break;

	case ANEG_STATE_DISABLE_LINK_OK:
		ret = ANEG_DONE;
		break;

	case ANEG_STATE_ABILITY_DETECT_INIT:
		ap->flags &= ~(MR_TOGGLE_TX);
		ap->txconfig = ANEG_CFG_FD;
		flowctrl = tg3_advert_flowctrl_1000X(tp->link_config.flowctrl);
		if (flowctrl & ADVERTISE_1000XPAUSE)
			ap->txconfig |= ANEG_CFG_PS1;
		if (flowctrl & ADVERTISE_1000XPSE_ASYM)
			ap->txconfig |= ANEG_CFG_PS2;
		tw32(MAC_TX_AUTO_NEG, ap->txconfig);
		tp->mac_mode |= MAC_MODE_SEND_CONFIGS;
		tw32_f(MAC_MODE, tp->mac_mode);
		micro_delay(40);

		ap->state = ANEG_STATE_ABILITY_DETECT;
		break;

	case ANEG_STATE_ABILITY_DETECT:
		if (ap->ability_match != 0 && ap->rxconfig != 0) {
			ap->state = ANEG_STATE_ACK_DETECT_INIT;
		}
		break;

	case ANEG_STATE_ACK_DETECT_INIT:
		ap->txconfig |= ANEG_CFG_ACK;
		tw32(MAC_TX_AUTO_NEG, ap->txconfig);
		tp->mac_mode |= MAC_MODE_SEND_CONFIGS;
		tw32_f(MAC_MODE, tp->mac_mode);
		micro_delay(40);

		ap->state = ANEG_STATE_ACK_DETECT;

		/* fallthru */
	case ANEG_STATE_ACK_DETECT:
		if (ap->ack_match != 0) {
			if ((ap->rxconfig & ~ANEG_CFG_ACK) ==
			    (ap->ability_match_cfg & ~ANEG_CFG_ACK)) {
				ap->state = ANEG_STATE_COMPLETE_ACK_INIT;
			} else {
				ap->state = ANEG_STATE_AN_ENABLE;
			}
		} else if (ap->ability_match != 0 &&
			   ap->rxconfig == 0) {
			ap->state = ANEG_STATE_AN_ENABLE;
		}
		break;

	case ANEG_STATE_COMPLETE_ACK_INIT:
		if (ap->rxconfig & ANEG_CFG_INVAL) {
			ret = ANEG_FAILED;
			break;
		}
		ap->flags &= ~(MR_LP_ADV_FULL_DUPLEX |
			       MR_LP_ADV_HALF_DUPLEX |
			       MR_LP_ADV_SYM_PAUSE |
			       MR_LP_ADV_ASYM_PAUSE |
			       MR_LP_ADV_REMOTE_FAULT1 |
			       MR_LP_ADV_REMOTE_FAULT2 |
			       MR_LP_ADV_NEXT_PAGE |
			       MR_TOGGLE_RX |
			       MR_NP_RX);
		if (ap->rxconfig & ANEG_CFG_FD)
			ap->flags |= MR_LP_ADV_FULL_DUPLEX;
		if (ap->rxconfig & ANEG_CFG_HD)
			ap->flags |= MR_LP_ADV_HALF_DUPLEX;
		if (ap->rxconfig & ANEG_CFG_PS1)
			ap->flags |= MR_LP_ADV_SYM_PAUSE;
		if (ap->rxconfig & ANEG_CFG_PS2)
			ap->flags |= MR_LP_ADV_ASYM_PAUSE;
		if (ap->rxconfig & ANEG_CFG_RF1)
			ap->flags |= MR_LP_ADV_REMOTE_FAULT1;
		if (ap->rxconfig & ANEG_CFG_RF2)
			ap->flags |= MR_LP_ADV_REMOTE_FAULT2;
		if (ap->rxconfig & ANEG_CFG_NP)
			ap->flags |= MR_LP_ADV_NEXT_PAGE;

		ap->link_time = ap->cur_time;

		ap->flags ^= (MR_TOGGLE_TX);
		if (ap->rxconfig & 0x0008)
			ap->flags |= MR_TOGGLE_RX;
		if (ap->rxconfig & ANEG_CFG_NP)
			ap->flags |= MR_NP_RX;
		ap->flags |= MR_PAGE_RX;

		ap->state = ANEG_STATE_COMPLETE_ACK;
		ret = ANEG_TIMER_ENAB;
		break;

	case ANEG_STATE_COMPLETE_ACK:
		if (ap->ability_match != 0 &&
		    ap->rxconfig == 0) {
			ap->state = ANEG_STATE_AN_ENABLE;
			break;
		}
		delta = ap->cur_time - ap->link_time;
		if (delta > ANEG_STATE_SETTLE_TIME) {
			if (!(ap->flags & (MR_LP_ADV_NEXT_PAGE))) {
				ap->state = ANEG_STATE_IDLE_DETECT_INIT;
			} else {
				if ((ap->txconfig & ANEG_CFG_NP) == 0 &&
				    !(ap->flags & MR_NP_RX)) {
					ap->state = ANEG_STATE_IDLE_DETECT_INIT;
				} else {
					ret = ANEG_FAILED;
				}
			}
		}
		break;

	case ANEG_STATE_IDLE_DETECT_INIT:
		ap->link_time = ap->cur_time;
		tp->mac_mode &= ~MAC_MODE_SEND_CONFIGS;
		tw32_f(MAC_MODE, tp->mac_mode);
		micro_delay(40);

		ap->state = ANEG_STATE_IDLE_DETECT;
		ret = ANEG_TIMER_ENAB;
		break;

	case ANEG_STATE_IDLE_DETECT:
		if (ap->ability_match != 0 &&
		    ap->rxconfig == 0) {
			ap->state = ANEG_STATE_AN_ENABLE;
			break;
		}
		delta = ap->cur_time - ap->link_time;
		if (delta > ANEG_STATE_SETTLE_TIME) {
			/* XXX another gem from the Broadcom driver :( */
			ap->state = ANEG_STATE_LINK_OK;
		}
		break;

	case ANEG_STATE_LINK_OK:
		ap->flags |= (MR_AN_COMPLETE | MR_LINK_OK);
		ret = ANEG_DONE;
		break;

	case ANEG_STATE_NEXT_PAGE_WAIT_INIT:
		/* ??? unimplemented */
		break;

	case ANEG_STATE_NEXT_PAGE_WAIT:
		/* ??? unimplemented */
		break;

	default:
		ret = ANEG_FAILED;
		break;
	}

	return ret;
}

PRIVATE int fiber_autoneg(tg3_t * tp, u32_t * txflags, u32_t * rxflags)
{
	int res = 0;
	struct tg3_fiber_aneginfo aninfo;
	int status = ANEG_FAILED;
	unsigned int tick;
	u32_t tmp;

	tw32_f(MAC_TX_AUTO_NEG, 0);

	tmp = tp->mac_mode & ~MAC_MODE_PORT_MODE_MASK;
	tw32_f(MAC_MODE, tmp | MAC_MODE_PORT_MODE_GMII);
	micro_delay(40);

	tw32_f(MAC_MODE, tp->mac_mode | MAC_MODE_SEND_CONFIGS);
	micro_delay(40);

	memset(&aninfo, 0, sizeof(aninfo));
	aninfo.flags |= MR_AN_ENABLE;
	aninfo.state = ANEG_STATE_UNKNOWN;
	aninfo.cur_time = 0;
	tick = 0;
	while (++tick < 195000) {
		status = tg3_fiber_aneg_smachine(tp, &aninfo);
		if (status == ANEG_DONE || status == ANEG_FAILED)
			break;

		micro_delay(1);
	}

	tp->mac_mode &= ~MAC_MODE_SEND_CONFIGS;
	tw32_f(MAC_MODE, tp->mac_mode);
	micro_delay(40);

	*txflags = aninfo.txconfig;
	*rxflags = aninfo.flags;

	if (status == ANEG_DONE &&
	    (aninfo.flags & (MR_AN_COMPLETE | MR_LINK_OK |
			     MR_LP_ADV_FULL_DUPLEX)))
		res = 1;

	return res;
}

PRIVATE void tg3_init_bcm8002(tg3_t * tp)
{
	u32_t mac_status = tr32(MAC_STATUS);
	int i;

	/* Reset when initting first time or we have a link. */
	if ((tp->tg3_flags & TG3_FLAG_INIT_COMPLETE) &&
	    !(mac_status & MAC_STATUS_PCS_SYNCED))
		return;

	/* Set PLL lock range. */
	tg3_writephy(tp, 0x16, 0x8007);

	/* SW reset */
	tg3_writephy(tp, MII_BMCR, BMCR_RESET);

	/* Wait for reset to complete. */
	/* XXX schedule_timeout() ... */
	for (i = 0; i < 500; i++)
		micro_delay(10);

	/* Config mode; select PMA/Ch 1 regs. */
	tg3_writephy(tp, 0x10, 0x8411);

	/* Enable auto-lock and comdet, select txclk for tx. */
	tg3_writephy(tp, 0x11, 0x0a10);

	tg3_writephy(tp, 0x18, 0x00a0);
	tg3_writephy(tp, 0x16, 0x41ff);

	/* Assert and deassert POR. */
	tg3_writephy(tp, 0x13, 0x0400);
	micro_delay(40);
	tg3_writephy(tp, 0x13, 0x0000);

	micro_delay(40);
	tg3_writephy(tp, 0x11, 0x0a10);

	/* Wait for signal to stabilize */
	/* XXX schedule_timeout() ... */
	for (i = 0; i < 15000; i++)
		micro_delay(10);

	/* Deselect the channel register so we can read the PHYID later. */
	tg3_writephy(tp, 0x10, 0x8011);
}

PRIVATE int tg3_setup_fiber_hw_autoneg(tg3_t * tp, u32_t mac_status)
{
	u16_t flowctrl;
	u32_t sg_dig_ctrl, sg_dig_status;
	u32_t serdes_cfg, expected_sg_dig_ctrl;
	int workaround, port_a;
	int current_link_up;

	serdes_cfg = 0;
	expected_sg_dig_ctrl = 0;
	workaround = 0;
	port_a = 1;
	current_link_up = 0;

	if (tp->pci_chip_rev_id != CHIPREV_ID_5704_A0 &&
	    tp->pci_chip_rev_id != CHIPREV_ID_5704_A1) {
		workaround = 1;
		if (tr32(TG3PCI_DUAL_MAC_CTRL) & DUAL_MAC_CTRL_ID)
			port_a = 0;

		/* preserve bits 0-11,13,14 for signal pre-emphasis */
		/* preserve bits 20-23 for voltage regulator */
		serdes_cfg = tr32(MAC_SERDES_CFG) & 0x00f06fff;
	}
	sg_dig_ctrl = tr32(SG_DIG_CTRL);

	if (tp->link_config.autoneg != AUTONEG_ENABLE) {
		if (sg_dig_ctrl & SG_DIG_USING_HW_AUTONEG) {
			if (workaround) {
				u32_t val = serdes_cfg;

				if (port_a)
					val |= 0xc010000;
				else
					val |= 0x4010000;
				tw32_f(MAC_SERDES_CFG, val);
			}
			tw32_f(SG_DIG_CTRL, SG_DIG_COMMON_SETUP);
		}
		if (mac_status & MAC_STATUS_PCS_SYNCED) {
			tg3_setup_flow_control(tp, 0, 0);
			current_link_up = 1;
		}
		goto out;
	}
	/* Want auto-negotiation.  */
	expected_sg_dig_ctrl = SG_DIG_USING_HW_AUTONEG | SG_DIG_COMMON_SETUP;

	flowctrl = tg3_advert_flowctrl_1000X(tp->link_config.flowctrl);
	if (flowctrl & ADVERTISE_1000XPAUSE)
		expected_sg_dig_ctrl |= SG_DIG_PAUSE_CAP;
	if (flowctrl & ADVERTISE_1000XPSE_ASYM)
		expected_sg_dig_ctrl |= SG_DIG_ASYM_PAUSE;

	if (sg_dig_ctrl != expected_sg_dig_ctrl) {
		if ((tp->tg3_flags2 & TG3_FLG2_PARALLEL_DETECT) &&
		    tp->serdes_counter &&
		    ((mac_status & (MAC_STATUS_PCS_SYNCED |
				    MAC_STATUS_RCVD_CFG)) ==
		     MAC_STATUS_PCS_SYNCED)) {
			tp->serdes_counter--;
			current_link_up = 1;
			goto out;
		}
restart_autoneg:
		if (workaround)
			tw32_f(MAC_SERDES_CFG, serdes_cfg | 0xc011000);
		tw32_f(SG_DIG_CTRL, expected_sg_dig_ctrl | SG_DIG_SOFT_RESET);
		micro_delay(5);
		tw32_f(SG_DIG_CTRL, expected_sg_dig_ctrl);

		tp->serdes_counter = SERDES_AN_TIMEOUT_5704S;
		tp->tg3_flags2 &= ~TG3_FLG2_PARALLEL_DETECT;
	} else if (mac_status & (MAC_STATUS_PCS_SYNCED |
				 MAC_STATUS_SIGNAL_DET)) {
		sg_dig_status = tr32(SG_DIG_STATUS);
		mac_status = tr32(MAC_STATUS);

		if ((sg_dig_status & SG_DIG_AUTONEG_COMPLETE) &&
		    (mac_status & MAC_STATUS_PCS_SYNCED)) {
			u32_t local_adv = 0, remote_adv = 0;

			if (sg_dig_ctrl & SG_DIG_PAUSE_CAP)
				local_adv |= ADVERTISE_1000XPAUSE;
			if (sg_dig_ctrl & SG_DIG_ASYM_PAUSE)
				local_adv |= ADVERTISE_1000XPSE_ASYM;

			if (sg_dig_status & SG_DIG_PARTNER_PAUSE_CAPABLE)
				remote_adv |= LPA_1000XPAUSE;
			if (sg_dig_status & SG_DIG_PARTNER_ASYM_PAUSE)
				remote_adv |= LPA_1000XPAUSE_ASYM;

			tg3_setup_flow_control(tp, local_adv, remote_adv);
			current_link_up = 1;
			tp->serdes_counter = 0;
			tp->tg3_flags2 &= ~TG3_FLG2_PARALLEL_DETECT;
		} else if (!(sg_dig_status & SG_DIG_AUTONEG_COMPLETE)) {
			if (tp->serdes_counter)
				tp->serdes_counter--;
			else {
				if (workaround) {
					u32_t val = serdes_cfg;

					if (port_a)
						val |= 0xc010000;
					else
						val |= 0x4010000;

					tw32_f(MAC_SERDES_CFG, val);
				}
				tw32_f(SG_DIG_CTRL, SG_DIG_COMMON_SETUP);
				micro_delay(40);

				/* Link parallel detection - link is up */
				/* only if we have PCS_SYNC and not */
				/* receiving config code words */
				mac_status = tr32(MAC_STATUS);
				if ((mac_status & MAC_STATUS_PCS_SYNCED) &&
				    !(mac_status & MAC_STATUS_RCVD_CFG)) {
					tg3_setup_flow_control(tp, 0, 0);
					current_link_up = 1;
					tp->tg3_flags2 |=
						TG3_FLG2_PARALLEL_DETECT;
					tp->serdes_counter =
						SERDES_PARALLEL_DET_TIMEOUT;
				} else
					goto restart_autoneg;
			}
		}
	} else {
		tp->serdes_counter = SERDES_AN_TIMEOUT_5704S;
		tp->tg3_flags2 &= ~TG3_FLG2_PARALLEL_DETECT;
	}

out:
	return current_link_up;
}

PRIVATE int tg3_setup_fiber_by_hand(tg3_t * tp, u32_t mac_status)
{
	int current_link_up = 0;

	if (!(mac_status & MAC_STATUS_PCS_SYNCED))
		goto out;

	if (tp->link_config.autoneg == AUTONEG_ENABLE) {
		u32_t txflags, rxflags;
		int i;

		if (fiber_autoneg(tp, &txflags, &rxflags)) {
			u32_t local_adv = 0, remote_adv = 0;

			if (txflags & ANEG_CFG_PS1)
				local_adv |= ADVERTISE_1000XPAUSE;
			if (txflags & ANEG_CFG_PS2)
				local_adv |= ADVERTISE_1000XPSE_ASYM;

			if (rxflags & MR_LP_ADV_SYM_PAUSE)
				remote_adv |= LPA_1000XPAUSE;
			if (rxflags & MR_LP_ADV_ASYM_PAUSE)
				remote_adv |= LPA_1000XPAUSE_ASYM;

			tg3_setup_flow_control(tp, local_adv, remote_adv);

			current_link_up = 1;
		}
		for (i = 0; i < 30; i++) {
			micro_delay(20);
			tw32_f(MAC_STATUS,
			       (MAC_STATUS_SYNC_CHANGED |
				MAC_STATUS_CFG_CHANGED));
			micro_delay(40);
			if ((tr32(MAC_STATUS) &
			     (MAC_STATUS_SYNC_CHANGED |
			      MAC_STATUS_CFG_CHANGED)) == 0)
				break;
		}

		mac_status = tr32(MAC_STATUS);
		if (current_link_up == 0 &&
		    (mac_status & MAC_STATUS_PCS_SYNCED) &&
		    !(mac_status & MAC_STATUS_RCVD_CFG))
			current_link_up = 1;
	} else {
		tg3_setup_flow_control(tp, 0, 0);

		/* Forcing 1000FD link up. */
		current_link_up = 1;

		tw32_f(MAC_MODE, (tp->mac_mode | MAC_MODE_SEND_CONFIGS));
		micro_delay(40);

		tw32_f(MAC_MODE, tp->mac_mode);
		micro_delay(40);
	}

out:
	return current_link_up;
}

PRIVATE int tg3_setup_fiber_phy(tg3_t * tp, int force_reset)
{
	u32_t orig_pause_cfg;
	u16_t orig_active_speed;
	u8_t orig_active_duplex;
	u32_t mac_status;
	int current_link_up;
	int i;

	orig_pause_cfg = tp->link_config.active_flowctrl;
	orig_active_speed = tp->link_config.active_speed;
	orig_active_duplex = tp->link_config.active_duplex;

	if (!(tp->tg3_flags2 & TG3_FLG2_HW_AUTONEG) &&
	    carrier_ok(tp) &&
	    (tp->tg3_flags & TG3_FLAG_INIT_COMPLETE)) {
		mac_status = tr32(MAC_STATUS);
		mac_status &= (MAC_STATUS_PCS_SYNCED |
			       MAC_STATUS_SIGNAL_DET |
			       MAC_STATUS_CFG_CHANGED |
			       MAC_STATUS_RCVD_CFG);
		if (mac_status == (MAC_STATUS_PCS_SYNCED |
				   MAC_STATUS_SIGNAL_DET)) {
			tw32_f(MAC_STATUS, (MAC_STATUS_SYNC_CHANGED |
					    MAC_STATUS_CFG_CHANGED));
			return 0;
		}
	}
	tw32_f(MAC_TX_AUTO_NEG, 0);

	tp->mac_mode &= ~(MAC_MODE_PORT_MODE_MASK | MAC_MODE_HALF_DUPLEX);
	tp->mac_mode |= MAC_MODE_PORT_MODE_TBI;
	tw32_f(MAC_MODE, tp->mac_mode);
	micro_delay(40);

	if (tp->phy_id == PHY_ID_BCM8002)
		tg3_init_bcm8002(tp);

	/* Enable link change event even when serdes polling.  */
	tw32_f(MAC_EVENT, MAC_EVENT_LNKSTATE_CHANGED);
	micro_delay(40);

	current_link_up = 0;
	mac_status = tr32(MAC_STATUS);

	if (tp->tg3_flags2 & TG3_FLG2_HW_AUTONEG)
		current_link_up = tg3_setup_fiber_hw_autoneg(tp, mac_status);
	else
		current_link_up = tg3_setup_fiber_by_hand(tp, mac_status);

	tp->hw_status->status =
		(SD_STATUS_UPDATED |
		 (tp->hw_status->status & ~SD_STATUS_LINK_CHG));

	for (i = 0; i < 100; i++) {
		tw32_f(MAC_STATUS, (MAC_STATUS_SYNC_CHANGED |
				    MAC_STATUS_CFG_CHANGED));
		micro_delay(5);
		if ((tr32(MAC_STATUS) & (MAC_STATUS_SYNC_CHANGED |
					 MAC_STATUS_CFG_CHANGED |
					 MAC_STATUS_LNKSTATE_CHANGED)) == 0)
			break;
	}

	mac_status = tr32(MAC_STATUS);
	if ((mac_status & MAC_STATUS_PCS_SYNCED) == 0) {
		current_link_up = 0;
		if (tp->link_config.autoneg == AUTONEG_ENABLE &&
		    tp->serdes_counter == 0) {
			tw32_f(MAC_MODE, (tp->mac_mode |
					  MAC_MODE_SEND_CONFIGS));
			micro_delay(1);
			tw32_f(MAC_MODE, tp->mac_mode);
		}
	}
	if (current_link_up == 1) {
		tp->link_config.active_speed = SPEED_1000;
		tp->link_config.active_duplex = DUPLEX_FULL;
		tw32(MAC_LED_CTRL, (tp->led_ctrl |
				    LED_CTRL_LNKLED_OVERRIDE |
				    LED_CTRL_1000MBPS_ON));
	} else {
		tp->link_config.active_speed = SPEED_INVALID;
		tp->link_config.active_duplex = DUPLEX_INVALID;
		tw32(MAC_LED_CTRL, (tp->led_ctrl |
				    LED_CTRL_LNKLED_OVERRIDE |
				    LED_CTRL_TRAFFIC_OVERRIDE));
	}

	if (current_link_up != carrier_ok(tp)) {
		if (current_link_up)
			carrier_on(tp);
		else
			carrier_off(tp);
		tg3_link_report(tp);
	} else {
		u32_t now_pause_cfg = tp->link_config.active_flowctrl;
		if (orig_pause_cfg != now_pause_cfg ||
		    orig_active_speed != tp->link_config.active_speed ||
		    orig_active_duplex != tp->link_config.active_duplex)
			tg3_link_report(tp);
	}

	return 0;
}

PRIVATE int tg3_setup_fiber_mii_phy(tg3_t * tp, int force_reset)
{
	int current_link_up, err = 0;
	u32_t bmsr, bmcr;
	u16_t current_speed;
	u8_t current_duplex;
	u32_t local_adv, remote_adv;

	tp->mac_mode |= MAC_MODE_PORT_MODE_GMII;
	tw32_f(MAC_MODE, tp->mac_mode);
	micro_delay(40);

	tw32(MAC_EVENT, 0);

	tw32_f(MAC_STATUS,
	       (MAC_STATUS_SYNC_CHANGED |
		MAC_STATUS_CFG_CHANGED |
		MAC_STATUS_MI_COMPLETION |
		MAC_STATUS_LNKSTATE_CHANGED));
	micro_delay(40);

	if (force_reset)
		tg3_phy_reset(tp);

	current_link_up = 0;
	current_speed = SPEED_INVALID;
	current_duplex = DUPLEX_INVALID;

	err |= tg3_readphy(tp, MII_BMSR, &bmsr);
	err |= tg3_readphy(tp, MII_BMSR, &bmsr);
	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5714) {
		if (tr32(MAC_TX_STATUS) & TX_STATUS_LINK_UP)
			bmsr |= BMSR_LSTATUS;
		else
			bmsr &= ~BMSR_LSTATUS;
	}
	err |= tg3_readphy(tp, MII_BMCR, &bmcr);

	if ((tp->link_config.autoneg == AUTONEG_ENABLE) && !force_reset &&
	    (tp->tg3_flags2 & TG3_FLG2_PARALLEL_DETECT)) {
		/* do nothing, just check for link up at the end */
	} else if (tp->link_config.autoneg == AUTONEG_ENABLE) {
		u32_t adv, new_adv;

		err |= tg3_readphy(tp, MII_ADVERTISE, &adv);
		new_adv = adv & ~(ADVERTISE_1000XFULL | ADVERTISE_1000XHALF |
				  ADVERTISE_1000XPAUSE |
				  ADVERTISE_1000XPSE_ASYM |
				  ADVERTISE_SLCT);

		new_adv |= tg3_advert_flowctrl_1000X(tp->link_config.flowctrl);

		if (tp->link_config.advertising & ADVERTISED_1000baseT_Half)
			new_adv |= ADVERTISE_1000XHALF;
		if (tp->link_config.advertising & ADVERTISED_1000baseT_Full)
			new_adv |= ADVERTISE_1000XFULL;

		if ((new_adv != adv) || !(bmcr & BMCR_ANENABLE)) {
			tg3_writephy(tp, MII_ADVERTISE, new_adv);
			bmcr |= BMCR_ANENABLE | BMCR_ANRESTART;
			tg3_writephy(tp, MII_BMCR, bmcr);

			tw32_f(MAC_EVENT, MAC_EVENT_LNKSTATE_CHANGED);
			tp->serdes_counter = SERDES_AN_TIMEOUT_5714S;
			tp->tg3_flags2 &= ~TG3_FLG2_PARALLEL_DETECT;

			return err;
		}
	} else {
		u32_t new_bmcr;

		bmcr &= ~BMCR_SPEED1000;
		new_bmcr = bmcr & ~(BMCR_ANENABLE | BMCR_FULLDPLX);

		if (tp->link_config.duplex == DUPLEX_FULL)
			new_bmcr |= BMCR_FULLDPLX;

		if (new_bmcr != bmcr) {
			/* BMCR_SPEED1000 is a reserved bit that needs to be
			 * set on write. */
			new_bmcr |= BMCR_SPEED1000;

			/* Force a linkdown */
			if (carrier_ok(tp)) {
				u32_t adv;

				err |= tg3_readphy(tp, MII_ADVERTISE, &adv);
				adv &= ~(ADVERTISE_1000XFULL |
					 ADVERTISE_1000XHALF |
					 ADVERTISE_SLCT);
				tg3_writephy(tp, MII_ADVERTISE, adv);
				tg3_writephy(tp, MII_BMCR, bmcr |
					     BMCR_ANRESTART |
					     BMCR_ANENABLE);
				micro_delay(10);
				carrier_off(tp);
			}
			tg3_writephy(tp, MII_BMCR, new_bmcr);
			bmcr = new_bmcr;
			err |= tg3_readphy(tp, MII_BMSR, &bmsr);
			err |= tg3_readphy(tp, MII_BMSR, &bmsr);
			if (GET_ASIC_REV(tp->pci_chip_rev_id) ==
			    ASIC_REV_5714) {
				if (tr32(MAC_TX_STATUS) & TX_STATUS_LINK_UP)
					bmsr |= BMSR_LSTATUS;
				else
					bmsr &= ~BMSR_LSTATUS;
			}
			tp->tg3_flags2 &= ~TG3_FLG2_PARALLEL_DETECT;
		}
	}

	if (bmsr & BMSR_LSTATUS) {
		current_speed = SPEED_1000;
		current_link_up = 1;
		if (bmcr & BMCR_FULLDPLX)
			current_duplex = DUPLEX_FULL;
		else
			current_duplex = DUPLEX_HALF;

		local_adv = 0;
		remote_adv = 0;

		if (bmcr & BMCR_ANENABLE) {
			u32_t common;

			err |= tg3_readphy(tp, MII_ADVERTISE, &local_adv);
			err |= tg3_readphy(tp, MII_LPA, &remote_adv);
			common = local_adv & remote_adv;
			if (common & (ADVERTISE_1000XHALF |
				      ADVERTISE_1000XFULL)) {
				if (common & ADVERTISE_1000XFULL)
					current_duplex = DUPLEX_FULL;
				else
					current_duplex = DUPLEX_HALF;
			} else
				current_link_up = 0;
		}
	}
	if (current_link_up == 1 && current_duplex == DUPLEX_FULL)
		tg3_setup_flow_control(tp, local_adv, remote_adv);

	tp->mac_mode &= ~MAC_MODE_HALF_DUPLEX;
	if (tp->link_config.active_duplex == DUPLEX_HALF)
		tp->mac_mode |= MAC_MODE_HALF_DUPLEX;

	tw32_f(MAC_MODE, tp->mac_mode);
	micro_delay(40);

	tw32_f(MAC_EVENT, MAC_EVENT_LNKSTATE_CHANGED);

	tp->link_config.active_speed = current_speed;
	tp->link_config.active_duplex = current_duplex;

	if (current_link_up != carrier_ok(tp)) {
		if (current_link_up)
			carrier_on(tp);
		else {
			carrier_off(tp);
			tp->tg3_flags2 &= ~TG3_FLG2_PARALLEL_DETECT;
		}
		tg3_link_report(tp);
	}
	return err;
}

PRIVATE void tg3_serdes_parallel_detect(tg3_t * tp)
{
	if (tp->serdes_counter) {
		/* Give autoneg time to complete. */
		tp->serdes_counter--;
		return;
	}
	if (!carrier_ok(tp) &&
	    (tp->link_config.autoneg == AUTONEG_ENABLE)) {
		u32_t bmcr;

		tg3_readphy(tp, MII_BMCR, &bmcr);
		if (bmcr & BMCR_ANENABLE) {
			u32_t phy1, phy2;

			/* Select shadow register 0x1f */
			tg3_writephy(tp, 0x1c, 0x7c00);
			tg3_readphy(tp, 0x1c, &phy1);

			/* Select expansion interrupt status register */
			tg3_writephy(tp, 0x17, 0x0f01);
			tg3_readphy(tp, 0x15, &phy2);
			tg3_readphy(tp, 0x15, &phy2);

			if ((phy1 & 0x10) && !(phy2 & 0x20)) {
				/* We have signal detect and not receiving
				 * config code words, link is up by parallel
				 * detection. */

				bmcr &= ~BMCR_ANENABLE;
				bmcr |= BMCR_SPEED1000 | BMCR_FULLDPLX;
				tg3_writephy(tp, MII_BMCR, bmcr);
				tp->tg3_flags2 |= TG3_FLG2_PARALLEL_DETECT;
			}
		}
	} else if (carrier_ok(tp) &&
		   (tp->link_config.autoneg == AUTONEG_ENABLE) &&
		   (tp->tg3_flags2 & TG3_FLG2_PARALLEL_DETECT)) {
		u32_t phy2;

		/* Select expansion interrupt status register */
		tg3_writephy(tp, 0x17, 0x0f01);
		tg3_readphy(tp, 0x15, &phy2);
		if (phy2 & 0x20) {
			u32_t bmcr;

			/* Config code words received, turn on autoneg. */
			tg3_readphy(tp, MII_BMCR, &bmcr);
			tg3_writephy(tp, MII_BMCR, bmcr | BMCR_ANENABLE);

			tp->tg3_flags2 &= ~TG3_FLG2_PARALLEL_DETECT;

		}
	}
}

PRIVATE int tg3_setup_phy(tg3_t * tp, int force_reset)
{
	int err;

	if (tp->tg3_flags2 & TG3_FLG2_PHY_SERDES) {
		err = tg3_setup_fiber_phy(tp, force_reset);
	} else if (tp->tg3_flags2 & TG3_FLG2_MII_SERDES) {
		err = tg3_setup_fiber_mii_phy(tp, force_reset);
	} else {
		err = tg3_setup_copper_phy(tp, force_reset);
	}

	if (GET_CHIP_REV(tp->pci_chip_rev_id) == CHIPREV_5784_AX) {
		u32_t val, scale;

		val = tr32(TG3_CPMU_CLCK_STAT) & CPMU_CLCK_STAT_MAC_CLCK_MASK;
		if (val == CPMU_CLCK_STAT_MAC_CLCK_62_5)
			scale = 65;
		else if (val == CPMU_CLCK_STAT_MAC_CLCK_6_25)
			scale = 6;
		else
			scale = 12;

		val = tr32(GRC_MISC_CFG) & ~GRC_MISC_CFG_PRESCALAR_MASK;
		val |= (scale << GRC_MISC_CFG_PRESCALAR_SHIFT);
		tw32(GRC_MISC_CFG, val);
	}
	if (tp->link_config.active_speed == SPEED_1000 &&
	    tp->link_config.active_duplex == DUPLEX_HALF)
		tw32(MAC_TX_LENGTHS,
		     ((2 << TX_LENGTHS_IPG_CRS_SHIFT) |
		      (6 << TX_LENGTHS_IPG_SHIFT) |
		      (0xff << TX_LENGTHS_SLOT_TIME_SHIFT)));
	else
		tw32(MAC_TX_LENGTHS,
		     ((2 << TX_LENGTHS_IPG_CRS_SHIFT) |
		      (6 << TX_LENGTHS_IPG_SHIFT) |
		      (32 << TX_LENGTHS_SLOT_TIME_SHIFT)));

	if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS)) {
		if (carrier_ok(tp)) {
			tw32(HOSTCC_STAT_COAL_TICKS,
			     tp->coal.stats_block_coalesce_usecs);
		} else {
			tw32(HOSTCC_STAT_COAL_TICKS, 0);
		}
	}
	if (tp->tg3_flags & TG3_FLAG_ASPM_WORKAROUND) {
		u32_t val = tr32(PCIE_PWR_MGMT_THRESH);
		if (!carrier_ok(tp))
			val = (val & ~PCIE_PWR_MGMT_L1_THRESH_MSK) |
				tp->pwrmgmt_thresh;
		else
			val |= PCIE_PWR_MGMT_L1_THRESH_MSK;
		tw32(PCIE_PWR_MGMT_THRESH, val);
	}
	return err;
}

/* This is called whenever we suspect that the system chipset is re-
 * ordering the sequence of MMIO to the tx send mailbox. The symptom
 * is bogus tx completions. We try to recover by setting the
 * TG3_FLAG_MBOX_WRITE_REORDER flag and resetting the chip later
 */
PRIVATE void tg3_tx_recover(tg3_t * tp)
{
	assert(!((tp->tg3_flags & TG3_FLAG_MBOX_WRITE_REORDER) ||
		 tp->write32_tx_mbox == tg3_write_indirect_mbox));

	printf("%s: The system may be re-ordering memory-"
	       "mapped I/O cycles to the network device, attempting to "
	       "recover. Please report the problem to the driver maintainer "
	       "and include system chipset information.\n", tp->name);

	tp->tg3_flags |= TG3_FLAG_TX_RECOVERY_PENDING;
}

PRIVATE u32_t tg3_tx_avail(tg3_t * tp)
{
	return (tp->tx_pending -
		((tp->tx_prod - tp->tx_cons) & (TG3_TX_RING_SIZE - 1)));
}

PRIVATE void tg3_tx(tg3_t * tp)
{
	u32_t hw_idx = tp->hw_status->idx[0].tx_consumer;
	u32_t sw_idx = tp->tx_cons;

	while (sw_idx != hw_idx) {
		struct tx_ring_info *ri = &tp->tx_buffers[sw_idx];

		/* Never seen this on Minix, but just to be safe... */
		if (ri->in_use == 0) {
			tg3_tx_recover(tp);
			return;
		}
		ri->in_use = 0;
		sw_idx = NEXT_TX(sw_idx);
	}

	tp->tx_cons = sw_idx;

}

/* Returns size of buffer allocated or < 0 on error.
 *
 * We only need to fill in the address because the other members
 * of the RX descriptor are invariant, see tg3_init_rings.
 *
 * Note the purposeful assymetry of cpu vs. chip accesses.  For
 * posting buffers we only dirty the first cache line of the RX
 * descriptor (containing the address).  Whereas for the RX status
 * buffers the cpu only reads the last cacheline of the RX descriptor
 * (to fetch the error flags, vlan tag, checksum, and opaque cookie).
 */
PRIVATE int tg3_alloc_rx_iovec(tg3_t * tp, u32_t opaque_key,
			        int src_idx, u32_t dest_idx_unmasked)
{
	struct tg3_rx_buffer_desc *desc;
	struct ring_info *map, *src_map;
	iovec_t *iovec;
	phys_bytes mapping;
	int iovec_size, dest_idx;

	src_map = NULL;
	switch (opaque_key) {
	case RXD_OPAQUE_RING_STD:
		dest_idx = dest_idx_unmasked % TG3_RX_RING_SIZE;
		desc = &tp->rx_std[dest_idx];
		map = &tp->rx_std_buffers[dest_idx];
		if (src_idx >= 0)
			src_map = &tp->rx_std_buffers[src_idx];
		iovec_size = tp->rx_pkt_buf_sz;
		break;

	case RXD_OPAQUE_RING_JUMBO:
		dest_idx = dest_idx_unmasked % TG3_RX_JUMBO_RING_SIZE;
		desc = &tp->rx_jumbo[dest_idx];
		map = &tp->rx_jumbo_buffers[dest_idx];
		if (src_idx >= 0)
			src_map = &tp->rx_jumbo_buffers[src_idx];
		iovec_size = RX_JUMBO_PKT_BUF_SZ;
		break;

	default:
		return -EINVAL;
	}

	/* Do not overwrite any of the map or rp information until we are sure
	 * we can commit to a new buffer.
	 * 
	 * Callers depend upon this behavior and assume that we leave everything
	 * unchanged if we fail. */

	mapping = 0;
	iovec = alloc_iovec(iovec_size, &mapping);
	if (iovec == NULL)
		return -ENOMEM;

	map->iovec = iovec;
	map->mapping = mapping;
	if (src_map != NULL)
		src_map->iovec = NULL;

	/* Minix is currently 32bit so mapping is 32bit */
	desc->addr_hi = 0;
	desc->addr_lo = mapping;

	return iovec_size;
}

/* We only need to move over in the address because the other
 * members of the RX descriptor are invariant.  See notes above
 * tg3_alloc_rx_iovec for full details.
 */
PRIVATE void tg3_recycle_rx(tg3_t * tp, u32_t opaque_key,
			     int src_idx, u32_t dest_idx_unmasked)
{
	struct tg3_rx_buffer_desc *src_desc, *dest_desc;
	struct ring_info *src_map, *dest_map;
	int dest_idx;

	switch (opaque_key) {
	case RXD_OPAQUE_RING_STD:
		dest_idx = dest_idx_unmasked % TG3_RX_RING_SIZE;
		dest_desc = &tp->rx_std[dest_idx];
		dest_map = &tp->rx_std_buffers[dest_idx];
		src_desc = &tp->rx_std[src_idx];
		src_map = &tp->rx_std_buffers[src_idx];
		break;

	case RXD_OPAQUE_RING_JUMBO:
		dest_idx = dest_idx_unmasked % TG3_RX_JUMBO_RING_SIZE;
		dest_desc = &tp->rx_jumbo[dest_idx];
		dest_map = &tp->rx_jumbo_buffers[dest_idx];
		src_desc = &tp->rx_jumbo[src_idx];
		src_map = &tp->rx_jumbo_buffers[src_idx];
		break;

	default:
		return;
	}

	dest_map->iovec = src_map->iovec;
	dest_desc->addr_hi = src_desc->addr_hi;
	dest_desc->addr_lo = src_desc->addr_lo;

	src_map->iovec = NULL;
}

PRIVATE int tg3_poll_work(tg3_t * tp, int work_done)
{
	struct tg3_hw_status *sblk = tp->hw_status;

	/* handle link change and other phy events */
	if (!(tp->tg3_flags &
	      (TG3_FLAG_USE_LINKCHG_REG |
	       TG3_FLAG_POLL_SERDES))) {
		if (sblk->status & SD_STATUS_LINK_CHG) {
			sblk->status = SD_STATUS_UPDATED |
				(sblk->status & ~SD_STATUS_LINK_CHG);

			if (tp->tg3_flags3 & TG3_FLG3_USE_PHYLIB) {
				tw32_f(MAC_STATUS,
				       (MAC_STATUS_SYNC_CHANGED |
					MAC_STATUS_CFG_CHANGED |
					MAC_STATUS_MI_COMPLETION |
					MAC_STATUS_LNKSTATE_CHANGED));
				micro_delay(40);
			} else
				tg3_setup_phy(tp, 0);
		}
	}
	/* run TX completion thread */
	if (sblk->idx[0].tx_consumer != tp->tx_cons) {
		tg3_tx(tp);
		if (tp->tg3_flags & TG3_FLAG_TX_RECOVERY_PENDING)
			return work_done;
	}
	/* Minix: running of RX is done later in the int handler */

	return work_done;
}

PRIVATE int tg3_poll(tg3_t * tp)
{
	int work_done = 0;
	struct tg3_hw_status *sblk = tp->hw_status;

	while (1) {
		work_done = tg3_poll_work(tp, work_done);

		if (tp->tg3_flags & TG3_FLAG_TX_RECOVERY_PENDING)
			goto tx_recovery;

		if (tp->tg3_flags & TG3_FLAG_TAGGED_STATUS) {
			/* tp->last_tag is used in tg3_restart_ints() below to
			 * tell the hw how much work has been processed, so we
			 * must read it before checking for more work. */
			tp->last_tag = sblk->status_tag;
			tp->last_irq_tag = tp->last_tag;
		} else
			sblk->status &= ~SD_STATUS_UPDATED;

		if (!tg3_has_work(tp)) {
			tg3_restart_ints(tp);
			break;
		}
	}

	return work_done;

tx_recovery:
	tg3_reset_task(tp);
	return work_done;
}

PRIVATE void tg3_irq_quiesce(tg3_t * tp)
{
	assert(!(tp->irq_sync));
	tp->irq_sync = 1;
}

PRIVATE int tg3_irq_sync(tg3_t * tp)
{
	return tp->irq_sync;
}

/* Fully shutdown all tg3 driver activity elsewhere in the system.
 * If irq_sync is non-zero, then the IRQ handler must be synchronized
 * with as well.  Most of the time, this is not necessary except when
 * shutting down the device.
 */
PRIVATE void tg3_full_lock(tg3_t * tp, int irq_sync)
{
	if (irq_sync)
		tg3_irq_quiesce(tp);
}

PRIVATE void tg3_full_unlock(tg3_t * tp)
{
}

PRIVATE u32_t tg3_interrupt(tg3_t * tp)
{
	struct tg3_hw_status *sblk = tp->hw_status;
	unsigned int handled = 1;

	/* In INTx mode, it is possible for the interrupt to arrive at the CPU
	 * before the status block posted prior to the interrupt. Reading the
	 * PCI State register will confirm whether the interrupt is ours and
	 * will flush the status block. */
	if (!(sblk->status & SD_STATUS_UPDATED)) {
		if ((tp->tg3_flags & TG3_FLAG_CHIP_RESETTING) ||
		    (tr32(TG3PCI_PCISTATE) & PCISTATE_INT_NOT_ACTIVE)) {
			handled = 0;
			goto out;
		}
	}
	/* Writing any value to intr-mbox-0 clears PCI INTA# and chip-internal
	 * interrupt pending events. Writing non-zero to intr-mbox-0 additional
	 * tells the NIC to stop sending us irqs, engaging "in-intr-handler"
	 * event coalescing.
	 * 
	 * Flush the mailbox to de-assert the IRQ immediately to prevent spurious
	 * interrupts.  The flush impacts performance but excessive spurious
	 * interrupts can be worse in some cases. */
	tw32_mailbox_f(MAILBOX_INTERRUPT_0 + TG3_64BIT_REG_LOW, 0x00000001);
	if (tg3_irq_sync(tp)) {
		printf("INT out 1\n");
		goto out;
	}
	sblk->status &= ~SD_STATUS_UPDATED;
	if (!tg3_has_work(tp)) {
		/* No work, shared interrupt perhaps?  re-enable interrupts,
		 * and flush that PCI write */

		/* Minix addition. We use the return value to indicate if we
		 * need to poll or not */
		handled = 0;
		tw32_mailbox_f(MAILBOX_INTERRUPT_0 + TG3_64BIT_REG_LOW,
			       0x00000000);
	}
out:
	return handled;
}

PRIVATE u32_t tg3_interrupt_tagged(tg3_t * tp)
{
	struct tg3_hw_status *sblk = tp->hw_status;
	unsigned int handled = 1;

	/* In INTx mode, it is possible for the interrupt to arrive at the CPU
	 * before the status block posted prior to the interrupt. Reading the
	 * PCI State register will confirm whether the interrupt is ours and
	 * will flush the status block. */
	if (sblk->status_tag == tp->last_irq_tag) {
		if ((tp->tg3_flags & TG3_FLAG_CHIP_RESETTING) ||
		    (tr32(TG3PCI_PCISTATE) & PCISTATE_INT_NOT_ACTIVE)) {
			handled = 0;
			goto out;
		}
	}
	/* writing any value to intr-mbox-0 clears PCI INTA# and chip-internal
	 * interrupt pending events. writing non-zero to intr-mbox-0 additional
	 * tells the NIC to stop sending us irqs, engaging "in-intr-handler"
	 * event coalescing.
	 * 
	 * Flush the mailbox to de-assert the IRQ immediately to prevent spurious
	 * interrupts.  The flush impacts performance but excessive spurious
	 * interrupts can be worse in some cases. */
	tw32_mailbox_f(MAILBOX_INTERRUPT_0 + TG3_64BIT_REG_LOW, 0x00000001);


	/* In a shared interrupt configuration, sometimes other devices'
	 * interrupts will scream.  We record the current status tag here so
	 * that the above check can report that the screaming interrupts are
	 * unhandled.  Eventually they will be silenced. */
	tp->last_irq_tag = sblk->status_tag;


	if (tg3_irq_sync(tp)) {
		/* Minix addition. We use the return value to indicate if we
		 * need to poll or not */
		handled = 0;
		goto out;
	}
out:
	return handled;
}

/* Restart hardware after configuration changes, self-test, etc. */
PRIVATE int tg3_restart_hw(tg3_t * tp, int reset_phy)
{
	int err;

	err = tg3_init_hw(tp, reset_phy);
	if (err) {
		printf("%s: Failed to re-initialize device, "
		       "aborting.\n", tp->name);
		tg3_halt(tp, RESET_KIND_SHUTDOWN, 1);
		tg3_full_unlock(tp);
		tp->irq_sync = 0;
		tg3_full_lock(tp, 0);
	}
	return err;
}

PRIVATE void tg3_reset_task(tg3_t * tp)
{
	int err;
	unsigned int restart_timer;

	tg3_full_lock(tp, 0);

	if (!tg3_enabled(tp)) {
		tg3_full_unlock(tp);
		return;
	}
	tg3_full_unlock(tp);

	tg3_phy_stop(tp);


	tg3_full_lock(tp, 1);

	restart_timer = tp->tg3_flags2 & TG3_FLG2_RESTART_TIMER;
	tp->tg3_flags2 &= ~TG3_FLG2_RESTART_TIMER;

	if (tp->tg3_flags & TG3_FLAG_TX_RECOVERY_PENDING) {
		tp->write32_tx_mbox = tg3_write32_tx_mbox;
		tp->write32_rx_mbox = tg3_write_flush_reg32;
		tp->tg3_flags |= TG3_FLAG_MBOX_WRITE_REORDER;
		tp->tg3_flags &= ~TG3_FLAG_TX_RECOVERY_PENDING;
	}
	tg3_halt(tp, RESET_KIND_SHUTDOWN, 0);
	err = tg3_init_hw(tp, 1);
	if (err)
		goto out;

	tg3_start(tp);

	if (restart_timer) {
		sys_setalarm(1, 0);	/* timer to fire next tick */
	}
out:
	tg3_full_unlock(tp);

	if (!err)
		tg3_phy_start(tp);
}

PRIVATE void tg3_dump_short_state(tg3_t * tp)
{
	printf("DEBUG: MAC_TX_STATUS[%08x] MAC_RX_STATUS[%08x]\n",
	       tr32(MAC_TX_STATUS), tr32(MAC_RX_STATUS));
	printf("DEBUG: RDMAC_STATUS[%08x] WDMAC_STATUS[%08x]\n",
	       tr32(RDMAC_STATUS), tr32(WDMAC_STATUS));
}

PRIVATE void tg3_set_txd(tg3_t * tp, int entry,
			  vir_bytes mapping, int len, u32_t flags,
			  u32_t mss_and_is_end)
{
	struct tg3_tx_buffer_desc *txd = &tp->tx_ring[entry];
	int is_end = (mss_and_is_end & 0x1);
	u32_t mss = (mss_and_is_end >> 1);
	u32_t vlan_tag = 0;

	if (is_end)
		flags |= TXD_FLAG_END;
	if (flags & TXD_FLAG_VLAN) {
		vlan_tag = flags >> 16;
		flags &= 0xffff;
	}
	vlan_tag |= (mss << TXD_MSS_SHIFT);

	/* Minix is 32bit so mapping is too */
	txd->addr_hi = 0;
	txd->addr_lo = mapping;
	txd->len_flags = (len << TXD_LEN_SHIFT) | flags;
	txd->vlan_tag = vlan_tag << TXD_VLAN_TAG_SHIFT;
}

PRIVATE int tg3_init_rings(tg3_t * tp)
{
	u32_t i;

	/* Zero out all descriptors. */
	memset(tp->rx_std, 0, TG3_RX_RING_BYTES);
	memset(tp->rx_jumbo, 0, TG3_RX_JUMBO_RING_BYTES);
	memset(tp->rx_rcb, 0, TG3_RX_RCB_RING_BYTES(tp));
	memset(tp->tx_ring, 0, TG3_TX_RING_BYTES);

	tp->rx_pkt_buf_sz = RX_PKT_BUF_SZ;
	if ((tp->tg3_flags2 & TG3_FLG2_5780_CLASS) &&
	    (tp->mtu > ETH_DATA_LEN))
		tp->rx_pkt_buf_sz = RX_JUMBO_PKT_BUF_SZ;

	/* Initialize invariants of the rings, we only set this stuff once.
	 * This works because the card does not write into the rx buffer
	 * posting rings. */
	for (i = 0; i < TG3_RX_RING_SIZE; i++) {
		struct tg3_rx_buffer_desc *rxd;

		rxd = &tp->rx_std[i];
		rxd->idx_len = (tp->rx_pkt_buf_sz - tp->rx_offset - 64)
			<< RXD_LEN_SHIFT;
		rxd->type_flags = (RXD_FLAG_END << RXD_FLAGS_SHIFT);
		rxd->opaque = (RXD_OPAQUE_RING_STD |
			       (i << RXD_OPAQUE_INDEX_SHIFT));
	}

	if (tp->tg3_flags & TG3_FLAG_JUMBO_RING_ENABLE) {
		for (i = 0; i < TG3_RX_JUMBO_RING_SIZE; i++) {
			struct tg3_rx_buffer_desc *rxd;

			rxd = &tp->rx_jumbo[i];
			rxd->idx_len = (RX_JUMBO_PKT_BUF_SZ - tp->rx_offset - 64)
				<< RXD_LEN_SHIFT;
			rxd->type_flags = (RXD_FLAG_END << RXD_FLAGS_SHIFT) |
				RXD_FLAG_JUMBO;
			rxd->opaque = (RXD_OPAQUE_RING_JUMBO |
				       (i << RXD_OPAQUE_INDEX_SHIFT));
		}
	}
	/* Now allocate fresh buffer for each rx ring. */
	for (i = 0; i < tp->rx_pending; i++) {
		if (tg3_alloc_rx_iovec(tp, RXD_OPAQUE_RING_STD, -1, i) < 0) {
			printf(
			       "%s: Using a smaller RX standard ring, "
			       "only %d out of %d buffers were allocated "
			       "successfully.\n",
			       tp->name, i, tp->rx_pending);
			if (i == 0)
				return -ENOMEM;
			tp->rx_pending = i;
			break;
		}
	}

	if (tp->tg3_flags & TG3_FLAG_JUMBO_RING_ENABLE) {
		for (i = 0; i < tp->rx_jumbo_pending; i++) {
			if (tg3_alloc_rx_iovec(tp, RXD_OPAQUE_RING_JUMBO,
					       -1, i) < 0) {
				printf(
				       "%s: Using a smaller RX jumbo ring, "
				       "only %d out of %d buffers were "
				       "allocated successfully.\n",
				       tp->name, i, tp->rx_jumbo_pending);
				if (i == 0) {
					return -ENOMEM;
				}
				tp->rx_jumbo_pending = i;
				break;
			}
		}
	}
	return 0;
}

/*
 * Must not be invoked with interrupt sources disabled and
 * the hardware shutdown down.
 */
PRIVATE void tg3_free_consistent(tg3_t * tp)
{
	minix_munmap(tp->rx_std_buffers, (sizeof(struct ring_info) *
				    (TG3_RX_RING_SIZE +
				     TG3_RX_JUMBO_RING_SIZE)) +
	       (sizeof(struct tx_ring_info) *
		TG3_TX_RING_SIZE));
	tp->rx_std_buffers = NULL;

	if (tp->rx_std) {
		minix_munmap(tp->rx_std, TG3_RX_RING_BYTES);
		tp->rx_std = NULL;
	}
	if (tp->rx_jumbo) {
		minix_munmap(tp->rx_jumbo, TG3_RX_JUMBO_RING_BYTES);
		tp->rx_jumbo = NULL;
	}
	if (tp->rx_rcb) {
		minix_munmap(tp->rx_rcb, TG3_RX_RCB_RING_BYTES(tp));
		tp->rx_rcb = NULL;
	}
	if (tp->tx_ring) {
		minix_munmap(tp->tx_ring, TG3_TX_RING_BYTES);
		tp->tx_ring = NULL;
	}
	if (tp->hw_status) {
		minix_munmap(tp->hw_status, TG3_HW_STATUS_SIZE);
		tp->hw_status = NULL;
	}
	if (tp->hw_stats) {
		minix_munmap(tp->hw_stats, sizeof(struct tg3_hw_stats));
		tp->hw_stats = NULL;
	}
}

/*
 * Must not be invoked with interrupt sources disabled and
 * the hardware shutdown down.  Can sleep.
 */
PRIVATE int tg3_alloc_consistent(tg3_t * tp)
{
	int i;

	tp->rx_std_buffers = alloc_contig((sizeof(struct ring_info) *
					   (TG3_RX_RING_SIZE +
					    TG3_RX_JUMBO_RING_SIZE)) +
					  (sizeof(struct tx_ring_info) *
					   TG3_TX_RING_SIZE), 0, NULL);

	if (!tp->rx_std_buffers)
		return -ENOMEM;


	tp->rx_jumbo_buffers = &tp->rx_std_buffers[TG3_RX_RING_SIZE];
	tp->tx_buffers = (struct tx_ring_info *)
		& tp->rx_jumbo_buffers[TG3_RX_JUMBO_RING_SIZE];

	/* On Minix we allocate the TX buffers once. */
	/* We also store the physical address of the buffer; */
	for (i = 0; i < TG3_TX_RING_SIZE; i++) {
		struct tx_ring_info *ri = &tp->tx_buffers[i];
		ri->iovec.iov_addr =
			(vir_bytes) alloc_contig(	TG3_TX_IOVEC_SIZE, 
							0,
							&(ri->mapping));
	}

	tp->rx_std =
		alloc_contig(TG3_RX_RING_BYTES,
		0,
		(phys_bytes *) & tp->rx_std_mapping);


	if (!tp->rx_std)
		goto err_out;

	tp->rx_jumbo =
		alloc_contig(TG3_RX_JUMBO_RING_BYTES, 0, 
			(phys_bytes *) & tp->rx_jumbo_mapping);

	if (!tp->rx_jumbo)
		goto err_out;

	tp->rx_rcb = alloc_contig(TG3_RX_RCB_RING_BYTES(tp), 0,
				  (phys_bytes *) & tp->rx_rcb_mapping);

	if (!tp->rx_rcb)
		goto err_out;

	tp->tx_ring =
		alloc_contig(TG3_TX_RING_BYTES, 0,
			(phys_bytes *) & tp->tx_desc_mapping);

	if (!tp->tx_ring)
		goto err_out;

	tp->hw_status =
		alloc_contig(TG3_HW_STATUS_SIZE, 0,
			(phys_bytes *) & tp->status_mapping);

	if (!tp->hw_status)
		goto err_out;

	tp->hw_stats = 
		alloc_contig(sizeof(struct tg3_hw_stats), 0,
			(phys_bytes *) & tp->stats_mapping);

	if (!tp->hw_stats)
		goto err_out;

	memset(tp->hw_status, 0, TG3_HW_STATUS_SIZE);
	memset(tp->hw_stats, 0, sizeof(struct tg3_hw_stats));

	return 0;

err_out:
	printf("%s: Fatal error allocating memory\n", tp->name);
	tg3_free_consistent(tp);
	return -ENOMEM;
}

#define MAX_WAIT_CNT 1000

/* To stop a block, clear the enable bit and poll till it
 * clears.
 */
PRIVATE int tg3_stop_block(tg3_t * tp, unsigned long ofs, u32_t enable_bit,
		int silent)
{
	unsigned int i;
	u32_t val;

	if (tp->tg3_flags2 & TG3_FLG2_5705_PLUS) {
		switch (ofs) {
		case RCVLSC_MODE:
		case DMAC_MODE:
		case MBFREE_MODE:
		case BUFMGR_MODE:
		case MEMARB_MODE:
			/* We can't enable/disable these bits of the 5705/5750,
			 * just say success. */
			return 0;

		default:
			break;
		}
	}
	val = tr32(ofs);
	val &= ~enable_bit;
	tw32_f(ofs, val);

	for (i = 0; i < MAX_WAIT_CNT; i++) {
		micro_delay(100);
		val = tr32(ofs);
		if ((val & enable_bit) == 0)
			break;
	}

	if (i == MAX_WAIT_CNT && !silent) {
		printf("tg3_stop_block timed out, "
		       "ofs=%lx enable_bit=%x\n",
		       ofs, enable_bit);
		return -ENODEV;
	}
	return 0;
}

PRIVATE int tg3_abort_hw(tg3_t * tp, int silent)
{
	int i, err;

	tg3_disable_ints(tp);

	tp->rx_mode &= ~RX_MODE_ENABLE;
	tw32_f(MAC_RX_MODE, tp->rx_mode);
	micro_delay(10);

	err = tg3_stop_block(tp, RCVBDI_MODE, RCVBDI_MODE_ENABLE, silent);
	err |= tg3_stop_block(tp, RCVLPC_MODE, RCVLPC_MODE_ENABLE, silent);
	err |= tg3_stop_block(tp, RCVLSC_MODE, RCVLSC_MODE_ENABLE, silent);
	err |= tg3_stop_block(tp, RCVDBDI_MODE, RCVDBDI_MODE_ENABLE, silent);
	err |= tg3_stop_block(tp, RCVDCC_MODE, RCVDCC_MODE_ENABLE, silent);
	err |= tg3_stop_block(tp, RCVCC_MODE, RCVCC_MODE_ENABLE, silent);

	err |= tg3_stop_block(tp, SNDBDS_MODE, SNDBDS_MODE_ENABLE, silent);
	err |= tg3_stop_block(tp, SNDBDI_MODE, SNDBDI_MODE_ENABLE, silent);
	err |= tg3_stop_block(tp, SNDDATAI_MODE, SNDDATAI_MODE_ENABLE, silent);
	err |= tg3_stop_block(tp, RDMAC_MODE, RDMAC_MODE_ENABLE, silent);
	err |= tg3_stop_block(tp, SNDDATAC_MODE, SNDDATAC_MODE_ENABLE, silent);
	err |= tg3_stop_block(tp, DMAC_MODE, DMAC_MODE_ENABLE, silent);
	err |= tg3_stop_block(tp, SNDBDC_MODE, SNDBDC_MODE_ENABLE, silent);

	tp->mac_mode &= ~MAC_MODE_TDE_ENABLE;
	tw32_f(MAC_MODE, tp->mac_mode);

	micro_delay(40);

	tp->tx_mode &= ~TX_MODE_ENABLE;
	tw32_f(MAC_TX_MODE, tp->tx_mode);

	for (i = 0; i < MAX_WAIT_CNT; i++) {
		micro_delay(100);
		if (!(tr32(MAC_TX_MODE) & TX_MODE_ENABLE))
			break;
	}
	if (i >= MAX_WAIT_CNT) {
		printf("tg3_abort_hw timed out for %s, "
		       "TX_MODE_ENABLE will not clear MAC_TX_MODE=%08x\n",
		       tp->name, tr32(MAC_TX_MODE));
		err |= -ENODEV;
	}
	err |= tg3_stop_block(tp, HOSTCC_MODE, HOSTCC_MODE_ENABLE, silent);
	err |= tg3_stop_block(tp, WDMAC_MODE, WDMAC_MODE_ENABLE, silent);
	err |= tg3_stop_block(tp, MBFREE_MODE, MBFREE_MODE_ENABLE, silent);

	tw32(FTQ_RESET, 0xffffffff);
	tw32(FTQ_RESET, 0x00000000);

	err |= tg3_stop_block(tp, BUFMGR_MODE, BUFMGR_MODE_ENABLE, silent);
	err |= tg3_stop_block(tp, MEMARB_MODE, MEMARB_MODE_ENABLE, silent);

	if (tp->hw_status)
		memset(tp->hw_status, 0, TG3_HW_STATUS_SIZE);
	if (tp->hw_stats)
		memset(tp->hw_stats, 0, sizeof(struct tg3_hw_stats));

	return err;
}

PRIVATE void tg3_ape_send_event(tg3_t * tp, u32_t event)
{
	int i;
	u32_t apedata;

	apedata = tg3_ape_read32(tp, TG3_APE_SEG_SIG);
	if (apedata != APE_SEG_SIG_MAGIC)
		return;

	apedata = tg3_ape_read32(tp, TG3_APE_FW_STATUS);
	if (!(apedata & APE_FW_STATUS_READY))
		return;

	/* Wait for up to 1 millisecond for APE to service previous event. */
	for (i = 0; i < 10; i++) {
		if (tg3_ape_lock(tp, TG3_APE_LOCK_MEM))
			return;

		apedata = tg3_ape_read32(tp, TG3_APE_EVENT_STATUS);

		if (!(apedata & APE_EVENT_STATUS_EVENT_PENDING))
			tg3_ape_write32(tp, TG3_APE_EVENT_STATUS,
				      event | APE_EVENT_STATUS_EVENT_PENDING);

		tg3_ape_unlock(tp, TG3_APE_LOCK_MEM);

		if (!(apedata & APE_EVENT_STATUS_EVENT_PENDING))
			break;

		micro_delay(100);
	}

	if (!(apedata & APE_EVENT_STATUS_EVENT_PENDING))
		tg3_ape_write32(tp, TG3_APE_EVENT, APE_EVENT_1);
}

PRIVATE void tg3_ape_driver_state_change(tg3_t * tp, int kind)
{
	u32_t event;
	u32_t apedata;

	if (!(tp->tg3_flags3 & TG3_FLG3_ENABLE_APE))
		return;

	switch (kind) {
	case RESET_KIND_INIT:
		tg3_ape_write32(tp, TG3_APE_HOST_SEG_SIG,
				APE_HOST_SEG_SIG_MAGIC);
		tg3_ape_write32(tp, TG3_APE_HOST_SEG_LEN,
				APE_HOST_SEG_LEN_MAGIC);
		apedata = tg3_ape_read32(tp, TG3_APE_HOST_INIT_COUNT);
		tg3_ape_write32(tp, TG3_APE_HOST_INIT_COUNT, ++apedata);
		tg3_ape_write32(tp, TG3_APE_HOST_DRIVER_ID,
				APE_HOST_DRIVER_ID_MAGIC);
		tg3_ape_write32(tp, TG3_APE_HOST_BEHAVIOR,
				APE_HOST_BEHAV_NO_PHYLOCK);

		event = APE_EVENT_STATUS_STATE_START;
		break;
	case RESET_KIND_SHUTDOWN:
		/* With the interface we are currently using, APE does not
		 * track driver state.  Wiping out the HOST SEGMENT SIGNATURE
		 * forces the APE to assume OS absent status. */
		tg3_ape_write32(tp, TG3_APE_HOST_SEG_SIG, 0x0);

		event = APE_EVENT_STATUS_STATE_UNLOAD;
		break;
	case RESET_KIND_SUSPEND:
		event = APE_EVENT_STATUS_STATE_SUSPEND;
		break;
	default:
		return;
	}

	event |= APE_EVENT_STATUS_DRIVER_EVNT | APE_EVENT_STATUS_STATE_CHNGE;

	tg3_ape_send_event(tp, event);
}

PRIVATE void tg3_write_sig_pre_reset(tg3_t * tp, int kind)
{
	tg3_write_mem(tp, NIC_SRAM_FIRMWARE_MBOX,
		      NIC_SRAM_FIRMWARE_MBOX_MAGIC1);

	if (tp->tg3_flags2 & TG3_FLG2_ASF_NEW_HANDSHAKE) {
		switch (kind) {
		case RESET_KIND_INIT:
			tg3_write_mem(tp, NIC_SRAM_FW_DRV_STATE_MBOX,
				      DRV_STATE_START);
			break;

		case RESET_KIND_SHUTDOWN:
			tg3_write_mem(tp, NIC_SRAM_FW_DRV_STATE_MBOX,
				      DRV_STATE_UNLOAD);
			break;

		case RESET_KIND_SUSPEND:
			tg3_write_mem(tp, NIC_SRAM_FW_DRV_STATE_MBOX,
				      DRV_STATE_SUSPEND);
			break;

		default:
			break;
		}
	}
	if (kind == RESET_KIND_INIT ||
	    kind == RESET_KIND_SUSPEND)
		tg3_ape_driver_state_change(tp, kind);
}

PRIVATE void tg3_write_sig_post_reset(tg3_t * tp, int kind)
{
	if (tp->tg3_flags2 & TG3_FLG2_ASF_NEW_HANDSHAKE) {
		switch (kind) {
			case RESET_KIND_INIT:
			tg3_write_mem(tp, NIC_SRAM_FW_DRV_STATE_MBOX,
				      DRV_STATE_START_DONE);
			break;

		case RESET_KIND_SHUTDOWN:
			tg3_write_mem(tp, NIC_SRAM_FW_DRV_STATE_MBOX,
				      DRV_STATE_UNLOAD_DONE);
			break;

		default:
			break;
		}
	}
	if (kind == RESET_KIND_SHUTDOWN)
		tg3_ape_driver_state_change(tp, kind);
}

PRIVATE void tg3_write_sig_legacy(tg3_t * tp, int kind)
{
	if (tp->tg3_flags & TG3_FLAG_ENABLE_ASF) {
		switch (kind) {
			case RESET_KIND_INIT:
			tg3_write_mem(tp, NIC_SRAM_FW_DRV_STATE_MBOX,
				      DRV_STATE_START);
			break;

		case RESET_KIND_SHUTDOWN:
			tg3_write_mem(tp, NIC_SRAM_FW_DRV_STATE_MBOX,
				      DRV_STATE_UNLOAD);
			break;

		case RESET_KIND_SUSPEND:
			tg3_write_mem(tp, NIC_SRAM_FW_DRV_STATE_MBOX,
				      DRV_STATE_SUSPEND);
			break;

		default:
			break;
		}
	}
}

PRIVATE int tg3_poll_fw(tg3_t * tp)
{
	int i;
	u32_t val;

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) {
		/* Wait up to 20ms for init done. */
		for (i = 0; i < 200; i++) {
			if (tr32(VCPU_STATUS) & VCPU_STATUS_INIT_DONE)
				return 0;
			micro_delay(100);
		}
		return -ENODEV;
	}
	/* Wait for firmware initialization to complete. */
	for (i = 0; i < 100000; i++) {
		tg3_read_mem(tp, NIC_SRAM_FIRMWARE_MBOX, &val);
		if (val == ~NIC_SRAM_FIRMWARE_MBOX_MAGIC1)
			break;
		micro_delay(10);
	}

	/* Chip might not be fitted with firmware.  Some Sun onboard parts are
	 * configured like that.  So don't signal the timeout of the above loop
	 * as an error, but do report the lack of running firmware once. */
	if (i >= 100000 &&
	    !(tp->tg3_flags2 & TG3_FLG2_NO_FWARE_REPORTED)) {
		tp->tg3_flags2 |= TG3_FLG2_NO_FWARE_REPORTED;

		printf("%s: No firmware running.\n", tp->name);
	}
	return 0;
}

/* Save PCI command register before chip reset */
PRIVATE void tg3_save_pci_state(tg3_t * tp)
{
	tp->pci_cmd = pci_attr_r16(tp->devind, PCI_CR);
}

/* Restore PCI state after chip reset */
PRIVATE void tg3_restore_pci_state(tg3_t * tp)
{
	u32_t val;

	/* Re-enable indirect register accesses. */
	pci_attr_w32(tp->devind, TG3PCI_MISC_HOST_CTRL, tp->misc_host_ctrl);

	/* Set MAX PCI retry to zero. */
	val = (PCISTATE_ROM_ENABLE | PCISTATE_ROM_RETRY_ENABLE);
	if (tp->pci_chip_rev_id == CHIPREV_ID_5704_A0 &&
	    (tp->tg3_flags & TG3_FLAG_PCIX_MODE))
		val |= PCISTATE_RETRY_SAME_DMA;
	/* Allow reads and writes to the APE register and memory space. */
	if (tp->tg3_flags3 & TG3_FLG3_ENABLE_APE)
		val |= PCISTATE_ALLOW_APE_CTLSPC_WR |
			PCISTATE_ALLOW_APE_SHMEM_WR;
	pci_attr_w32(tp->devind, TG3PCI_PCISTATE, val);

	pci_attr_w16(tp->devind, PCI_CR, tp->pci_cmd);

	if (GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5785) {
		if (tp->tg3_flags2 & TG3_FLG2_PCI_EXPRESS) {
			pcie_set_readrq(tp->devind, 4096);
		} else {
			pci_attr_w8(tp->devind, PCI_CACHE_LINE_SIZE,
				    tp->pci_cacheline_sz);
			pci_attr_w8(tp->devind, PCI_LATENCY_TIMER,
				    tp->pci_lat_timer);
		}
	}
	/* Make sure PCI-X relaxed ordering bit is clear. */
	if (tp->tg3_flags & TG3_FLAG_PCIX_MODE) {
		u16_t pcix_cmd;

		pcix_cmd = pci_attr_r16(tp->devind, tp->cap.pcix_cap + PCI_X_CMD);
		pcix_cmd &= ~PCI_X_CMD_ERO;

		pci_attr_w16(tp->devind, tp->cap.pcix_cap + PCI_X_CMD, pcix_cmd);
	}
}

PRIVATE int tg3_chip_reset(tg3_t * tp)
{
	u32_t val;
	void (*write_op) (tg3_t *, u32_t, u32_t);
	int err;

	tg3_nvram_lock(tp);

	tg3_mdio_stop(tp);

	tg3_ape_lock(tp, TG3_APE_LOCK_GRC);

	/* No matching tg3_nvram_unlock() after this because chip reset below
	 * will undo the nvram lock. */
	tp->nvram_lock_cnt = 0;

	/* GRC_MISC_CFG core clock reset will clear the memory enable bit in
	 * PCI register 4 and the MSI enable bit on some chips, so we save
	 * relevant registers here. */
	tg3_save_pci_state(tp);

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5752 ||
	    (tp->tg3_flags3 & TG3_FLG3_5755_PLUS))
		tw32(GRC_FASTBOOT_PC, 0);


	/* We must avoid the readl() that normally takes place. It locks
	 * machines, causes machine checks, and other fun things.  So,
	 * temporarily disable the 5701 hardware workaround, while we do the
	 * reset. */
	write_op = tp->write32;
	if (write_op == tg3_write_flush_reg32)
		tp->write32 = tg3_write32;

	/* Prevent the irq handler from reading or writing PCI registers during
	 * chip reset when the memory enable bit in the PCI command register
	 * may be cleared.  The chip does not generate interrupt at this time,
	 * but the irq handler may still be called due to irq sharing or
	 * irqpoll. */
	tp->tg3_flags |= TG3_FLAG_CHIP_RESETTING;
	if (tp->hw_status) {
		tp->hw_status->status = 0;
		tp->hw_status->status_tag = 0;
	}
	tp->last_tag = 0;
	tp->last_irq_tag = 0;

	/* do the reset */
	val = GRC_MISC_CFG_CORECLK_RESET;

	if (tp->tg3_flags2 & TG3_FLG2_PCI_EXPRESS) {
		if (tr32(0x7e2c) == 0x60) {
			tw32(0x7e2c, 0x20);
		}
		if (tp->pci_chip_rev_id != CHIPREV_ID_5750_A0) {
			tw32(GRC_MISC_CFG, (1 << 29));
			val |= (1 << 29);
		}
	}
	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) {
		tw32(VCPU_STATUS, tr32(VCPU_STATUS) | VCPU_STATUS_DRV_RESET);
		tw32(GRC_VCPU_EXT_CTRL,
		     tr32(GRC_VCPU_EXT_CTRL) & ~GRC_VCPU_EXT_CTRL_HALT_CPU);
	}
	if (tp->tg3_flags2 & TG3_FLG2_5705_PLUS)
		val |= GRC_MISC_CFG_KEEP_GPHY_POWER;
	tw32(GRC_MISC_CFG, val);

	/* restore 5701 hardware bug workaround write method */
	tp->write32 = write_op;

	/* Unfortunately, we have to delay before the PCI read back. Some 575X
	 * chips even will not respond to a PCI cfg access when the reset
	 * command is given to the chip.
	 * 
	 * How do these hardware designers expect things to work properly if the
	 * PCI write is posted for a long period of time?  It is always
	 * necessary to have some method by which a register read back can
	 * occur to push the write out which does the reset.
	 * 
	 * For most tg3 variants the trick below was working. Ho hum... */
	micro_delay(120);

	/* Flush PCI posted writes.  The normal MMIO registers are inaccessible
	 * at this time so this is the only way to make this reliably
	 * (actually, this is no longer the case, see above).  I tried to use
	 * indirect register read/write but this upset some 5701 variants. */

	val = pci_attr_r32(tp->devind, PCI_CR);
	micro_delay(120);

	if ((tp->tg3_flags2 & TG3_FLG2_PCI_EXPRESS) && tp->cap.pcie_cap) {
		if (tp->pci_chip_rev_id == CHIPREV_ID_5750_A0) {
			int i;
			u32_t cfg_val;

			/* Wait for link training to complete. */
			for (i = 0; i < 5000; i++)
				micro_delay(100);

			cfg_val = pci_attr_r32(tp->devind, 0xc4);
			pci_attr_w32(tp->devind, 0xc4, cfg_val | (1 << 15));
		}
		/* Set PCIE max payload size to 128 bytes and clear the "no
		 * snoop" and "relaxed ordering" bits. */
		pci_attr_w16(tp->devind, tp->cap.pcie_cap + PCI_EXP_DEVCTL, 0);

		pcie_set_readrq(tp->devind, 4096);

		/* Clear error status */
		pci_attr_w16(tp->devind,
			     tp->cap.pcie_cap + PCI_EXP_DEVSTA,
			     PCI_EXP_DEVSTA_CED |
			     PCI_EXP_DEVSTA_NFED |
			     PCI_EXP_DEVSTA_FED |
			     PCI_EXP_DEVSTA_URD);
	}
	tg3_restore_pci_state(tp);

	tp->tg3_flags &= ~TG3_FLAG_CHIP_RESETTING;

	val = 0;
	if (tp->tg3_flags2 & TG3_FLG2_5780_CLASS)
		val = tr32(MEMARB_MODE);
	tw32(MEMARB_MODE, val | MEMARB_MODE_ENABLE);

	if (tp->pci_chip_rev_id == CHIPREV_ID_5750_A3) {
		tg3_stop_fw(tp);
		tw32(0x5000, 0x400);
	}
	tw32(GRC_MODE, tp->grc_mode);

	if (tp->pci_chip_rev_id == CHIPREV_ID_5705_A0) {
		val = tr32(0xc4);

		tw32(0xc4, val | (1 << 15));
	}
	if ((tp->nic_sram_data_cfg & NIC_SRAM_DATA_CFG_MINI_PCI) != 0 &&
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5705) {
		tp->pci_clock_ctrl |= CLOCK_CTRL_CLKRUN_OENABLE;
		if (tp->pci_chip_rev_id == CHIPREV_ID_5705_A0)
			tp->pci_clock_ctrl |= CLOCK_CTRL_FORCE_CLKRUN;
		tw32(TG3PCI_CLOCK_CTRL, tp->pci_clock_ctrl);
	}
	if (tp->tg3_flags2 & TG3_FLG2_PHY_SERDES) {
		tp->mac_mode = MAC_MODE_PORT_MODE_TBI;
		tw32_f(MAC_MODE, tp->mac_mode);
	} else if (tp->tg3_flags2 & TG3_FLG2_MII_SERDES) {
		tp->mac_mode = MAC_MODE_PORT_MODE_GMII;
		tw32_f(MAC_MODE, tp->mac_mode);
	} else if (tp->tg3_flags3 & TG3_FLG3_ENABLE_APE) {
		tp->mac_mode &= (MAC_MODE_APE_TX_EN | MAC_MODE_APE_RX_EN);
		if (tp->mac_mode & MAC_MODE_APE_TX_EN)
			tp->mac_mode |= MAC_MODE_TDE_ENABLE;
		tw32_f(MAC_MODE, tp->mac_mode);
	} else
		tw32_f(MAC_MODE, 0);

	micro_delay(40);

	tg3_mdio_start(tp);

	tg3_ape_unlock(tp, TG3_APE_LOCK_GRC);

	err = tg3_poll_fw(tp);
	if (err)
		return err;

	if ((tp->tg3_flags2 & TG3_FLG2_PCI_EXPRESS) &&
	    tp->pci_chip_rev_id != CHIPREV_ID_5750_A0) {
		val = tr32(0x7c00);

		tw32(0x7c00, val | (1 << 25));
	}
	/* Reprobe ASF enable state. */
	tp->tg3_flags &= ~TG3_FLAG_ENABLE_ASF;
	tp->tg3_flags2 &= ~TG3_FLG2_ASF_NEW_HANDSHAKE;
	tg3_read_mem(tp, NIC_SRAM_DATA_SIG, &val);
	if (val == NIC_SRAM_DATA_SIG_MAGIC) {
		u32_t nic_cfg;

		tg3_read_mem(tp, NIC_SRAM_DATA_CFG, &nic_cfg);
		if (nic_cfg & NIC_SRAM_DATA_CFG_ASF_ENABLE) {
			tp->tg3_flags |= TG3_FLAG_ENABLE_ASF;
			if (tp->tg3_flags2 & TG3_FLG2_5750_PLUS)
				tp->tg3_flags2 |= TG3_FLG2_ASF_NEW_HANDSHAKE;
		}
	}
	return 0;
}

PRIVATE void tg3_stop_fw(tg3_t * tp)
{
	if ((tp->tg3_flags & TG3_FLAG_ENABLE_ASF) &&
	    !(tp->tg3_flags3 & TG3_FLG3_ENABLE_APE)) {
		/* Wait for RX cpu to ACK the previous event. */
		tg3_wait_for_event_ack(tp);

		tg3_write_mem(tp, NIC_SRAM_FW_CMD_MBOX, FWCMD_NICDRV_PAUSE_FW);

		tg3_generate_fw_event(tp);

		/* Wait for RX cpu to ACK this event. */
		tg3_wait_for_event_ack(tp);
	}
}

PRIVATE int tg3_halt(tg3_t * tp, int kind, int silent)
{
	int err;

	tg3_stop_fw(tp);

	tg3_write_sig_pre_reset(tp, kind);

	tg3_abort_hw(tp, silent);
	err = tg3_chip_reset(tp);

	__tg3_set_mac_addr(tp, 0);

	tg3_write_sig_legacy(tp, kind);
	tg3_write_sig_post_reset(tp, kind);

	if (err)
		return err;

	return 0;
}

PRIVATE int tg3_halt_cpu(tg3_t * tp, u32_t offset)
{
	int i;

	assert(!(offset == TX_CPU_BASE &&
		 (tp->tg3_flags2 & TG3_FLG2_5705_PLUS)));

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) {
		u32_t val = tr32(GRC_VCPU_EXT_CTRL);

		tw32(GRC_VCPU_EXT_CTRL, val | GRC_VCPU_EXT_CTRL_HALT_CPU);
		return 0;
	}
	if (offset == RX_CPU_BASE) {
		for (i = 0; i < 10000; i++) {
			tw32(offset + CPU_STATE, 0xffffffff);
			tw32(offset + CPU_MODE, CPU_MODE_HALT);
			if (tr32(offset + CPU_MODE) & CPU_MODE_HALT)
				break;
		}

		tw32(offset + CPU_STATE, 0xffffffff);
		tw32_f(offset + CPU_MODE, CPU_MODE_HALT);
		micro_delay(10);
	} else {
		for (i = 0; i < 10000; i++) {
			tw32(offset + CPU_STATE, 0xffffffff);
			tw32(offset + CPU_MODE, CPU_MODE_HALT);
			if (tr32(offset + CPU_MODE) & CPU_MODE_HALT)
				break;
		}
	}

	if (i >= 10000) {
		printf("tg3_reset_cpu timed out for %s, "
		       "and %s CPU\n",
		       tp->name,
		       (offset == RX_CPU_BASE ? "RX" : "TX"));
		return -ENODEV;
	}
	/* Clear firmware's nvram arbitration. */
	if (tp->tg3_flags & TG3_FLAG_NVRAM)
		tw32(NVRAM_SWARB, SWARB_REQ_CLR0);
	return 0;
}

PRIVATE int tg3_load_5701_a0_firmware_fix(tg3_t * tp)
{
	panic("TG3", "tg3_load_5701_a0_firmware_fix: \
		TG3 Driver does not currently support loading fimrware\n", 0);
	return 0;
}

/* 5705 needs a special version of the TSO firmware.  */
PRIVATE int tg3_load_tso_firmware(tg3_t * tp)
{
	if (tp->tg3_flags2 & TG3_FLG2_HW_TSO) {
		return 0;
	}
	panic("TG3", "tg3_load_tso_firmware: \
		TG3 Driver does not currently support loading fimrware\n", 0);

	return 1;
}

PRIVATE int tg3_set_mac_addr(tg3_t * tp)
{
	int err = 0, skip_mac_1 = 0;

	if (!is_valid_ether_addr(tp->mac_address.ea_addr))
		return -EINVAL;

	if (!tg3_enabled(tp))
		return 0;

	if (tp->tg3_flags & TG3_FLAG_ENABLE_ASF) {
		u32_t addr0_high, addr0_low, addr1_high, addr1_low;

		addr0_high = tr32(MAC_ADDR_0_HIGH);
		addr0_low = tr32(MAC_ADDR_0_LOW);
		addr1_high = tr32(MAC_ADDR_1_HIGH);
		addr1_low = tr32(MAC_ADDR_1_LOW);

		/* Skip MAC addr 1 if ASF is using it. */
		if ((addr0_high != addr1_high || addr0_low != addr1_low) &&
		    !(addr1_high == 0 && addr1_low == 0))
			skip_mac_1 = 1;
	}
	__tg3_set_mac_addr(tp, skip_mac_1);

	return err;
}

PRIVATE void tg3_set_bdinfo(tg3_t * tp, u32_t bdinfo_addr,
			     vir_bytes mapping, u32_t maxlen_flags,
			     u32_t nic_addr)
{
	tg3_write_mem(tp,
		    (bdinfo_addr + TG3_BDINFO_HOST_ADDR + TG3_64BIT_REG_HIGH),
		      0);	/* Top 32 bits of address is always 0 in 32 bit */
	tg3_write_mem(tp,
		      (bdinfo_addr + TG3_BDINFO_HOST_ADDR + TG3_64BIT_REG_LOW),
		      mapping);
	tg3_write_mem(tp,
		      (bdinfo_addr + TG3_BDINFO_MAXLEN_FLAGS),
		      maxlen_flags);

	if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS))
		tg3_write_mem(tp,
			      (bdinfo_addr + TG3_BDINFO_NIC_ADDR),
			      nic_addr);
}

PRIVATE void __tg3_set_coalesce(tg3_t * tp, struct coalesce * ec)
{

	tw32(HOSTCC_RXCOL_TICKS, ec->rx_coalesce_usecs);
	tw32(HOSTCC_TXCOL_TICKS, ec->tx_coalesce_usecs);
	tw32(HOSTCC_RXMAX_FRAMES, ec->rx_max_coalesced_frames);
	tw32(HOSTCC_TXMAX_FRAMES, ec->tx_max_coalesced_frames);
	if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS)) {
		tw32(HOSTCC_RXCOAL_TICK_INT, ec->rx_coalesce_usecs_irq);
		tw32(HOSTCC_TXCOAL_TICK_INT, ec->tx_coalesce_usecs_irq);
	}
	tw32(HOSTCC_RXCOAL_MAXF_INT, ec->rx_max_coalesced_frames_irq);
	tw32(HOSTCC_TXCOAL_MAXF_INT, ec->tx_max_coalesced_frames_irq);
	if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS)) {
		u32_t val = ec->stats_block_coalesce_usecs;

		if (!carrier_ok(tp))
			val = 0;

		tw32(HOSTCC_STAT_COAL_TICKS, val);
	}
}

PRIVATE int tg3_reset_hw(tg3_t * tp, int reset_phy)
{
	u32_t val, rdmac_mode;
	int i, err, limit;

	tg3_disable_ints(tp);

	tg3_stop_fw(tp);

	tg3_write_sig_pre_reset(tp, RESET_KIND_INIT);

	if (tp->tg3_flags & TG3_FLAG_INIT_COMPLETE) {
		tg3_abort_hw(tp, 1);
	}
	if (reset_phy &&
	    !(tp->tg3_flags3 & TG3_FLG3_USE_PHYLIB))
		tg3_phy_reset(tp);

	err = tg3_chip_reset(tp);
	if (err)
		return err;

	tg3_write_sig_legacy(tp, RESET_KIND_INIT);

	if (GET_CHIP_REV(tp->pci_chip_rev_id) == CHIPREV_5784_AX) {
		val = tr32(TG3_CPMU_CTRL);
		val &= ~(CPMU_CTRL_LINK_AWARE_MODE | CPMU_CTRL_LINK_IDLE_MODE);
		tw32(TG3_CPMU_CTRL, val);

		val = tr32(TG3_CPMU_LSPD_10MB_CLK);
		val &= ~CPMU_LSPD_10MB_MACCLK_MASK;
		val |= CPMU_LSPD_10MB_MACCLK_6_25;
		tw32(TG3_CPMU_LSPD_10MB_CLK, val);

		val = tr32(TG3_CPMU_LNK_AWARE_PWRMD);
		val &= ~CPMU_LNK_AWARE_MACCLK_MASK;
		val |= CPMU_LNK_AWARE_MACCLK_6_25;
		tw32(TG3_CPMU_LNK_AWARE_PWRMD, val);

		val = tr32(TG3_CPMU_HST_ACC);
		val &= ~CPMU_HST_ACC_MACCLK_MASK;
		val |= CPMU_HST_ACC_MACCLK_6_25;
		tw32(TG3_CPMU_HST_ACC, val);
	}
	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_57780) {
		val = tr32(PCIE_PWR_MGMT_THRESH) & ~PCIE_PWR_MGMT_L1_THRESH_MSK;
		val |= PCIE_PWR_MGMT_EXT_ASPM_TMR_EN |
			PCIE_PWR_MGMT_L1_THRESH_4MS;
		tw32(PCIE_PWR_MGMT_THRESH, val);
	}
	/* This works around an issue with Athlon chipsets on B3 tigon3
	 * silicon.  This bit has no effect on any other revision.  But do not
	 * set this on PCI Express chips and don't even touch the clocks if the
	 * CPMU is present. */
	if (!(tp->tg3_flags & TG3_FLAG_CPMU_PRESENT)) {
		if (!(tp->tg3_flags2 & TG3_FLG2_PCI_EXPRESS))
			tp->pci_clock_ctrl |= CLOCK_CTRL_DELAY_PCI_GRANT;
		tw32_f(TG3PCI_CLOCK_CTRL, tp->pci_clock_ctrl);
	}
	if (tp->pci_chip_rev_id == CHIPREV_ID_5704_A0 &&
	    (tp->tg3_flags & TG3_FLAG_PCIX_MODE)) {
		val = tr32(TG3PCI_PCISTATE);
		val |= PCISTATE_RETRY_SAME_DMA;
		tw32(TG3PCI_PCISTATE, val);
	}
	if (tp->tg3_flags3 & TG3_FLG3_ENABLE_APE) {
		/* Allow reads and writes to the APE register and memory space*/
		val = tr32(TG3PCI_PCISTATE);
		val |= PCISTATE_ALLOW_APE_CTLSPC_WR |
			PCISTATE_ALLOW_APE_SHMEM_WR;
		tw32(TG3PCI_PCISTATE, val);
	}
	if (GET_CHIP_REV(tp->pci_chip_rev_id) == CHIPREV_5704_BX) {
		/* Enable some hw fixes.  */
		val = tr32(TG3PCI_MSI_DATA);
		val |= (1 << 26) | (1 << 28) | (1 << 29);
		tw32(TG3PCI_MSI_DATA, val);
	}
	/* Descriptor ring init may make accesses to the NIC SRAM area to setup
	 * the TX descriptors, so we can only do this after the hardware has
	 * been successfully reset. */
	err = tg3_init_rings(tp);
	if (err)
		return err;

	if (GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5784 &&
	    GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5761) {
		/* This value is determined during the probe time DMA engine
		 * test, tg3_test_dma. */
		tw32(TG3PCI_DMA_RW_CTRL, tp->dma_rwctrl);
	}
	tp->grc_mode &= ~(GRC_MODE_HOST_SENDBDS |
			  GRC_MODE_4X_NIC_SEND_RINGS |
			  GRC_MODE_NO_TX_PHDR_CSUM |
			  GRC_MODE_NO_RX_PHDR_CSUM);
	tp->grc_mode |= GRC_MODE_HOST_SENDBDS;

	/* Pseudo-header checksum is done by hardware logic and not the offload
	 * processers, so make the chip do the pseudo- header checksums on
	 * receive.  For transmit it is more convenient to do the pseudo-header
	 * checksum in software as Linux does that on transmit for us in all
	 * cases. */
	tp->grc_mode |= GRC_MODE_NO_TX_PHDR_CSUM;

	tw32(GRC_MODE,
	     tp->grc_mode |
	     (GRC_MODE_IRQ_ON_MAC_ATTN | GRC_MODE_HOST_STACKUP));

	/* Setup the timer prescalar register.  Clock is always 66Mhz. */
	val = tr32(GRC_MISC_CFG);
	val &= ~0xff;
	val |= (65 << GRC_MISC_CFG_PRESCALAR_SHIFT);
	tw32(GRC_MISC_CFG, val);

	/* Initialize MBUF/DESC pool. */
	if (tp->tg3_flags2 & TG3_FLG2_5750_PLUS) {
		/* Do nothing.  */
	} else if (GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5705) {
		tw32(BUFMGR_MB_POOL_ADDR, NIC_SRAM_MBUF_POOL_BASE);
		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5704)
			tw32(BUFMGR_MB_POOL_SIZE, NIC_SRAM_MBUF_POOL_SIZE64);
		else
			tw32(BUFMGR_MB_POOL_SIZE, NIC_SRAM_MBUF_POOL_SIZE96);
		tw32(BUFMGR_DMA_DESC_POOL_ADDR, NIC_SRAM_DMA_DESC_POOL_BASE);
		tw32(BUFMGR_DMA_DESC_POOL_SIZE, NIC_SRAM_DMA_DESC_POOL_SIZE);
	} else if (tp->tg3_flags2 & TG3_FLG2_TSO_CAPABLE) {
		int fw_len;

		fw_len = tp->fw_len;
		fw_len = (fw_len + (0x80 - 1)) & ~(0x80 - 1);
		tw32(BUFMGR_MB_POOL_ADDR,
		     NIC_SRAM_MBUF_POOL_BASE5705 + fw_len);
		tw32(BUFMGR_MB_POOL_SIZE,
		     NIC_SRAM_MBUF_POOL_SIZE5705 - fw_len - 0xa00);
	}
	/* On Minix we've hardwired the mtu to 1500. However, in order to allow
	 * for future work on jumbo packets, this code is here */
#define ETH_DATA_LEN    1500
	if (tp->mtu <= ETH_DATA_LEN) {
		tw32(BUFMGR_MB_RDMA_LOW_WATER,
		     tp->bufmgr_config.mbuf_read_dma_low_water);
		tw32(BUFMGR_MB_MACRX_LOW_WATER,
		     tp->bufmgr_config.mbuf_mac_rx_low_water);
		tw32(BUFMGR_MB_HIGH_WATER,
		     tp->bufmgr_config.mbuf_high_water);
	} else {
		tw32(BUFMGR_MB_RDMA_LOW_WATER,
		     tp->bufmgr_config.mbuf_read_dma_low_water_jumbo);
		tw32(BUFMGR_MB_MACRX_LOW_WATER,
		     tp->bufmgr_config.mbuf_mac_rx_low_water_jumbo);
		tw32(BUFMGR_MB_HIGH_WATER,
		     tp->bufmgr_config.mbuf_high_water_jumbo);
	}
	tw32(BUFMGR_DMA_LOW_WATER,
	     tp->bufmgr_config.dma_low_water);
	tw32(BUFMGR_DMA_HIGH_WATER,
	     tp->bufmgr_config.dma_high_water);

	tw32(BUFMGR_MODE, BUFMGR_MODE_ENABLE | BUFMGR_MODE_ATTN_ENABLE);
	for (i = 0; i < 2000; i++) {
		if (tr32(BUFMGR_MODE) & BUFMGR_MODE_ENABLE)
			break;
		micro_delay(10);
	}
	if (i >= 2000) {
		printf("tg3_reset_hw cannot enable BUFMGR for %s.\n", tp->name);
		return -ENODEV;
	}
	/* Setup replenish threshold. */
	val = tp->rx_pending / 8;
	if (val == 0)
		val = 1;
	else if (val > tp->rx_std_max_post)
		val = tp->rx_std_max_post;
	else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) {
		if (tp->pci_chip_rev_id == CHIPREV_ID_5906_A1)
			tw32(ISO_PKT_TX, (tr32(ISO_PKT_TX) & ~0x3) | 0x2);

		if (val > (TG3_RX_INTERNAL_RING_SZ_5906 / 2))
			val = TG3_RX_INTERNAL_RING_SZ_5906 / 2;
	}
	tw32(RCVBDI_STD_THRESH, val);

	/* Initialize TG3_BDINFO's at: RCVDBDI_STD_BD:	standard eth size rx
	 * ring RCVDBDI_JUMBO_BD:jumbo frame rx ring RCVDBDI_MINI_BD:
	 * small frame rx ring (??? does not work)
	 * 
	 * like so: TG3_BDINFO_HOST_ADDR:high/low parts of DMA address of ring
	 * TG3_BDINFO_MAXLEN_FLAGS:(rx max buffer size << 16) | ring
	 * attribute flags TG3_BDINFO_NIC_ADDR:	location of descriptors in nic
	 * SRAM
	 * 
	 * Standard receive ring @ NIC_SRAM_RX_BUFFER_DESC, 512 entries. Jumbo
	 * receive ring @ NIC_SRAM_RX_JUMBO_BUFFER_DESC, 256 entries.
	 * 
	 * The size of each ring is fixed in the firmware, but the location is
	 * configurable. */
	tw32(RCVDBDI_STD_BD + TG3_BDINFO_HOST_ADDR + TG3_64BIT_REG_HIGH,
	     0);		/* Minix is 32 bits so top bits are always 0 */
	tw32(RCVDBDI_STD_BD + TG3_BDINFO_HOST_ADDR + TG3_64BIT_REG_LOW,
	     tp->rx_std_mapping);
	tw32(RCVDBDI_STD_BD + TG3_BDINFO_NIC_ADDR,
	     NIC_SRAM_RX_BUFFER_DESC);

	/* Don't even try to program the JUMBO/MINI buffer descriptor configs
	 * on 5705. */
	if (tp->tg3_flags2 & TG3_FLG2_5705_PLUS) {
		tw32(RCVDBDI_STD_BD + TG3_BDINFO_MAXLEN_FLAGS,
		     RX_STD_MAX_SIZE_5705 << BDINFO_FLAGS_MAXLEN_SHIFT);
	} else {
		tw32(RCVDBDI_STD_BD + TG3_BDINFO_MAXLEN_FLAGS,
		     RX_STD_MAX_SIZE << BDINFO_FLAGS_MAXLEN_SHIFT);

		tw32(RCVDBDI_MINI_BD + TG3_BDINFO_MAXLEN_FLAGS,
		     BDINFO_FLAGS_DISABLED);

		/* Setup replenish threshold. */
		tw32(RCVBDI_JUMBO_THRESH, tp->rx_jumbo_pending / 8);

		if (tp->tg3_flags & TG3_FLAG_JUMBO_RING_ENABLE) {
			tw32(RCVDBDI_JUMBO_BD + TG3_BDINFO_HOST_ADDR + TG3_64BIT_REG_HIGH,
			     0);/* Minix is 32bit so top 32bits are always 0 */
			tw32(RCVDBDI_JUMBO_BD + TG3_BDINFO_HOST_ADDR + TG3_64BIT_REG_LOW,
			     tp->rx_jumbo_mapping);
			tw32(RCVDBDI_JUMBO_BD + TG3_BDINFO_MAXLEN_FLAGS,
			     RX_JUMBO_MAX_SIZE << BDINFO_FLAGS_MAXLEN_SHIFT);
			tw32(RCVDBDI_JUMBO_BD + TG3_BDINFO_NIC_ADDR,
			     NIC_SRAM_RX_JUMBO_BUFFER_DESC);
		} else {
			tw32(RCVDBDI_JUMBO_BD + TG3_BDINFO_MAXLEN_FLAGS,
			     BDINFO_FLAGS_DISABLED);
		}

	}

	/* There is only one send ring on 5705/5750, no need to explicitly
	 * disable the others. */
	if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS)) {
		/* Clear out send RCB ring in SRAM. */
		for (i = NIC_SRAM_SEND_RCB; i < NIC_SRAM_RCV_RET_RCB;
				i += TG3_BDINFO_SIZE)
			tg3_write_mem(tp, i + TG3_BDINFO_MAXLEN_FLAGS,
				      BDINFO_FLAGS_DISABLED);
	}
	tp->tx_prod = 0;
	tp->tx_cons = 0;
	tw32_mailbox(MAILBOX_SNDHOST_PROD_IDX_0 + TG3_64BIT_REG_LOW, 0);
	tw32_tx_mbox(MAILBOX_SNDNIC_PROD_IDX_0 + TG3_64BIT_REG_LOW, 0);

	tg3_set_bdinfo(tp, NIC_SRAM_SEND_RCB,
		       tp->tx_desc_mapping,
		       (TG3_TX_RING_SIZE <<
			BDINFO_FLAGS_MAXLEN_SHIFT),
		       NIC_SRAM_TX_BUFFER_DESC);

	/* There is only one receive return ring on 5705/5750, no need to
	 * explicitly disable the others. */
	if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS)) {
		for (i = NIC_SRAM_RCV_RET_RCB; i < NIC_SRAM_STATS_BLK;
		     i += TG3_BDINFO_SIZE) {
			tg3_write_mem(tp, i + TG3_BDINFO_MAXLEN_FLAGS,
				      BDINFO_FLAGS_DISABLED);
		}
	}
	tp->rx_rcb_ptr = 0;
	tw32_rx_mbox(MAILBOX_RCVRET_CON_IDX_0 + TG3_64BIT_REG_LOW, 0);
	tg3_set_bdinfo(tp, NIC_SRAM_RCV_RET_RCB,
		       tp->rx_rcb_mapping,
		       (TG3_RX_RCB_RING_SIZE(tp) <<
			BDINFO_FLAGS_MAXLEN_SHIFT),
		       0);

	tp->rx_std_ptr = tp->rx_pending;
	tw32_rx_mbox(MAILBOX_RCV_STD_PROD_IDX + TG3_64BIT_REG_LOW,
		     tp->rx_std_ptr);

	tp->rx_jumbo_ptr = (tp->tg3_flags & TG3_FLAG_JUMBO_RING_ENABLE) ?
		tp->rx_jumbo_pending : 0;
	tw32_rx_mbox(MAILBOX_RCV_JUMBO_PROD_IDX + TG3_64BIT_REG_LOW,
		     tp->rx_jumbo_ptr);

	/* Initialize MAC address and backoff seed. */
	__tg3_set_mac_addr(tp, 0);

	/* MTU + ethernet header + FCS + optional VLAN tag */
	tw32(MAC_RX_MTU_SIZE,
	     tp->mtu + ETH_HLEN + ETH_FCS_LEN + VLAN_HLEN);

	/* The slot time is changed by tg3_setup_phy if we run at gigabit with
	 * half duplex. */
	tw32(MAC_TX_LENGTHS,
	     (2 << TX_LENGTHS_IPG_CRS_SHIFT) |
	     (6 << TX_LENGTHS_IPG_SHIFT) |
	     (32 << TX_LENGTHS_SLOT_TIME_SHIFT));

	/* Receive rules. */
	tw32(MAC_RCV_RULE_CFG, RCV_RULE_CFG_DEFAULT_CLASS);
	tw32(RCVLPC_CONFIG, 0x0181);

	/* Calculate RDMAC_MODE setting early, we need it to determine the
	 * RCVLPC_STATE_ENABLE mask. */
	rdmac_mode = (RDMAC_MODE_ENABLE | RDMAC_MODE_TGTABORT_ENAB |
		      RDMAC_MODE_MSTABORT_ENAB | RDMAC_MODE_PARITYERR_ENAB |
		      RDMAC_MODE_ADDROFLOW_ENAB | RDMAC_MODE_FIFOOFLOW_ENAB |
		      RDMAC_MODE_FIFOURUN_ENAB | RDMAC_MODE_FIFOOREAD_ENAB |
		      RDMAC_MODE_LNGREAD_ENAB);

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5784 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5785 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_57780)
		rdmac_mode |= RDMAC_MODE_BD_SBD_CRPT_ENAB |
			RDMAC_MODE_MBUF_RBD_CRPT_ENAB |
			RDMAC_MODE_MBUF_SBD_CRPT_ENAB;

	/* If statement applies to 5705 and 5750 PCI devices only */
	if ((GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5705 &&
	     tp->pci_chip_rev_id != CHIPREV_ID_5705_A0) ||
	    (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5750)) {
		if (tp->tg3_flags2 & TG3_FLG2_TSO_CAPABLE &&
		    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5705) {
			rdmac_mode |= RDMAC_MODE_FIFO_SIZE_128;
		} else if (!(tr32(TG3PCI_PCISTATE) & PCISTATE_BUS_SPEED_HIGH) &&
			   !(tp->tg3_flags2 & TG3_FLG2_IS_5788)) {
			rdmac_mode |= RDMAC_MODE_FIFO_LONG_BURST;
		}
	}
	if (tp->tg3_flags2 & TG3_FLG2_PCI_EXPRESS)
		rdmac_mode |= RDMAC_MODE_FIFO_LONG_BURST;

	if (tp->tg3_flags2 & TG3_FLG2_HW_TSO)
		rdmac_mode |= RDMAC_MODE_IPV4_LSO_EN;

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5785 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_57780)
		rdmac_mode |= RDMAC_MODE_IPV6_LSO_EN;

	/* Receive/send statistics. */
	if (tp->tg3_flags2 & TG3_FLG2_5750_PLUS) {
		val = tr32(RCVLPC_STATS_ENABLE);
		val &= ~RCVLPC_STATSENAB_DACK_FIX;
		tw32(RCVLPC_STATS_ENABLE, val);
	} else if ((rdmac_mode & RDMAC_MODE_FIFO_SIZE_128) &&
		   (tp->tg3_flags2 & TG3_FLG2_TSO_CAPABLE)) {
		val = tr32(RCVLPC_STATS_ENABLE);
		val &= ~RCVLPC_STATSENAB_LNGBRST_RFIX;
		tw32(RCVLPC_STATS_ENABLE, val);
	} else {
		tw32(RCVLPC_STATS_ENABLE, 0xffffff);
	}
	tw32(RCVLPC_STATSCTRL, RCVLPC_STATSCTRL_ENABLE);
	tw32(SNDDATAI_STATSENAB, 0xffffff);
	tw32(SNDDATAI_STATSCTRL,
	     (SNDDATAI_SCTRL_ENABLE |
	      SNDDATAI_SCTRL_FASTUPD));

	/* Setup host coalescing engine. */
	tw32(HOSTCC_MODE, 0);
	for (i = 0; i < 2000; i++) {
		if (!(tr32(HOSTCC_MODE) & HOSTCC_MODE_ENABLE))
			break;
		micro_delay(10);
	}

	__tg3_set_coalesce(tp, &tp->coal);

	/* set status block DMA address */
	tw32(HOSTCC_STATUS_BLK_HOST_ADDR + TG3_64BIT_REG_HIGH,
	     0);		/* Minix is 32bit so top 32bits are always 0 */
	tw32(HOSTCC_STATUS_BLK_HOST_ADDR + TG3_64BIT_REG_LOW,
	     tp->status_mapping);

	if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS)) {
		/* Status/statistics block address.  See tg3_timer, the
		 * tg3_periodic_fetch_stats call there, and tg3_get_stats to
		 * see how this works for 5705/5750 chips. */
		tw32(HOSTCC_STATS_BLK_HOST_ADDR + TG3_64BIT_REG_HIGH,
		     0);	/* Minix is 32 bit */
		tw32(HOSTCC_STATS_BLK_HOST_ADDR + TG3_64BIT_REG_LOW,
		     tp->stats_mapping);
		tw32(HOSTCC_STATS_BLK_NIC_ADDR, NIC_SRAM_STATS_BLK);
		tw32(HOSTCC_STATUS_BLK_NIC_ADDR, NIC_SRAM_STATUS_BLK);
	}
	tw32(HOSTCC_MODE, HOSTCC_MODE_ENABLE | tp->coalesce_mode);

	tw32(RCVCC_MODE, RCVCC_MODE_ENABLE | RCVCC_MODE_ATTN_ENABLE);
	tw32(RCVLPC_MODE, RCVLPC_MODE_ENABLE);
	if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS))
		tw32(RCVLSC_MODE, RCVLSC_MODE_ENABLE | RCVLSC_MODE_ATTN_ENABLE);

	/* Clear statistics/status block in chip, and status block in ram. */
	for (i = NIC_SRAM_STATS_BLK;
	     i < NIC_SRAM_STATUS_BLK + TG3_HW_STATUS_SIZE;
	     i += sizeof(u32_t)) {
		tg3_write_mem(tp, i, 0);
		micro_delay(40);
	}
	memset(tp->hw_status, 0, TG3_HW_STATUS_SIZE);

	if (tp->tg3_flags2 & TG3_FLG2_MII_SERDES) {
		tp->tg3_flags2 &= ~TG3_FLG2_PARALLEL_DETECT;
		/* reset to prevent losing 1st rx packet intermittently */
		tw32_f(MAC_RX_MODE, RX_MODE_RESET);
		micro_delay(10);
	}
	if (tp->tg3_flags3 & TG3_FLG3_ENABLE_APE)
		tp->mac_mode &= MAC_MODE_APE_TX_EN | MAC_MODE_APE_RX_EN;
	else
		tp->mac_mode = 0;
	tp->mac_mode |= MAC_MODE_TXSTAT_ENABLE | MAC_MODE_RXSTAT_ENABLE |
		MAC_MODE_TDE_ENABLE | MAC_MODE_RDE_ENABLE | MAC_MODE_FHDE_ENABLE;
	if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS) &&
	    !(tp->tg3_flags2 & TG3_FLG2_PHY_SERDES) &&
	    GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5700)
		tp->mac_mode |= MAC_MODE_LINK_POLARITY;
	tw32_f(MAC_MODE,
		tp->mac_mode | MAC_MODE_RXSTAT_CLEAR | MAC_MODE_TXSTAT_CLEAR);
	micro_delay(40);

	/* tp->grc_local_ctrl is partially set up during tg3_get_invariants().
	 * If TG3_FLG2_IS_NIC is zero, we should read the register to preserve
	 * the GPIO settings for LOMs. The GPIOs, whether used as inputs or
	 * outputs, are set by boot code after reset. */
	if (!(tp->tg3_flags2 & TG3_FLG2_IS_NIC)) {
		u32_t gpio_mask;

		gpio_mask = GRC_LCLCTRL_GPIO_OE0 | GRC_LCLCTRL_GPIO_OE1 |
			GRC_LCLCTRL_GPIO_OE2 | GRC_LCLCTRL_GPIO_OUTPUT0 |
			GRC_LCLCTRL_GPIO_OUTPUT1 | GRC_LCLCTRL_GPIO_OUTPUT2;

		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5752)
			gpio_mask |= GRC_LCLCTRL_GPIO_OE3 |
				GRC_LCLCTRL_GPIO_OUTPUT3;

		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5755)
			gpio_mask |= GRC_LCLCTRL_GPIO_UART_SEL;

		tp->grc_local_ctrl &= ~gpio_mask;
		tp->grc_local_ctrl |= tr32(GRC_LOCAL_CTRL) & gpio_mask;

		/* GPIO1 must be driven high for eeprom write protect */
		if (tp->tg3_flags & TG3_FLAG_EEPROM_WRITE_PROT)
			tp->grc_local_ctrl |= (GRC_LCLCTRL_GPIO_OE1 |
					       GRC_LCLCTRL_GPIO_OUTPUT1);
	}
	tw32_f(GRC_LOCAL_CTRL, tp->grc_local_ctrl);
	micro_delay(100);

	tw32_mailbox_f(MAILBOX_INTERRUPT_0 + TG3_64BIT_REG_LOW, 0);

	if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS)) {
		tw32_f(DMAC_MODE, DMAC_MODE_ENABLE);
		micro_delay(40);
	}
	val = (WDMAC_MODE_ENABLE | WDMAC_MODE_TGTABORT_ENAB |
	       WDMAC_MODE_MSTABORT_ENAB | WDMAC_MODE_PARITYERR_ENAB |
	       WDMAC_MODE_ADDROFLOW_ENAB | WDMAC_MODE_FIFOOFLOW_ENAB |
	       WDMAC_MODE_FIFOURUN_ENAB | WDMAC_MODE_FIFOOREAD_ENAB |
	       WDMAC_MODE_LNGREAD_ENAB);

	/* If statement applies to 5705 and 5750 PCI devices only */
	if ((GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5705 &&
	     tp->pci_chip_rev_id != CHIPREV_ID_5705_A0) ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5750) {
		if ((tp->tg3_flags & TG3_FLG2_TSO_CAPABLE) &&
		    (tp->pci_chip_rev_id == CHIPREV_ID_5705_A1 ||
		     tp->pci_chip_rev_id == CHIPREV_ID_5705_A2)) {
			/* nothing */
		} else if (!(tr32(TG3PCI_PCISTATE) & PCISTATE_BUS_SPEED_HIGH) &&
			   !(tp->tg3_flags2 & TG3_FLG2_IS_5788) &&
			   !(tp->tg3_flags2 & TG3_FLG2_PCI_EXPRESS)) {
			val |= WDMAC_MODE_RX_ACCEL;
		}
	}
	/* Enable host coalescing bug fix */
	if (tp->tg3_flags3 & TG3_FLG3_5755_PLUS)
		val |= WDMAC_MODE_STATUS_TAG_FIX;

	tw32_f(WDMAC_MODE, val);
	micro_delay(40);

	if (tp->tg3_flags & TG3_FLAG_PCIX_MODE) {
		u16_t pcix_cmd;

		pcix_cmd = pci_attr_r16(tp->devind, tp->cap.pcix_cap + PCI_X_CMD);
		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5703) {
			pcix_cmd &= ~PCI_X_CMD_MAX_READ;
			pcix_cmd |= PCI_X_CMD_READ_2K;
		} else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5704) {
			pcix_cmd &= ~(PCI_X_CMD_MAX_SPLIT | PCI_X_CMD_MAX_READ);
			pcix_cmd |= PCI_X_CMD_READ_2K;
		}
		pci_attr_w16(tp->devind, tp->cap.pcix_cap + PCI_X_CMD, pcix_cmd);
	}
	tw32_f(RDMAC_MODE, rdmac_mode);
	micro_delay(40);

	tw32(RCVDCC_MODE, RCVDCC_MODE_ENABLE | RCVDCC_MODE_ATTN_ENABLE);
	if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS))
		tw32(MBFREE_MODE, MBFREE_MODE_ENABLE);

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5761)
		tw32(SNDDATAC_MODE,
		     SNDDATAC_MODE_ENABLE | SNDDATAC_MODE_CDELAY);
	else
		tw32(SNDDATAC_MODE, SNDDATAC_MODE_ENABLE);

	tw32(SNDBDC_MODE, SNDBDC_MODE_ENABLE | SNDBDC_MODE_ATTN_ENABLE);
	tw32(RCVBDI_MODE, RCVBDI_MODE_ENABLE | RCVBDI_MODE_RCB_ATTN_ENAB);
	tw32(RCVDBDI_MODE, RCVDBDI_MODE_ENABLE | RCVDBDI_MODE_INV_RING_SZ);
	tw32(SNDDATAI_MODE, SNDDATAI_MODE_ENABLE);
	if (tp->tg3_flags2 & TG3_FLG2_HW_TSO)
		tw32(SNDDATAI_MODE, SNDDATAI_MODE_ENABLE | 0x8);
	tw32(SNDBDI_MODE, SNDBDI_MODE_ENABLE | SNDBDI_MODE_ATTN_ENABLE);
	tw32(SNDBDS_MODE, SNDBDS_MODE_ENABLE | SNDBDS_MODE_ATTN_ENABLE);

	if (tp->pci_chip_rev_id == CHIPREV_ID_5701_A0) {
		err = tg3_load_5701_a0_firmware_fix(tp);
		if (err)
			return err;
	}
	if (tp->tg3_flags2 & TG3_FLG2_TSO_CAPABLE) {
		err = tg3_load_tso_firmware(tp);
		if (err)
			return err;
	}
	tp->tx_mode = TX_MODE_ENABLE;
	tw32_f(MAC_TX_MODE, tp->tx_mode);
	micro_delay(100);

	tp->rx_mode = RX_MODE_ENABLE;
	if (tp->tg3_flags3 & TG3_FLG3_5755_PLUS)
		tp->rx_mode |= RX_MODE_IPV6_CSUM_ENABLE;

	tw32_f(MAC_RX_MODE, tp->rx_mode);
	micro_delay(10);

	tw32(MAC_LED_CTRL, tp->led_ctrl);

	tw32(MAC_MI_STAT, MAC_MI_STAT_LNKSTAT_ATTN_ENAB);
	if (tp->tg3_flags2 & TG3_FLG2_PHY_SERDES) {
		tw32_f(MAC_RX_MODE, RX_MODE_RESET);
		micro_delay(10);
	}
	tw32_f(MAC_RX_MODE, tp->rx_mode);
	micro_delay(10);

	if (tp->tg3_flags2 & TG3_FLG2_PHY_SERDES) {
		if ((GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5704) &&
		    !(tp->tg3_flags2 & TG3_FLG2_SERDES_PREEMPHASIS)) {
			/* Set drive transmission level to 1.2V  */
			/* only if the signal pre-emphasis bit is not set  */
			val = tr32(MAC_SERDES_CFG);
			val &= 0xfffff000;
			val |= 0x880;
			tw32(MAC_SERDES_CFG, val);
		}
		if (tp->pci_chip_rev_id == CHIPREV_ID_5703_A1)
			tw32(MAC_SERDES_CFG, 0x616000);
	}
	/* Prevent chip from dropping frames when flow control is enabled. */
	tw32_f(MAC_LOW_WMARK_MAX_RX_FRAME, 2);

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5704 &&
	    (tp->tg3_flags2 & TG3_FLG2_PHY_SERDES)) {
		/* Use hardware link auto-negotiation */
		tp->tg3_flags2 |= TG3_FLG2_HW_AUTONEG;
	}
	if ((tp->tg3_flags2 & TG3_FLG2_MII_SERDES) &&
	    (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5714)) {
		u32_t tmp;

		tmp = tr32(SERDES_RX_CTRL);
		tw32(SERDES_RX_CTRL, tmp | SERDES_RX_SIG_DETECT);
		tp->grc_local_ctrl &= ~GRC_LCLCTRL_USE_EXT_SIG_DETECT;
		tp->grc_local_ctrl |= GRC_LCLCTRL_USE_SIG_DETECT;
		tw32(GRC_LOCAL_CTRL, tp->grc_local_ctrl);
	}
	if (!(tp->tg3_flags3 & TG3_FLG3_USE_PHYLIB)) {
		if (tp->link_config.phy_is_low_power) {
			tp->link_config.phy_is_low_power = 0;
			tp->link_config.speed = tp->link_config.orig_speed;
			tp->link_config.duplex = tp->link_config.orig_duplex;
			tp->link_config.autoneg = tp->link_config.orig_autoneg;
		}
		err = tg3_setup_phy(tp, 0);
		if (err)
			return err;

		if (!(tp->tg3_flags2 & TG3_FLG2_PHY_SERDES) &&
		    GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5906) {
			u32_t tmp;

			/* Clear CRC stats. */
			if (!tg3_readphy(tp, MII_TG3_TEST1, &tmp)) {
				tg3_writephy(tp, MII_TG3_TEST1,
					     tmp | MII_TG3_TEST1_CRC_EN);
				tg3_readphy(tp, 0x14, &tmp);
			}
		}
	}
	__tg3_set_rx_mode(tp);

	/* Initialize receive rules. */
	tw32(MAC_RCV_RULE_0, 0xc2000000 & RCV_RULE_DISABLE_MASK);
	tw32(MAC_RCV_VALUE_0, 0xffffffff & RCV_RULE_DISABLE_MASK);
	tw32(MAC_RCV_RULE_1, 0x86000004 & RCV_RULE_DISABLE_MASK);
	tw32(MAC_RCV_VALUE_1, 0xffffffff & RCV_RULE_DISABLE_MASK);

	if ((tp->tg3_flags2 & TG3_FLG2_5705_PLUS) &&
	    !(tp->tg3_flags2 & TG3_FLG2_5780_CLASS))
		limit = 8;
	else
		limit = 16;
	if (tp->tg3_flags & TG3_FLAG_ENABLE_ASF)
		limit -= 4;
	switch (limit) {
	case 16:
		tw32(MAC_RCV_RULE_15, 0);
		tw32(MAC_RCV_VALUE_15, 0);
	case 15:
		tw32(MAC_RCV_RULE_14, 0);
		tw32(MAC_RCV_VALUE_14, 0);
	case 14:
		tw32(MAC_RCV_RULE_13, 0);
		tw32(MAC_RCV_VALUE_13, 0);
	case 13:
		tw32(MAC_RCV_RULE_12, 0);
		tw32(MAC_RCV_VALUE_12, 0);
	case 12:
		tw32(MAC_RCV_RULE_11, 0);
		tw32(MAC_RCV_VALUE_11, 0);
	case 11:
		tw32(MAC_RCV_RULE_10, 0);
		tw32(MAC_RCV_VALUE_10, 0);
	case 10:
		tw32(MAC_RCV_RULE_9, 0);
		tw32(MAC_RCV_VALUE_9, 0);
	case 9:
		tw32(MAC_RCV_RULE_8, 0);
		tw32(MAC_RCV_VALUE_8, 0);
	case 8:
		tw32(MAC_RCV_RULE_7, 0);
		tw32(MAC_RCV_VALUE_7, 0);
	case 7:
		tw32(MAC_RCV_RULE_6, 0);
		tw32(MAC_RCV_VALUE_6, 0);
	case 6:
		tw32(MAC_RCV_RULE_5, 0);
		tw32(MAC_RCV_VALUE_5, 0);
	case 5:
		tw32(MAC_RCV_RULE_4, 0);
		tw32(MAC_RCV_VALUE_4, 0);
	case 4:
		tw32(MAC_RCV_RULE_3, 0);
		tw32(MAC_RCV_VALUE_3, 0);
	case 3:
		tw32(MAC_RCV_RULE_2, 0);
		tw32(MAC_RCV_VALUE_2, 0);
	case 2:
	case 1:

	default:
		break;
	}

	if (tp->tg3_flags3 & TG3_FLG3_ENABLE_APE)
		/* Write our heartbeat update interval to APE. */
		tg3_ape_write32(tp, TG3_APE_HOST_HEARTBEAT_INT_MS,
				APE_HOST_HEARTBEAT_INT_DISABLE);

	tg3_write_sig_post_reset(tp, RESET_KIND_INIT);

	return 0;
}

/* Called at device open time to get the chip ready for
 * packet processing.
 */
PRIVATE int tg3_init_hw(tg3_t * tp, int reset_phy)
{
	tg3_switch_clocks(tp);

	tw32(TG3PCI_MEM_WIN_BASE_ADDR, 0);

	return tg3_reset_hw(tp, reset_phy);
}

#define TG3_STAT_ADD32(PSTAT, REG) \
do {	u32_t __val = tr32(REG); \
	(PSTAT)->low += __val; \
	if ((PSTAT)->low < __val) \
		(PSTAT)->high += 1; \
} while (0)

PRIVATE void tg3_periodic_fetch_stats(tg3_t * tp)
{
	struct tg3_hw_stats *sp = tp->hw_stats;

	if (!carrier_ok(tp))
		return;

	TG3_STAT_ADD32(&sp->tx_octets, MAC_TX_STATS_OCTETS);
	TG3_STAT_ADD32(&sp->tx_collisions, MAC_TX_STATS_COLLISIONS);
	TG3_STAT_ADD32(&sp->tx_xon_sent, MAC_TX_STATS_XON_SENT);
	TG3_STAT_ADD32(&sp->tx_xoff_sent, MAC_TX_STATS_XOFF_SENT);
	TG3_STAT_ADD32(&sp->tx_mac_errors, MAC_TX_STATS_MAC_ERRORS);
	TG3_STAT_ADD32(&sp->tx_single_collisions, MAC_TX_STATS_SINGLE_COLLISIONS);
	TG3_STAT_ADD32(&sp->tx_mult_collisions, MAC_TX_STATS_MULT_COLLISIONS);
	TG3_STAT_ADD32(&sp->tx_deferred, MAC_TX_STATS_DEFERRED);
	TG3_STAT_ADD32(&sp->tx_excessive_collisions, MAC_TX_STATS_EXCESSIVE_COL);
	TG3_STAT_ADD32(&sp->tx_late_collisions, MAC_TX_STATS_LATE_COL);
	TG3_STAT_ADD32(&sp->tx_ucast_packets, MAC_TX_STATS_UCAST);
	TG3_STAT_ADD32(&sp->tx_mcast_packets, MAC_TX_STATS_MCAST);
	TG3_STAT_ADD32(&sp->tx_bcast_packets, MAC_TX_STATS_BCAST);

	TG3_STAT_ADD32(&sp->rx_octets, MAC_RX_STATS_OCTETS);
	TG3_STAT_ADD32(&sp->rx_fragments, MAC_RX_STATS_FRAGMENTS);
	TG3_STAT_ADD32(&sp->rx_ucast_packets, MAC_RX_STATS_UCAST);
	TG3_STAT_ADD32(&sp->rx_mcast_packets, MAC_RX_STATS_MCAST);
	TG3_STAT_ADD32(&sp->rx_bcast_packets, MAC_RX_STATS_BCAST);
	TG3_STAT_ADD32(&sp->rx_fcs_errors, MAC_RX_STATS_FCS_ERRORS);
	TG3_STAT_ADD32(&sp->rx_align_errors, MAC_RX_STATS_ALIGN_ERRORS);
	TG3_STAT_ADD32(&sp->rx_xon_pause_rcvd, MAC_RX_STATS_XON_PAUSE_RECVD);
	TG3_STAT_ADD32(&sp->rx_xoff_pause_rcvd, MAC_RX_STATS_XOFF_PAUSE_RECVD);
	TG3_STAT_ADD32(&sp->rx_mac_ctrl_rcvd, MAC_RX_STATS_MAC_CTRL_RECVD);
	TG3_STAT_ADD32(&sp->rx_xoff_entered, MAC_RX_STATS_XOFF_ENTERED);
	TG3_STAT_ADD32(&sp->rx_frame_too_long_errors, MAC_RX_STATS_FRAME_TOO_LONG);
	TG3_STAT_ADD32(&sp->rx_jabbers, MAC_RX_STATS_JABBERS);
	TG3_STAT_ADD32(&sp->rx_undersize_packets, MAC_RX_STATS_UNDERSIZE);

	TG3_STAT_ADD32(&sp->rxbds_empty, RCVLPC_NO_RCV_BD_CNT);
	TG3_STAT_ADD32(&sp->rx_discards, RCVLPC_IN_DISCARDS_CNT);
	TG3_STAT_ADD32(&sp->rx_errors, RCVLPC_IN_ERRORS_CNT);
}

PRIVATE void tg3_timer(tg3_t * tp)
{
	if (tp->irq_sync) {
		printf("SYNC - restarting timer\n");
		goto restart_timer;
	}
	if (!(tp->tg3_flags & TG3_FLAG_TAGGED_STATUS)) {
		/* All of this garbage is because when using non-tagged IRQ
		 * status the mailbox/status_block protocol the chip uses with
		 * the cpu is race prone. */

		if (tp->hw_status->status & SD_STATUS_UPDATED) {
			tw32(GRC_LOCAL_CTRL,
			     tp->grc_local_ctrl | GRC_LCLCTRL_SETINT);
		} else {
			tw32(HOSTCC_MODE, tp->coalesce_mode |
			     (HOSTCC_MODE_ENABLE | HOSTCC_MODE_NOW));
		}

		if (!(tr32(WDMAC_MODE) & WDMAC_MODE_ENABLE)) {
			tp->tg3_flags2 |= TG3_FLG2_RESTART_TIMER;
			tg3_reset_task(tp);
			return;
		}
	}
	/* This part only runs once per second. */
	if (!--tp->timer_counter) {
		if (tp->tg3_flags2 & TG3_FLG2_5705_PLUS)
			tg3_periodic_fetch_stats(tp);

		if (tp->tg3_flags & TG3_FLAG_USE_LINKCHG_REG) {
			u32_t mac_stat;
			int phy_event;

			mac_stat = tr32(MAC_STATUS);

			phy_event = 0;
			if (tp->tg3_flags & TG3_FLAG_USE_MI_INTERRUPT) {
				if (mac_stat & MAC_STATUS_MI_INTERRUPT)
					phy_event = 1;
			} else if (mac_stat & MAC_STATUS_LNKSTATE_CHANGED)
				phy_event = 1;

			if (phy_event)
				tg3_setup_phy(tp, 0);
		} else if (tp->tg3_flags & TG3_FLAG_POLL_SERDES) {
			u32_t mac_stat = tr32(MAC_STATUS);
			int need_setup = 0;

			if (carrier_ok(tp) &&
			    (mac_stat & MAC_STATUS_LNKSTATE_CHANGED)) {
				need_setup = 1;
			}
			if (!carrier_ok(tp) &&
			    (mac_stat & (MAC_STATUS_PCS_SYNCED |
					 MAC_STATUS_SIGNAL_DET))) {
				need_setup = 1;
			}
			if (need_setup) {
				if (!tp->serdes_counter) {
					tw32_f(MAC_MODE,
					       (tp->mac_mode &
						~MAC_MODE_PORT_MODE_MASK));
					micro_delay(40);
					tw32_f(MAC_MODE, tp->mac_mode);
					micro_delay(40);
				}
				tg3_setup_phy(tp, 0);
			}
		} else if (tp->tg3_flags2 & TG3_FLG2_MII_SERDES)
			tg3_serdes_parallel_detect(tp);

		tp->timer_counter = tp->timer_multiplier;
	}
	/* Heartbeat is only sent once every 2 seconds.
	 * 
	 * The heartbeat is to tell the ASF firmware that the host driver is still
	 * alive.  In the event that the OS crashes, ASF needs to reset the
	 * hardware to free up the FIFO space that may be filled with rx
	 * packets destined for the host. If the FIFO is full, ASF will no
	 * longer function properly.
	 * 
	 * Unintended resets have been reported on real time kernels where the
	 * timer doesn't run on time.  Netpoll will also have same problem.
	 * 
	 * The new FWCMD_NICDRV_ALIVE3 command tells the ASF firmware to check the
	 * ring condition when the heartbeat is expiring before doing the
	 * reset.  This will prevent most unintended resets. */
	if (!--tp->asf_counter) {
		if ((tp->tg3_flags & TG3_FLAG_ENABLE_ASF) &&
		    !(tp->tg3_flags3 & TG3_FLG3_ENABLE_APE)) {
			tg3_wait_for_event_ack(tp);

			tg3_write_mem(tp, NIC_SRAM_FW_CMD_MBOX,
				      FWCMD_NICDRV_ALIVE3);
			tg3_write_mem(tp, NIC_SRAM_FW_CMD_LEN_MBOX, 4);
			/* 5 seconds timeout */
			tg3_write_mem(tp, NIC_SRAM_FW_CMD_DATA_MBOX, 5);

			tg3_generate_fw_event(tp);
		}
		tp->asf_counter = tp->asf_multiplier;
	}
restart_timer:
	sys_setalarm(tp->timer_offset, 0);
}

PRIVATE int tg3_request_irq(tg3_t * tp)
{
	tp->irq_handler = tg3_interrupt;

	if (tp->tg3_flags & TG3_FLAG_TAGGED_STATUS) {
		tp->irq_handler = tg3_interrupt_tagged;
	}
	return 0;
}

PRIVATE int tg3_test_interrupt(tg3_t * tp)
{
	/* No real need for this on Minix */
	return 0;
}

PRIVATE int tg3_open(tg3_t * tp)
{
	int err;

	if (tp->fw_needed) {
		panic("TG3", "tg3_open: \
			TG3 Driver does not currently support loading firmware\n", 0);
	}
	carrier_off(tp);

	err = tg3_set_power_state(tp, PCI_D0);
	if (err)
		return err;

	tg3_full_lock(tp, 0);

	tg3_disable_ints(tp);
	tp->tg3_flags &= ~TG3_FLAG_INIT_COMPLETE;

	tg3_full_unlock(tp);

	/* The placement of this call is tied to the setup and use of Host TX
	 * descriptors. */
	err = tg3_alloc_consistent(tp);
	if (err)
		return err;

	if (tp->tg3_flags & TG3_FLAG_SUPPORT_MSI) {
		printf("NO MSI SUPPORT disabling\n");
		tp->tg3_flags &= ~TG3_FLAG_SUPPORT_MSI;
	}
	err = tg3_request_irq(tp);

	if (err) {
		printf("COULD NOT GET AN IRQ!");
		tg3_free_consistent(tp);
		return err;
	}
	tg3_full_lock(tp, 0);

	err = tg3_init_hw(tp, 1);
	if (err) {
		tg3_halt(tp, RESET_KIND_SHUTDOWN, 1);
	} else {
		if (tp->tg3_flags & TG3_FLAG_TAGGED_STATUS)
			tp->timer_offset = system_hz;
		else
			tp->timer_offset = system_hz / 10;

		assert(!(tp->timer_offset > system_hz));

		tp->timer_counter = tp->timer_multiplier =
			(system_hz / tp->timer_offset);
		tp->asf_counter = tp->asf_multiplier =
			((system_hz / tp->timer_offset) * 2);

		/* Minix Note. I moved the timer init code that was here to the
		 * end of the function. We can init and add it at the same time
		 * in Minix */
	}

	tg3_full_unlock(tp);

	if (err) {
		tg3_free_consistent(tp);
		return err;
	}
	tg3_phy_start(tp);

	tg3_full_lock(tp, 0);

	sys_setalarm(tp->timer_offset, 0);
	tp->tg3_flags |= TG3_FLAG_INIT_COMPLETE;
	tg3_enable_ints(tp);

	tg3_full_unlock(tp);

	return 0;
}

PRIVATE void tg3_dump_state(tg3_t * tp)
{
	u32_t val32, val32_2, val32_3, val32_4, val32_5;
	u16_t val16;
	int i;

	val16 = pci_attr_r16(tp->devind, PCI_SR);
	val32 = pci_attr_r32(tp->devind, TG3PCI_PCISTATE);
	printf("DEBUG: PCI status [%04x] TG3PCI state[%08x]\n",
	       val16, val32);

	/* MAC block */
	printf("DEBUG: MAC_MODE[%08x] MAC_STATUS[%08x]\n",
	       tr32(MAC_MODE), tr32(MAC_STATUS));
	printf("       MAC_EVENT[%08x] MAC_LED_CTRL[%08x]\n",
	       tr32(MAC_EVENT), tr32(MAC_LED_CTRL));
	printf("DEBUG: MAC_TX_MODE[%08x] MAC_TX_STATUS[%08x]\n",
	       tr32(MAC_TX_MODE), tr32(MAC_TX_STATUS));
	printf("       MAC_RX_MODE[%08x] MAC_RX_STATUS[%08x]\n",
	       tr32(MAC_RX_MODE), tr32(MAC_RX_STATUS));

	/* Send data initiator control block */
	printf("DEBUG: SNDDATAI_MODE[%08x] SNDDATAI_STATUS[%08x]\n",
	       tr32(SNDDATAI_MODE), tr32(SNDDATAI_STATUS));
	printf("       SNDDATAI_STATSCTRL[%08x]\n",
	       tr32(SNDDATAI_STATSCTRL));

	/* Send data completion control block */
	printf("DEBUG: SNDDATAC_MODE[%08x]\n", tr32(SNDDATAC_MODE));

	/* Send BD ring selector block */
	printf("DEBUG: SNDBDS_MODE[%08x] SNDBDS_STATUS[%08x]\n",
	       tr32(SNDBDS_MODE), tr32(SNDBDS_STATUS));

	/* Send BD initiator control block */
	printf("DEBUG: SNDBDI_MODE[%08x] SNDBDI_STATUS[%08x]\n",
	       tr32(SNDBDI_MODE), tr32(SNDBDI_STATUS));

	/* Send BD completion control block */
	printf("DEBUG: SNDBDC_MODE[%08x]\n", tr32(SNDBDC_MODE));

	/* Receive list placement control block */
	printf("DEBUG: RCVLPC_MODE[%08x] RCVLPC_STATUS[%08x]\n",
	       tr32(RCVLPC_MODE), tr32(RCVLPC_STATUS));
	printf("       RCVLPC_STATSCTRL[%08x]\n",
	       tr32(RCVLPC_STATSCTRL));

	/* Receive data and receive BD initiator control block */
	printf("DEBUG: RCVDBDI_MODE[%08x] RCVDBDI_STATUS[%08x]\n",
	       tr32(RCVDBDI_MODE), tr32(RCVDBDI_STATUS));

	/* Receive data completion control block */
	printf("DEBUG: RCVDCC_MODE[%08x]\n",
	       tr32(RCVDCC_MODE));

	/* Receive BD initiator control block */
	printf("DEBUG: RCVBDI_MODE[%08x] RCVBDI_STATUS[%08x]\n",
	       tr32(RCVBDI_MODE), tr32(RCVBDI_STATUS));

	/* Receive BD completion control block */
	printf("DEBUG: RCVCC_MODE[%08x] RCVCC_STATUS[%08x]\n",
	       tr32(RCVCC_MODE), tr32(RCVCC_STATUS));

	/* Receive list selector control block */
	printf("DEBUG: RCVLSC_MODE[%08x] RCVLSC_STATUS[%08x]\n",
	       tr32(RCVLSC_MODE), tr32(RCVLSC_STATUS));

	/* Mbuf cluster free block */
	printf("DEBUG: MBFREE_MODE[%08x] MBFREE_STATUS[%08x]\n",
	       tr32(MBFREE_MODE), tr32(MBFREE_STATUS));

	/* Host coalescing control block */
	printf("DEBUG: HOSTCC_MODE[%08x] HOSTCC_STATUS[%08x]\n",
	       tr32(HOSTCC_MODE), tr32(HOSTCC_STATUS));
	printf("DEBUG: HOSTCC_STATS_BLK_HOST_ADDR[%08x%08x]\n",
	       tr32(HOSTCC_STATS_BLK_HOST_ADDR + TG3_64BIT_REG_HIGH),
	       tr32(HOSTCC_STATS_BLK_HOST_ADDR + TG3_64BIT_REG_LOW));
	printf("DEBUG: HOSTCC_STATUS_BLK_HOST_ADDR[%08x%08x]\n",
	       tr32(HOSTCC_STATUS_BLK_HOST_ADDR + TG3_64BIT_REG_HIGH),
	       tr32(HOSTCC_STATUS_BLK_HOST_ADDR + TG3_64BIT_REG_LOW));
	printf("DEBUG: HOSTCC_STATS_BLK_NIC_ADDR[%08x]\n",
	       tr32(HOSTCC_STATS_BLK_NIC_ADDR));
	printf("DEBUG: HOSTCC_STATUS_BLK_NIC_ADDR[%08x]\n",
	       tr32(HOSTCC_STATUS_BLK_NIC_ADDR));

	/* Memory arbiter control block */
	printf("DEBUG: MEMARB_MODE[%08x] MEMARB_STATUS[%08x]\n",
	       tr32(MEMARB_MODE), tr32(MEMARB_STATUS));

	/* Buffer manager control block */
	printf("DEBUG: BUFMGR_MODE[%08x] BUFMGR_STATUS[%08x]\n",
	       tr32(BUFMGR_MODE), tr32(BUFMGR_STATUS));
	printf("DEBUG: BUFMGR_MB_POOL_ADDR[%08x] BUFMGR_MB_POOL_SIZE[%08x]\n",
	       tr32(BUFMGR_MB_POOL_ADDR), tr32(BUFMGR_MB_POOL_SIZE));
	printf("DEBUG: BUFMGR_DMA_DESC_POOL_ADDR[%08x] "
	       "BUFMGR_DMA_DESC_POOL_SIZE[%08x]\n",
	       tr32(BUFMGR_DMA_DESC_POOL_ADDR),
	       tr32(BUFMGR_DMA_DESC_POOL_SIZE));

	/* Read DMA control block */
	printf("DEBUG: RDMAC_MODE[%08x] RDMAC_STATUS[%08x]\n",
	       tr32(RDMAC_MODE), tr32(RDMAC_STATUS));

	/* Write DMA control block */
	printf("DEBUG: WDMAC_MODE[%08x] WDMAC_STATUS[%08x]\n",
	       tr32(WDMAC_MODE), tr32(WDMAC_STATUS));

	/* DMA completion block */
	printf("DEBUG: DMAC_MODE[%08x]\n",
	       tr32(DMAC_MODE));

	/* GRC block */
	printf("DEBUG: GRC_MODE[%08x] GRC_MISC_CFG[%08x]\n",
	       tr32(GRC_MODE), tr32(GRC_MISC_CFG));
	printf("DEBUG: GRC_LOCAL_CTRL[%08x]\n",
	       tr32(GRC_LOCAL_CTRL));

	/* TG3_BDINFOs */
	printf("DEBUG: RCVDBDI_JUMBO_BD[%08x%08x:%08x:%08x]\n",
	       tr32(RCVDBDI_JUMBO_BD + 0x0),
	       tr32(RCVDBDI_JUMBO_BD + 0x4),
	       tr32(RCVDBDI_JUMBO_BD + 0x8),
	       tr32(RCVDBDI_JUMBO_BD + 0xc));
	printf("DEBUG: RCVDBDI_STD_BD[%08x%08x:%08x:%08x]\n",
	       tr32(RCVDBDI_STD_BD + 0x0),
	       tr32(RCVDBDI_STD_BD + 0x4),
	       tr32(RCVDBDI_STD_BD + 0x8),
	       tr32(RCVDBDI_STD_BD + 0xc));
	printf("DEBUG: RCVDBDI_MINI_BD[%08x%08x:%08x:%08x]\n",
	       tr32(RCVDBDI_MINI_BD + 0x0),
	       tr32(RCVDBDI_MINI_BD + 0x4),
	       tr32(RCVDBDI_MINI_BD + 0x8),
	       tr32(RCVDBDI_MINI_BD + 0xc));

	tg3_read_mem(tp, NIC_SRAM_SEND_RCB + 0x0, &val32);
	tg3_read_mem(tp, NIC_SRAM_SEND_RCB + 0x4, &val32_2);
	tg3_read_mem(tp, NIC_SRAM_SEND_RCB + 0x8, &val32_3);
	tg3_read_mem(tp, NIC_SRAM_SEND_RCB + 0xc, &val32_4);
	printf("DEBUG: SRAM_SEND_RCB_0[%08x%08x:%08x:%08x]\n",
	       val32, val32_2, val32_3, val32_4);

	tg3_read_mem(tp, NIC_SRAM_RCV_RET_RCB + 0x0, &val32);
	tg3_read_mem(tp, NIC_SRAM_RCV_RET_RCB + 0x4, &val32_2);
	tg3_read_mem(tp, NIC_SRAM_RCV_RET_RCB + 0x8, &val32_3);
	tg3_read_mem(tp, NIC_SRAM_RCV_RET_RCB + 0xc, &val32_4);
	printf("DEBUG: SRAM_RCV_RET_RCB_0[%08x%08x:%08x:%08x]\n",
	       val32, val32_2, val32_3, val32_4);

	tg3_read_mem(tp, NIC_SRAM_STATUS_BLK + 0x0, &val32);
	tg3_read_mem(tp, NIC_SRAM_STATUS_BLK + 0x4, &val32_2);
	tg3_read_mem(tp, NIC_SRAM_STATUS_BLK + 0x8, &val32_3);
	tg3_read_mem(tp, NIC_SRAM_STATUS_BLK + 0xc, &val32_4);
	tg3_read_mem(tp, NIC_SRAM_STATUS_BLK + 0x10, &val32_5);
	printf("DEBUG: SRAM_STATUS_BLK[%08x:%08x:%08x:%08x:%08x]\n",
	       val32, val32_2, val32_3, val32_4, val32_5);

	/* SW status block */
	printf("DEBUG: Host status block [%08x:%08x:(%04x:%04x:%04x):(%04x:%04x)]\n",
	       tp->hw_status->status,
	       tp->hw_status->status_tag,
	       tp->hw_status->rx_jumbo_consumer,
	       tp->hw_status->rx_consumer,
	       tp->hw_status->rx_mini_consumer,
	       tp->hw_status->idx[0].rx_producer,
	       tp->hw_status->idx[0].tx_consumer);

	/* SW statistics block */
	printf("DEBUG: Host statistics block [%08x:%08x:%08x:%08x]\n",
	       ((u32_t *) tp->hw_stats)[0],
	       ((u32_t *) tp->hw_stats)[1],
	       ((u32_t *) tp->hw_stats)[2],
	       ((u32_t *) tp->hw_stats)[3]);

	/* Mailboxes */
	printf("DEBUG: SNDHOST_PROD[%08x%08x] SNDNIC_PROD[%08x%08x]\n",
	       tr32_mailbox(MAILBOX_SNDHOST_PROD_IDX_0 + 0x0),
	       tr32_mailbox(MAILBOX_SNDHOST_PROD_IDX_0 + 0x4),
	       tr32_mailbox(MAILBOX_SNDNIC_PROD_IDX_0 + 0x0),
	       tr32_mailbox(MAILBOX_SNDNIC_PROD_IDX_0 + 0x4));

	/* NIC side send descriptors. */
	for (i = 0; i < 6; i++) {
		u8_t *txd;

		txd = tp->regs + NIC_SRAM_WIN_BASE + NIC_SRAM_TX_BUFFER_DESC
			+ (i * sizeof(struct tg3_tx_buffer_desc));
		printf("DEBUG: NIC TXD(%d)[%08x:%08x:%08x:%08x]\n",
		       i,
		       readl(txd + 0x0), readl(txd + 0x4),
		       readl(txd + 0x8), readl(txd + 0xc));
	}

	/* NIC side RX descriptors. */
	for (i = 0; i < 6; i++) {
		u8_t *rxd;

		rxd = tp->regs + NIC_SRAM_WIN_BASE + NIC_SRAM_RX_BUFFER_DESC
			+ (i * sizeof(struct tg3_rx_buffer_desc));
		printf("DEBUG: NIC RXD_STD(%d)[0][%08x:%08x:%08x:%08x]\n",
		       i,
		       readl(rxd + 0x0), readl(rxd + 0x4),
		       readl(rxd + 0x8), readl(rxd + 0xc));
		rxd += (4 * sizeof(u32_t));
		printf("DEBUG: NIC RXD_STD(%d)[1][%08x:%08x:%08x:%08x]\n",
		       i,
		       readl(rxd + 0x0), readl(rxd + 0x4),
		       readl(rxd + 0x8), readl(rxd + 0xc));
	}

	for (i = 0; i < 6; i++) {
		u8_t *rxd;

		rxd = tp->regs + NIC_SRAM_WIN_BASE + NIC_SRAM_RX_JUMBO_BUFFER_DESC
			+ (i * sizeof(struct tg3_rx_buffer_desc));
		printf("DEBUG: NIC RXD_JUMBO(%d)[0][%08x:%08x:%08x:%08x]\n",
		       i,
		       readl(rxd + 0x0), readl(rxd + 0x4),
		       readl(rxd + 0x8), readl(rxd + 0xc));
		rxd += (4 * sizeof(u32_t));
		printf("DEBUG: NIC RXD_JUMBO(%d)[1][%08x:%08x:%08x:%08x]\n",
		       i,
		       readl(rxd + 0x0), readl(rxd + 0x4),
		       readl(rxd + 0x8), readl(rxd + 0xc));
	}
}


PRIVATE int tg3_close(tg3_t * tp)
{
	tg3_full_lock(tp, 1);
#if 0
	tg3_dump_state(tp);
#endif

	tg3_disable_ints(tp);

	tg3_halt(tp, RESET_KIND_SHUTDOWN, 1);
	tp->tg3_flags &= ~TG3_FLAG_INIT_COMPLETE;

	tg3_full_unlock(tp);

	tg3_free_consistent(tp);

	tg3_set_power_state(tp, PCI_D3hot);

	carrier_off(tp);

	return 0;
}

PRIVATE u32_t calc_crc(unsigned char *buf, int len)
{
	u32_t reg;
	u32_t tmp;
	int j, k;

	reg = 0xffffffff;

	for (j = 0; j < len; j++) {
		reg ^= buf[j];

		for (k = 0; k < 8; k++) {
			tmp = reg & 0x01;

			reg >>= 1;

			if (tmp) {
				reg ^= 0xedb88320;
			}
		}
	}

	return ~reg;
}

PRIVATE void tg3_set_multi(tg3_t * tp, unsigned int accept_all)
{
	/* accept or reject all multicast frames */
	tw32(MAC_HASH_REG_0, accept_all ? 0xffffffff : 0);
	tw32(MAC_HASH_REG_1, accept_all ? 0xffffffff : 0);
	tw32(MAC_HASH_REG_2, accept_all ? 0xffffffff : 0);
	tw32(MAC_HASH_REG_3, accept_all ? 0xffffffff : 0);
}

PRIVATE void __tg3_set_rx_mode(tg3_t * tp)
{
	u32_t rx_mode;

	rx_mode = tp->rx_mode & ~(RX_MODE_PROMISC |
				  RX_MODE_KEEP_VLAN_TAG);

	/* When ASF is in use, we always keep the RX_MODE_KEEP_VLAN_TAG flag
	 * clear. */

	/* By definition, VLAN is disabled always in this case. */
	if (!(tp->tg3_flags & TG3_FLAG_ENABLE_ASF))
		rx_mode |= RX_MODE_KEEP_VLAN_TAG;

	if (tp->flags & TG3_PROMISC) {
		/* Promiscuous mode. */
		rx_mode |= RX_MODE_PROMISC;
	} else if (tp->flags & TG3_MULTI) {
		/* Accept all multicast. */
		tg3_set_multi(tp, 1);
		/* Reject all multicast. */
	} else {
		tg3_set_multi(tp, 0);
	}

	if (rx_mode != tp->rx_mode) {
		tp->rx_mode = rx_mode;
		tw32_f(MAC_RX_MODE, rx_mode);
		micro_delay(10);
	}
}

#define NVRAM_TEST_SIZE 0x100
#define NVRAM_SELFBOOT_FORMAT1_0_SIZE	0x14
#define NVRAM_SELFBOOT_FORMAT1_2_SIZE	0x18
#define NVRAM_SELFBOOT_FORMAT1_3_SIZE	0x1c
#define NVRAM_SELFBOOT_HW_SIZE 0x20
#define NVRAM_SELFBOOT_DATA_SIZE 0x1c

PRIVATE int tg3_test_nvram(tg3_t * tp)
{
	u32_t csum, magic;
	u32_t *buf = NULL;
	int i, j, k, err = 0, size;

	if (tp->tg3_flags3 & TG3_FLG3_NO_NVRAM)
		return 0;

	if (tg3_nvram_read(tp, 0, &magic) != 0)
		return -EIO;

	if (magic == TG3_EEPROM_MAGIC)
		size = NVRAM_TEST_SIZE;
	else if ((magic & TG3_EEPROM_MAGIC_FW_MSK) == TG3_EEPROM_MAGIC_FW) {
		if ((magic & TG3_EEPROM_SB_FORMAT_MASK) ==
		    TG3_EEPROM_SB_FORMAT_1) {
			switch (magic & TG3_EEPROM_SB_REVISION_MASK) {
			case TG3_EEPROM_SB_REVISION_0:
				size = NVRAM_SELFBOOT_FORMAT1_0_SIZE;
				break;
			case TG3_EEPROM_SB_REVISION_2:
				size = NVRAM_SELFBOOT_FORMAT1_2_SIZE;
				break;
			case TG3_EEPROM_SB_REVISION_3:
				size = NVRAM_SELFBOOT_FORMAT1_3_SIZE;
				break;
			default:
				return 0;
			}
		} else
			return 0;
	} else if ((magic & TG3_EEPROM_MAGIC_HW_MSK) == TG3_EEPROM_MAGIC_HW)
		size = NVRAM_SELFBOOT_HW_SIZE;
	else
		return -EIO;

	buf = malloc(size);
	if (buf == NULL)
		return -ENOMEM;

	err = -EIO;
	for (i = 0, j = 0; i < size; i += 4, j++) {
		err = tg3_nvram_read_be32(tp, i, (u32_t *) & buf[j]);
		if (err)
			break;
	}
	if (i < size)
		goto out;

	/* Selfboot format */
	magic = be32_to_cpu(buf[0]);
	if ((magic & TG3_EEPROM_MAGIC_FW_MSK) ==
	    TG3_EEPROM_MAGIC_FW) {
		u8_t *buf8 = (u8_t *) buf, csum8 = 0;

		if ((magic & TG3_EEPROM_SB_REVISION_MASK) ==
		    TG3_EEPROM_SB_REVISION_2) {
			/* For rev 2, the csum doesn't include the MBA. */
			for (i = 0; i < TG3_EEPROM_SB_F1R2_MBA_OFF; i++)
				csum8 += buf8[i];
			for (i = TG3_EEPROM_SB_F1R2_MBA_OFF + 4; i < size; i++)
				csum8 += buf8[i];
		} else {
			for (i = 0; i < size; i++)
				csum8 += buf8[i];
		}

		if (csum8 == 0) {
			err = 0;
			goto out;
		}
		err = -EIO;
		goto out;
	}
	if ((magic & TG3_EEPROM_MAGIC_HW_MSK) ==
	    TG3_EEPROM_MAGIC_HW) {
		u8_t data[NVRAM_SELFBOOT_DATA_SIZE];
		u8_t parity[NVRAM_SELFBOOT_DATA_SIZE];
		u8_t *buf8 = (u8_t *) buf;

		/* Separate the parity bits and the data bytes.  */
		for (i = 0, j = 0, k = 0; i < NVRAM_SELFBOOT_HW_SIZE; i++) {
			if ((i == 0) || (i == 8)) {
				int l;
				u8_t msk;

				for (l = 0, msk = 0x80; l < 7; l++, msk >>= 1)
					parity[k++] = buf8[i] & msk;
				i++;
			} else if (i == 16) {
				int l;
				u8_t msk;

				for (l = 0, msk = 0x20; l < 6; l++, msk >>= 1)
					parity[k++] = buf8[i] & msk;
				i++;

				for (l = 0, msk = 0x80; l < 8; l++, msk >>= 1)
					parity[k++] = buf8[i] & msk;
				i++;
			}
			data[j++] = buf8[i];
		}

		err = -EIO;
		for (i = 0; i < NVRAM_SELFBOOT_DATA_SIZE; i++) {
			u8_t hw8 = hweight8(data[i]);

			if ((hw8 & 0x1) && parity[i])
				goto out;
			else if (!(hw8 & 0x1) && !parity[i])
				goto out;
		}
		err = 0;
		goto out;
	}
	/* Bootstrap checksum at offset 0x10 */
	csum = calc_crc((unsigned char *) buf, 0x10);
	if (csum != be32_to_cpu(buf[0x10 / 4]))
		goto out;

	/* Manufacturing block starts at offset 0x74, checksum at 0xfc */
	csum = calc_crc((unsigned char *) &buf[0x74 / 4], 0x88);
	if (csum != be32_to_cpu(buf[0xfc / 4]))
		goto out;

	err = 0;

out:
	free(buf);
	return err;
}

#define TG3_SERDES_TIMEOUT_SEC	2
#define TG3_COPPER_TIMEOUT_SEC	6

PRIVATE int tg3_test_link(tg3_t * tp)
{
	int i, max;

	if (!tg3_enabled(tp))
		return -ENODEV;

	if (tp->tg3_flags2 & TG3_FLG2_ANY_SERDES)
		max = TG3_SERDES_TIMEOUT_SEC;
	else
		max = TG3_COPPER_TIMEOUT_SEC;

	for (i = 0; i < max; i++) {
		if (carrier_ok(tp))
			return 0;

		if (sleep(1))
			break;
	}

	return -EIO;
}

/* Only test the commonly used registers */
PRIVATE int tg3_test_registers(tg3_t * tp)
{
	int i, is_5705, is_5750;
	u32_t offset, read_mask, write_mask, val, save_val, read_val;
	static struct {
		u16_t offset;
		u16_t flags;
#define TG3_FL_5705	0x1
#define TG3_FL_NOT_5705	0x2
#define TG3_FL_NOT_5788	0x4
#define TG3_FL_NOT_5750	0x8
		u32_t read_mask;
		u32_t write_mask;
	} reg_tbl[] = {
		/* MAC Control Registers */
		{
			MAC_MODE, TG3_FL_NOT_5705,
			0x00000000, 0x00ef6f8c
		},
		{
			MAC_MODE, TG3_FL_5705,
			0x00000000, 0x01ef6b8c
		},
		{
			MAC_STATUS, TG3_FL_NOT_5705,
			0x03800107, 0x00000000
		},
		{
			MAC_STATUS, TG3_FL_5705,
			0x03800100, 0x00000000
		},
		{
			MAC_ADDR_0_HIGH, 0x0000,
			0x00000000, 0x0000ffff
		},
		{
			MAC_ADDR_0_LOW, 0x0000,
			0x00000000, 0xffffffff
		},
		{
			MAC_RX_MTU_SIZE, 0x0000,
			0x00000000, 0x0000ffff
		},
		{
			MAC_TX_MODE, 0x0000,
			0x00000000, 0x00000070
		},
		{
			MAC_TX_LENGTHS, 0x0000,
			0x00000000, 0x00003fff
		},
		{
			MAC_RX_MODE, TG3_FL_NOT_5705,
			0x00000000, 0x000007fc
		},
		{
			MAC_RX_MODE, TG3_FL_5705,
			0x00000000, 0x000007dc
		},
		{
			MAC_HASH_REG_0, 0x0000,
			0x00000000, 0xffffffff
		},
		{
			MAC_HASH_REG_1, 0x0000,
			0x00000000, 0xffffffff
		},
		{
			MAC_HASH_REG_2, 0x0000,
			0x00000000, 0xffffffff
		},
		{
			MAC_HASH_REG_3, 0x0000,
			0x00000000, 0xffffffff
		},

		/* Receive Data and Receive BD Initiator Control Registers. */
		{
			RCVDBDI_JUMBO_BD + 0, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},
		{
			RCVDBDI_JUMBO_BD + 4, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},
		{
			RCVDBDI_JUMBO_BD + 8, TG3_FL_NOT_5705,
			0x00000000, 0x00000003
		},
		{
			RCVDBDI_JUMBO_BD + 0xc, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},
		{
			RCVDBDI_STD_BD + 0, 0x0000,
			0x00000000, 0xffffffff
		},
		{
			RCVDBDI_STD_BD + 4, 0x0000,
			0x00000000, 0xffffffff
		},
		{
			RCVDBDI_STD_BD + 8, 0x0000,
			0x00000000, 0xffff0002
		},
		{
			RCVDBDI_STD_BD + 0xc, 0x0000,
			0x00000000, 0xffffffff
		},

		/* Receive BD Initiator Control Registers. */
		{
			RCVBDI_STD_THRESH, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},
		{
			RCVBDI_STD_THRESH, TG3_FL_5705,
			0x00000000, 0x000003ff
		},
		{
			RCVBDI_JUMBO_THRESH, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},

		/* Host Coalescing Control Registers. */
		{
			HOSTCC_MODE, TG3_FL_NOT_5705,
			0x00000000, 0x00000004
		},
		{
			HOSTCC_MODE, TG3_FL_5705,
			0x00000000, 0x000000f6
		},
		{
			HOSTCC_RXCOL_TICKS, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},
		{
			HOSTCC_RXCOL_TICKS, TG3_FL_5705,
			0x00000000, 0x000003ff
		},
		{
			HOSTCC_TXCOL_TICKS, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},
		{
			HOSTCC_TXCOL_TICKS, TG3_FL_5705,
			0x00000000, 0x000003ff
		},
		{
			HOSTCC_RXMAX_FRAMES, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},
		{
			HOSTCC_RXMAX_FRAMES, TG3_FL_5705 | TG3_FL_NOT_5788,
			0x00000000, 0x000000ff
		},
		{
			HOSTCC_TXMAX_FRAMES, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},
		{
			HOSTCC_TXMAX_FRAMES, TG3_FL_5705 | TG3_FL_NOT_5788,
			0x00000000, 0x000000ff
		},
		{
			HOSTCC_RXCOAL_TICK_INT, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},
		{
			HOSTCC_TXCOAL_TICK_INT, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},
		{
			HOSTCC_RXCOAL_MAXF_INT, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},
		{
			HOSTCC_RXCOAL_MAXF_INT, TG3_FL_5705 | TG3_FL_NOT_5788,
			0x00000000, 0x000000ff
		},
		{
			HOSTCC_TXCOAL_MAXF_INT, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},
		{
			HOSTCC_TXCOAL_MAXF_INT, TG3_FL_5705 | TG3_FL_NOT_5788,
			0x00000000, 0x000000ff
		},
		{
			HOSTCC_STAT_COAL_TICKS, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},
		{
			HOSTCC_STATS_BLK_HOST_ADDR, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},
		{
			HOSTCC_STATS_BLK_HOST_ADDR + 4, TG3_FL_NOT_5705,
			0x00000000, 0xffffffff
		},
		{
			HOSTCC_STATUS_BLK_HOST_ADDR, 0x0000,
			0x00000000, 0xffffffff
		},
		{
			HOSTCC_STATUS_BLK_HOST_ADDR + 4, 0x0000,
			0x00000000, 0xffffffff
		},
		{
			HOSTCC_STATS_BLK_NIC_ADDR, 0x0000,
			0xffffffff, 0x00000000
		},
		{
			HOSTCC_STATUS_BLK_NIC_ADDR, 0x0000,
			0xffffffff, 0x00000000
		},

		/* Buffer Manager Control Registers. */
		{
			BUFMGR_MB_POOL_ADDR, TG3_FL_NOT_5750,
			0x00000000, 0x007fff80
		},
		{
			BUFMGR_MB_POOL_SIZE, TG3_FL_NOT_5750,
			0x00000000, 0x007fffff
		},
		{
			BUFMGR_MB_RDMA_LOW_WATER, 0x0000,
			0x00000000, 0x0000003f
		},
		{
			BUFMGR_MB_MACRX_LOW_WATER, 0x0000,
			0x00000000, 0x000001ff
		},
		{
			BUFMGR_MB_HIGH_WATER, 0x0000,
			0x00000000, 0x000001ff
		},
		{
			BUFMGR_DMA_DESC_POOL_ADDR, TG3_FL_NOT_5705,
			0xffffffff, 0x00000000
		},
		{
			BUFMGR_DMA_DESC_POOL_SIZE, TG3_FL_NOT_5705,
			0xffffffff, 0x00000000
		},

		/* Mailbox Registers */
		{
			GRCMBOX_RCVSTD_PROD_IDX + 4, 0x0000,
			0x00000000, 0x000001ff
		},
		{
			GRCMBOX_RCVJUMBO_PROD_IDX + 4, TG3_FL_NOT_5705,
			0x00000000, 0x000001ff
		},
		{
			GRCMBOX_RCVRET_CON_IDX_0 + 4, 0x0000,
			0x00000000, 0x000007ff
		},
		{
			GRCMBOX_SNDHOST_PROD_IDX_0 + 4, 0x0000,
			0x00000000, 0x000001ff
		},

		{
			0xffff, 0x0000, 0x00000000, 0x00000000
		},
	};

	is_5705 = is_5750 = 0;
	if (tp->tg3_flags2 & TG3_FLG2_5705_PLUS) {
		is_5705 = 1;
		if (tp->tg3_flags2 & TG3_FLG2_5750_PLUS)
			is_5750 = 1;
	}
	for (i = 0; reg_tbl[i].offset != 0xffff; i++) {
		if (is_5705 && (reg_tbl[i].flags & TG3_FL_NOT_5705))
			continue;

		if (!is_5705 && (reg_tbl[i].flags & TG3_FL_5705))
			continue;

		if ((tp->tg3_flags2 & TG3_FLG2_IS_5788) &&
		    (reg_tbl[i].flags & TG3_FL_NOT_5788))
			continue;

		if (is_5750 && (reg_tbl[i].flags & TG3_FL_NOT_5750))
			continue;

		offset = (u32_t) reg_tbl[i].offset;
		read_mask = reg_tbl[i].read_mask;
		write_mask = reg_tbl[i].write_mask;

		/* Save the original register content */
		save_val = tr32(offset);

		/* Determine the read-only value. */
		read_val = save_val & read_mask;

		/* Write zero to the register, then make sure the read-only
		 * bits are not changed and the read/write bits are all zeros. */
		tw32(offset, 0);

		val = tr32(offset);

		/* Test the read-only and read/write bits. */
		if (((val & read_mask) != read_val) || (val & write_mask))
			goto out;

		/* Write ones to all the bits defined by RdMask and WrMask,
		 * then make sure the read-only bits are not changed and the
		 * read/write bits are all ones. */
		tw32(offset, read_mask | write_mask);

		val = tr32(offset);

		/* Test the read-only bits. */
		if ((val & read_mask) != read_val)
			goto out;

		/* Test the read/write bits. */
		if ((val & write_mask) != write_mask)
			goto out;

		tw32(offset, save_val);
	}

	return 0;

out:
	printf("Register test failed at offset %x\n", offset);
	tw32(offset, save_val);
	return -EIO;
}

PRIVATE int tg3_do_mem_test(tg3_t * tp, u32_t offset, u32_t len)
{
	static const u32_t test_pattern[] = {0x00000000, 0xffffffff, 0xaa55a55a};
	int i;
	u32_t j;

	for (i = 0; i < ARRAY_SIZE(test_pattern); i++) {
		for (j = 0; j < len; j += 4) {
			u32_t val;

			tg3_write_mem(tp, offset + j, test_pattern[i]);
			tg3_read_mem(tp, offset + j, &val);
			if (val != test_pattern[i])
				return -EIO;
		}
	}
	return 0;
}

PRIVATE int tg3_test_memory(tg3_t * tp)
{
	static struct mem_entry {
		u32_t offset;
		u32_t len;
	} mem_tbl_570x[] = {
		{
			0x00000000, 0x00b50
		},
		{
			0x00002000, 0x1c000
		},
		{
			0xffffffff, 0x00000
		}
	}, mem_tbl_5705[] = {
		{
			0x00000100, 0x0000c
		},
		{
			0x00000200, 0x00008
		},
		{
			0x00004000, 0x00800
		},
		{
			0x00006000, 0x01000
		},
		{
			0x00008000, 0x02000
		},
		{
			0x00010000, 0x0e000
		},
		{
			0xffffffff, 0x00000
		}
	}, mem_tbl_5755[] = {
		{
			0x00000200, 0x00008
		},
		{
			0x00004000, 0x00800
		},
		{
			0x00006000, 0x00800
		},
		{
			0x00008000, 0x02000
		},
		{
			0x00010000, 0x0c000
		},
		{
			0xffffffff, 0x00000
		}
	}, mem_tbl_5906[] = {
		{
			0x00000200, 0x00008
		},
		{
			0x00004000, 0x00400
		},
		{
			0x00006000, 0x00400
		},
		{
			0x00008000, 0x01000
		},
		{
			0x00010000, 0x01000
		},
		{
			0xffffffff, 0x00000
		}
	};
	struct mem_entry *mem_tbl;
	int err = 0;
	int i;

	if (tp->tg3_flags3 & TG3_FLG3_5755_PLUS)
		mem_tbl = mem_tbl_5755;
	else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906)
		mem_tbl = mem_tbl_5906;
	else if (tp->tg3_flags2 & TG3_FLG2_5705_PLUS)
		mem_tbl = mem_tbl_5705;
	else
		mem_tbl = mem_tbl_570x;

	for (i = 0; mem_tbl[i].offset != 0xffffffff; i++) {
		if ((err = tg3_do_mem_test(tp, mem_tbl[i].offset,
					   mem_tbl[i].len)) != 0)
			break;
	}

	return err;
}

#define TG3_MAC_LOOPBACK	0
#define TG3_PHY_LOOPBACK	1

PRIVATE int tg3_run_loopback(tg3_t * tp, int loopback_mode)
{
	u32_t mac_mode, rx_start_idx, rx_idx, tx_idx, opaque_key;
	u32_t desc_idx;
	iovec_t *iovec, *rx_iovec;
	u8_t *tx_data;
	phys_bytes map;
	int num_pkts, tx_len, rx_len, i, err;
	struct tg3_rx_buffer_desc *desc;

	printf("Loopback test causes a crash, skipping\n");
	return 0;

	if (loopback_mode == TG3_MAC_LOOPBACK) {
		/* HW errata - mac loopback fails in some cases on 5780. Normal
		 * traffic and PHY loopback are not affected by errata. */
		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5780)
			return 0;

		mac_mode = (tp->mac_mode & ~MAC_MODE_PORT_MODE_MASK) |
			MAC_MODE_PORT_INT_LPBACK;
		if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS))
			mac_mode |= MAC_MODE_LINK_POLARITY;
		if (tp->tg3_flags & TG3_FLAG_10_100_ONLY)
			mac_mode |= MAC_MODE_PORT_MODE_MII;
		else
			mac_mode |= MAC_MODE_PORT_MODE_GMII;
		tw32(MAC_MODE, mac_mode);
	} else if (loopback_mode == TG3_PHY_LOOPBACK) {
		u32_t val;

		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) {
			u32_t phytest;

			if (!tg3_readphy(tp, MII_TG3_EPHY_TEST, &phytest)) {
				u32_t phy;

				tg3_writephy(tp, MII_TG3_EPHY_TEST,
					     phytest | MII_TG3_EPHY_SHADOW_EN);
				if (!tg3_readphy(tp, 0x1b, &phy))
					tg3_writephy(tp, 0x1b, phy & ~0x20);
				tg3_writephy(tp, MII_TG3_EPHY_TEST, phytest);
			}
			val = BMCR_LOOPBACK | BMCR_FULLDPLX | BMCR_SPEED100;
		} else
			val = BMCR_LOOPBACK | BMCR_FULLDPLX | BMCR_SPEED1000;

		tg3_phy_toggle_automdix(tp, 0);

		tg3_writephy(tp, MII_BMCR, val);
		micro_delay(40);

		mac_mode = tp->mac_mode & ~MAC_MODE_PORT_MODE_MASK;
		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) {
			tg3_writephy(tp, MII_TG3_EPHY_PTEST, 0x1800);
			mac_mode |= MAC_MODE_PORT_MODE_MII;
		} else
			mac_mode |= MAC_MODE_PORT_MODE_GMII;

		/* reset to prevent losing 1st rx packet intermittently */
		if (tp->tg3_flags2 & TG3_FLG2_MII_SERDES) {
			tw32_f(MAC_RX_MODE, RX_MODE_RESET);
			micro_delay(10);
			tw32_f(MAC_RX_MODE, tp->rx_mode);
		}
		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5700) {
			if ((tp->phy_id & PHY_ID_MASK) == PHY_ID_BCM5401)
				mac_mode &= ~MAC_MODE_LINK_POLARITY;
			else if ((tp->phy_id & PHY_ID_MASK) == PHY_ID_BCM5411)
				mac_mode |= MAC_MODE_LINK_POLARITY;
			tg3_writephy(tp, MII_TG3_EXT_CTRL,
				     MII_TG3_EXT_CTRL_LNK3_LED_MODE);
		}
		tw32(MAC_MODE, mac_mode);
	} else
		return -EINVAL;

	err = -EIO;

	tx_len = 1514;
	iovec = alloc_iovec(tx_len, &map);
	if (!iovec)
		return -ENOMEM;

	iovec->iov_size = tx_len;
	memcpy((void *) iovec->iov_addr, (void *) (&tp->mac_address), 6);
	memset((void *) (iovec->iov_addr + 6), 0x0, 8);

	tw32(MAC_RX_MTU_SIZE, tx_len + 4);

	for (i = 14; i < tx_len; i++)
		tx_data[i] = (u8_t) (i & 0xff);

	tw32_f(HOSTCC_MODE, tp->coalesce_mode | HOSTCC_MODE_ENABLE |
	       HOSTCC_MODE_NOW);

	micro_delay(10);

	rx_start_idx = tp->hw_status->idx[0].rx_producer;

	num_pkts = 0;

	tg3_set_txd(tp, tp->tx_prod, map, tx_len, 0, 1);

	tp->tx_prod++;
	num_pkts++;

	tw32_tx_mbox(MAILBOX_SNDHOST_PROD_IDX_0 + TG3_64BIT_REG_LOW,
		     tp->tx_prod);
	tr32_mailbox(MAILBOX_SNDHOST_PROD_IDX_0 + TG3_64BIT_REG_LOW);

	micro_delay(10);

	/* 250 usec to allow enough time on some 10/100 Mbps devices.  */
	for (i = 0; i < 25; i++) {
		tw32_f(HOSTCC_MODE, tp->coalesce_mode | HOSTCC_MODE_ENABLE |
		       HOSTCC_MODE_NOW);

		micro_delay(10);

		tx_idx = tp->hw_status->idx[0].tx_consumer;
		rx_idx = tp->hw_status->idx[0].rx_producer;
		if ((tx_idx == tp->tx_prod) &&
		    (rx_idx == (rx_start_idx + num_pkts)))
			break;
	}

	if (tx_idx != tp->tx_prod)
		goto out;

	if (rx_idx != rx_start_idx + num_pkts)
		goto out;

	desc = &tp->rx_rcb[rx_start_idx];
	desc_idx = desc->opaque & RXD_OPAQUE_INDEX_MASK;
	opaque_key = desc->opaque & RXD_OPAQUE_RING_MASK;
	if (opaque_key != RXD_OPAQUE_RING_STD)
		goto out;

	if ((desc->err_vlan & RXD_ERR_MASK) != 0 &&
	    (desc->err_vlan != RXD_ERR_ODD_NIBBLE_RCVD_MII))
		goto out;

	rx_len = ((desc->idx_len & RXD_LEN_MASK) >> RXD_LEN_SHIFT) - 4;
	if (rx_len != tx_len)
		goto out;

	rx_iovec = tp->rx_std_buffers[desc_idx].iovec;

	for (i = 14; i < tx_len; i++) {
		if (*(u8_t *) (rx_iovec->iov_addr + i) != (u8_t) (i & 0xff))
			goto out;
	}
	err = 0;

out:
	return err;
}

#define TG3_MAC_LOOPBACK_FAILED		1
#define TG3_PHY_LOOPBACK_FAILED		2
#define TG3_LOOPBACK_FAILED		(TG3_MAC_LOOPBACK_FAILED |	\
					 TG3_PHY_LOOPBACK_FAILED)

PRIVATE int tg3_test_loopback(tg3_t * tp)
{
	int err = 0;
	u32_t cpmuctrl = 0;

	if (!tg3_enabled(tp))
		return TG3_LOOPBACK_FAILED;

	err = tg3_reset_hw(tp, 1);
	if (err)
		return TG3_LOOPBACK_FAILED;

	/* Turn off gphy autopowerdown. */
	if (tp->tg3_flags3 & TG3_FLG3_PHY_ENABLE_APD)
		tg3_phy_toggle_apd(tp, FALSE);

	if (tp->tg3_flags & TG3_FLAG_CPMU_PRESENT) {
		int i;
		u32_t status;

		tw32(TG3_CPMU_MUTEX_REQ, CPMU_MUTEX_REQ_DRIVER);

		/* Wait for up to 40 microseconds to acquire lock. */
		for (i = 0; i < 4; i++) {
			status = tr32(TG3_CPMU_MUTEX_GNT);
			if (status == CPMU_MUTEX_GNT_DRIVER)
				break;
			micro_delay(10);
		}

		if (status != CPMU_MUTEX_GNT_DRIVER)
			return TG3_LOOPBACK_FAILED;

		/* Turn off link-based power management. */
		cpmuctrl = tr32(TG3_CPMU_CTRL);
		tw32(TG3_CPMU_CTRL,
		     cpmuctrl & ~(CPMU_CTRL_LINK_SPEED_MODE |
				  CPMU_CTRL_LINK_AWARE_MODE));
	}
	if (tg3_run_loopback(tp, TG3_MAC_LOOPBACK))
		err |= TG3_MAC_LOOPBACK_FAILED;

	if (tp->tg3_flags & TG3_FLAG_CPMU_PRESENT) {
		tw32(TG3_CPMU_CTRL, cpmuctrl);

		/* Release the mutex */
		tw32(TG3_CPMU_MUTEX_GNT, CPMU_MUTEX_GNT_DRIVER);
	}
	if (!(tp->tg3_flags2 & TG3_FLG2_PHY_SERDES) &&
	    !(tp->tg3_flags3 & TG3_FLG3_USE_PHYLIB)) {
		if (tg3_run_loopback(tp, TG3_PHY_LOOPBACK))
			err |= TG3_PHY_LOOPBACK_FAILED;
	}
	/* Re-enable gphy autopowerdown. */
	if (tp->tg3_flags3 & TG3_FLG3_PHY_ENABLE_APD)
		tg3_phy_toggle_apd(tp, TRUE);

	return err;
}

PRIVATE void tg3_self_test(tg3_t * tp)
{
	if (tp->link_config.phy_is_low_power) {
		printf("PHY is low power. Could get unpredictable here\n");
		tg3_set_power_state(tp, PCI_D0);
	}
	if (tg3_test_nvram(tp) != 0) {
		printf("Test NVRAM Failed\n");
	}
	if (tg3_test_link(tp) != 0) {
		printf("Test Link Failed\n");
	}
	if (1) {
		int err, err2 = 0, irq_sync = 0;

		if (tg3_enabled(tp)) {
			tg3_phy_stop(tp);
			irq_sync = 1;
		}
		tg3_full_lock(tp, irq_sync);

		tg3_halt(tp, RESET_KIND_SUSPEND, 1);
		err = tg3_nvram_lock(tp);
		tg3_halt_cpu(tp, RX_CPU_BASE);
		if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS))
			tg3_halt_cpu(tp, TX_CPU_BASE);
		if (!err)
			tg3_nvram_unlock(tp);

		if (tp->tg3_flags2 & TG3_FLG2_MII_SERDES)
			tg3_phy_reset(tp);

		if (tg3_test_registers(tp) != 0) {
			printf("Test registers failed\n");
		}
		if (tg3_test_memory(tp) != 0) {
			printf("Test Memory Failed\n");
		}
		if (tg3_test_loopback(tp) != 0)
			printf("Test Loopback Failed\n");

		tg3_full_unlock(tp);

		if (tg3_test_interrupt(tp) != 0) {
			printf("Test Interrupt Failed\n");
		}
		tg3_full_lock(tp, 0);

		tg3_halt(tp, RESET_KIND_SHUTDOWN, 1);
		if (tg3_enabled(tp)) {
			tp->tg3_flags |= TG3_FLAG_INIT_COMPLETE;
			err2 = tg3_restart_hw(tp, 1);
			if (!err2)
				tg3_start(tp);
		}
		tg3_full_unlock(tp);

		if (irq_sync && !err2)
			tg3_phy_start(tp);
	}
	if (tp->link_config.phy_is_low_power)
		tg3_set_power_state(tp, PCI_D3hot);

	printf("%s Self-Test Complete\n", tp->name);
}

PRIVATE void tg3_get_eeprom_size(tg3_t * tp)
{
	u32_t cursize, val, magic;

	tp->nvram_size = EEPROM_CHIP_SIZE;

	if (tg3_nvram_read(tp, 0, &magic) != 0)
		return;

	if ((magic != TG3_EEPROM_MAGIC) &&
	    ((magic & TG3_EEPROM_MAGIC_FW_MSK) != TG3_EEPROM_MAGIC_FW) &&
	    ((magic & TG3_EEPROM_MAGIC_HW_MSK) != TG3_EEPROM_MAGIC_HW))
		return;


	/* Size the chip by reading offsets at increasing powers of two. When
	 * we encounter our validation signature, we know the addressing has
	 * wrapped around, and thus have our chip size. */
	cursize = 0x10;

	while (cursize < tp->nvram_size) {
		if (tg3_nvram_read(tp, cursize, &val) != 0)
			return;

		if (val == magic)
			break;

		cursize <<= 1;
	}

	tp->nvram_size = cursize;
}

PRIVATE void tg3_get_nvram_size(tg3_t * tp)
{
	u32_t val;

	if ((tp->tg3_flags3 & TG3_FLG3_NO_NVRAM) ||
	    tg3_nvram_read(tp, 0, &val) != 0)
		return;

	/* Selfboot format */
	if (val != TG3_EEPROM_MAGIC) {
		tg3_get_eeprom_size(tp);
		return;
	}
	if (tg3_nvram_read(tp, 0xf0, &val) == 0) {
		if (val != 0) {
			/* This is confusing.  We want to operate on the 16-bit
			 * value at offset 0xf2.  The tg3_nvram_read() call
			 * will read from NVRAM and byteswap the data according
			 * to the byteswapping settings for all other register
			 * accesses.  This ensures the data we want will always
			 * reside in the lower 16-bits. However, the data in
			 * NVRAM is in LE format, which means the data from the
			 * NVRAM read will always be opposite the endianness of
			 * the CPU.  The 16-bit byteswap then brings the data
			 * to CPU endianness. */
			tp->nvram_size = swab16((u16_t) (val & 0x0000ffff)) * 1024;
			return;
		}
	}
	tp->nvram_size = TG3_NVRAM_SIZE_512KB;
}

PRIVATE void tg3_get_nvram_info(tg3_t * tp)
{
	u32_t nvcfg1;

	nvcfg1 = tr32(NVRAM_CFG1);
	if (nvcfg1 & NVRAM_CFG1_FLASHIF_ENAB) {
		tp->tg3_flags2 |= TG3_FLG2_FLASH;
	} else {
		nvcfg1 &= ~NVRAM_CFG1_COMPAT_BYPASS;
		tw32(NVRAM_CFG1, nvcfg1);
	}

	if ((GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5750) ||
	    (tp->tg3_flags2 & TG3_FLG2_5780_CLASS)) {
		switch (nvcfg1 & NVRAM_CFG1_VENDOR_MASK) {
		case FLASH_VENDOR_ATMEL_FLASH_BUFFERED:
			tp->nvram_jedecnum = JEDEC_ATMEL;
			tp->nvram_pagesize = ATMEL_AT45DB0X1B_PAGE_SIZE;
			tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
			break;
		case FLASH_VENDOR_ATMEL_FLASH_UNBUFFERED:
			tp->nvram_jedecnum = JEDEC_ATMEL;
			tp->nvram_pagesize = ATMEL_AT25F512_PAGE_SIZE;
			break;
		case FLASH_VENDOR_ATMEL_EEPROM:
			tp->nvram_jedecnum = JEDEC_ATMEL;
			tp->nvram_pagesize = ATMEL_AT24C512_CHIP_SIZE;
			tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
			break;
		case FLASH_VENDOR_ST:
			tp->nvram_jedecnum = JEDEC_ST;
			tp->nvram_pagesize = ST_M45PEX0_PAGE_SIZE;
			tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
			break;
		case FLASH_VENDOR_SAIFUN:
			tp->nvram_jedecnum = JEDEC_SAIFUN;
			tp->nvram_pagesize = SAIFUN_SA25F0XX_PAGE_SIZE;
			break;
		case FLASH_VENDOR_SST_SMALL:
		case FLASH_VENDOR_SST_LARGE:
			tp->nvram_jedecnum = JEDEC_SST;
			tp->nvram_pagesize = SST_25VF0X0_PAGE_SIZE;
			break;
		}
	} else {
		tp->nvram_jedecnum = JEDEC_ATMEL;
		tp->nvram_pagesize = ATMEL_AT45DB0X1B_PAGE_SIZE;
		tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
	}
}

PRIVATE void tg3_get_5752_nvram_info(tg3_t * tp)
{
	u32_t nvcfg1;

	nvcfg1 = tr32(NVRAM_CFG1);

	/* NVRAM protection for TPM */
	if (nvcfg1 & (1 << 27))
		tp->tg3_flags2 |= TG3_FLG2_PROTECTED_NVRAM;

	switch (nvcfg1 & NVRAM_CFG1_5752VENDOR_MASK) {
	case FLASH_5752VENDOR_ATMEL_EEPROM_64KHZ:
	case FLASH_5752VENDOR_ATMEL_EEPROM_376KHZ:
		tp->nvram_jedecnum = JEDEC_ATMEL;
		tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
		break;
	case FLASH_5752VENDOR_ATMEL_FLASH_BUFFERED:
		tp->nvram_jedecnum = JEDEC_ATMEL;
		tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
		tp->tg3_flags2 |= TG3_FLG2_FLASH;
		break;
	case FLASH_5752VENDOR_ST_M45PE10:
	case FLASH_5752VENDOR_ST_M45PE20:
	case FLASH_5752VENDOR_ST_M45PE40:
		tp->nvram_jedecnum = JEDEC_ST;
		tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
		tp->tg3_flags2 |= TG3_FLG2_FLASH;
		break;
	}

	if (tp->tg3_flags2 & TG3_FLG2_FLASH) {
		switch (nvcfg1 & NVRAM_CFG1_5752PAGE_SIZE_MASK) {
		case FLASH_5752PAGE_SIZE_256:
			tp->nvram_pagesize = 256;
			break;
		case FLASH_5752PAGE_SIZE_512:
			tp->nvram_pagesize = 512;
			break;
		case FLASH_5752PAGE_SIZE_1K:
			tp->nvram_pagesize = 1024;
			break;
		case FLASH_5752PAGE_SIZE_2K:
			tp->nvram_pagesize = 2048;
			break;
		case FLASH_5752PAGE_SIZE_4K:
			tp->nvram_pagesize = 4096;
			break;
		case FLASH_5752PAGE_SIZE_264:
			tp->nvram_pagesize = 264;
			break;
		}
	} else {
		/* For eeprom, set pagesize to maximum eeprom size */
		tp->nvram_pagesize = ATMEL_AT24C512_CHIP_SIZE;

		nvcfg1 &= ~NVRAM_CFG1_COMPAT_BYPASS;
		tw32(NVRAM_CFG1, nvcfg1);
	}
}

PRIVATE void tg3_get_5755_nvram_info(tg3_t * tp)
{
	u32_t nvcfg1, protect = 0;

	nvcfg1 = tr32(NVRAM_CFG1);

	/* NVRAM protection for TPM */
	if (nvcfg1 & (1 << 27)) {
		tp->tg3_flags2 |= TG3_FLG2_PROTECTED_NVRAM;
		protect = 1;
	}
	nvcfg1 &= NVRAM_CFG1_5752VENDOR_MASK;
	switch (nvcfg1) {
	case FLASH_5755VENDOR_ATMEL_FLASH_1:
	case FLASH_5755VENDOR_ATMEL_FLASH_2:
	case FLASH_5755VENDOR_ATMEL_FLASH_3:
	case FLASH_5755VENDOR_ATMEL_FLASH_5:
		tp->nvram_jedecnum = JEDEC_ATMEL;
		tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
		tp->tg3_flags2 |= TG3_FLG2_FLASH;
		tp->nvram_pagesize = 264;
		if (nvcfg1 == FLASH_5755VENDOR_ATMEL_FLASH_1 ||
		    nvcfg1 == FLASH_5755VENDOR_ATMEL_FLASH_5)
			tp->nvram_size = (protect ? 0x3e200 :
					  TG3_NVRAM_SIZE_512KB);
		else if (nvcfg1 == FLASH_5755VENDOR_ATMEL_FLASH_2)
			tp->nvram_size = (protect ? 0x1f200 :
					  TG3_NVRAM_SIZE_256KB);
		else
			tp->nvram_size = (protect ? 0x1f200 :
					  TG3_NVRAM_SIZE_128KB);
		break;
	case FLASH_5752VENDOR_ST_M45PE10:
	case FLASH_5752VENDOR_ST_M45PE20:
	case FLASH_5752VENDOR_ST_M45PE40:
		tp->nvram_jedecnum = JEDEC_ST;
		tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
		tp->tg3_flags2 |= TG3_FLG2_FLASH;
		tp->nvram_pagesize = 256;
		if (nvcfg1 == FLASH_5752VENDOR_ST_M45PE10)
			tp->nvram_size = (protect ?
					  TG3_NVRAM_SIZE_64KB :
					  TG3_NVRAM_SIZE_128KB);
		else if (nvcfg1 == FLASH_5752VENDOR_ST_M45PE20)
			tp->nvram_size = (protect ?
					  TG3_NVRAM_SIZE_64KB :
					  TG3_NVRAM_SIZE_256KB);
		else
			tp->nvram_size = (protect ?
					  TG3_NVRAM_SIZE_128KB :
					  TG3_NVRAM_SIZE_512KB);
		break;
	}
}

PRIVATE void tg3_get_5787_nvram_info(tg3_t * tp)
{
	u32_t nvcfg1;

	nvcfg1 = tr32(NVRAM_CFG1);

	switch (nvcfg1 & NVRAM_CFG1_5752VENDOR_MASK) {
	case FLASH_5787VENDOR_ATMEL_EEPROM_64KHZ:
	case FLASH_5787VENDOR_ATMEL_EEPROM_376KHZ:
	case FLASH_5787VENDOR_MICRO_EEPROM_64KHZ:
	case FLASH_5787VENDOR_MICRO_EEPROM_376KHZ:
		tp->nvram_jedecnum = JEDEC_ATMEL;
		tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
		tp->nvram_pagesize = ATMEL_AT24C512_CHIP_SIZE;

		nvcfg1 &= ~NVRAM_CFG1_COMPAT_BYPASS;
		tw32(NVRAM_CFG1, nvcfg1);
		break;
	case FLASH_5752VENDOR_ATMEL_FLASH_BUFFERED:
	case FLASH_5755VENDOR_ATMEL_FLASH_1:
	case FLASH_5755VENDOR_ATMEL_FLASH_2:
	case FLASH_5755VENDOR_ATMEL_FLASH_3:
		tp->nvram_jedecnum = JEDEC_ATMEL;
		tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
		tp->tg3_flags2 |= TG3_FLG2_FLASH;
		tp->nvram_pagesize = 264;
		break;
	case FLASH_5752VENDOR_ST_M45PE10:
	case FLASH_5752VENDOR_ST_M45PE20:
	case FLASH_5752VENDOR_ST_M45PE40:
		tp->nvram_jedecnum = JEDEC_ST;
		tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
		tp->tg3_flags2 |= TG3_FLG2_FLASH;
		tp->nvram_pagesize = 256;
		break;
	}
}

PRIVATE void tg3_get_5761_nvram_info(tg3_t * tp)
{
	u32_t nvcfg1, protect = 0;

	nvcfg1 = tr32(NVRAM_CFG1);

	/* NVRAM protection for TPM */
	if (nvcfg1 & (1 << 27)) {
		tp->tg3_flags2 |= TG3_FLG2_PROTECTED_NVRAM;
		protect = 1;
	}
	nvcfg1 &= NVRAM_CFG1_5752VENDOR_MASK;
	switch (nvcfg1) {
	case FLASH_5761VENDOR_ATMEL_ADB021D:
	case FLASH_5761VENDOR_ATMEL_ADB041D:
	case FLASH_5761VENDOR_ATMEL_ADB081D:
	case FLASH_5761VENDOR_ATMEL_ADB161D:
	case FLASH_5761VENDOR_ATMEL_MDB021D:
	case FLASH_5761VENDOR_ATMEL_MDB041D:
	case FLASH_5761VENDOR_ATMEL_MDB081D:
	case FLASH_5761VENDOR_ATMEL_MDB161D:
		tp->nvram_jedecnum = JEDEC_ATMEL;
		tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
		tp->tg3_flags2 |= TG3_FLG2_FLASH;
		tp->tg3_flags3 |= TG3_FLG3_NO_NVRAM_ADDR_TRANS;
		tp->nvram_pagesize = 256;
		break;
	case FLASH_5761VENDOR_ST_A_M45PE20:
	case FLASH_5761VENDOR_ST_A_M45PE40:
	case FLASH_5761VENDOR_ST_A_M45PE80:
	case FLASH_5761VENDOR_ST_A_M45PE16:
	case FLASH_5761VENDOR_ST_M_M45PE20:
	case FLASH_5761VENDOR_ST_M_M45PE40:
	case FLASH_5761VENDOR_ST_M_M45PE80:
	case FLASH_5761VENDOR_ST_M_M45PE16:
		tp->nvram_jedecnum = JEDEC_ST;
		tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
		tp->tg3_flags2 |= TG3_FLG2_FLASH;
		tp->nvram_pagesize = 256;
		break;
	}

	if (protect) {
		tp->nvram_size = tr32(NVRAM_ADDR_LOCKOUT);
	} else {
		switch (nvcfg1) {
		case FLASH_5761VENDOR_ATMEL_ADB161D:
		case FLASH_5761VENDOR_ATMEL_MDB161D:
		case FLASH_5761VENDOR_ST_A_M45PE16:
		case FLASH_5761VENDOR_ST_M_M45PE16:
			tp->nvram_size = TG3_NVRAM_SIZE_2MB;
			break;
		case FLASH_5761VENDOR_ATMEL_ADB081D:
		case FLASH_5761VENDOR_ATMEL_MDB081D:
		case FLASH_5761VENDOR_ST_A_M45PE80:
		case FLASH_5761VENDOR_ST_M_M45PE80:
			tp->nvram_size = TG3_NVRAM_SIZE_1MB;
			break;
		case FLASH_5761VENDOR_ATMEL_ADB041D:
		case FLASH_5761VENDOR_ATMEL_MDB041D:
		case FLASH_5761VENDOR_ST_A_M45PE40:
		case FLASH_5761VENDOR_ST_M_M45PE40:
			tp->nvram_size = TG3_NVRAM_SIZE_512KB;
			break;
		case FLASH_5761VENDOR_ATMEL_ADB021D:
		case FLASH_5761VENDOR_ATMEL_MDB021D:
		case FLASH_5761VENDOR_ST_A_M45PE20:
		case FLASH_5761VENDOR_ST_M_M45PE20:
			tp->nvram_size = TG3_NVRAM_SIZE_256KB;
			break;
		}
	}
}

PRIVATE void tg3_get_5906_nvram_info(tg3_t * tp)
{
	tp->nvram_jedecnum = JEDEC_ATMEL;
	tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
	tp->nvram_pagesize = ATMEL_AT24C512_CHIP_SIZE;
}

PRIVATE void tg3_get_57780_nvram_info(tg3_t * tp)
{
	u32_t nvcfg1;

	nvcfg1 = tr32(NVRAM_CFG1);

	switch (nvcfg1 & NVRAM_CFG1_5752VENDOR_MASK) {
	case FLASH_5787VENDOR_ATMEL_EEPROM_376KHZ:
	case FLASH_5787VENDOR_MICRO_EEPROM_376KHZ:
		tp->nvram_jedecnum = JEDEC_ATMEL;
		tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
		tp->nvram_pagesize = ATMEL_AT24C512_CHIP_SIZE;

		nvcfg1 &= ~NVRAM_CFG1_COMPAT_BYPASS;
		tw32(NVRAM_CFG1, nvcfg1);
		return;
	case FLASH_5752VENDOR_ATMEL_FLASH_BUFFERED:
	case FLASH_57780VENDOR_ATMEL_AT45DB011D:
	case FLASH_57780VENDOR_ATMEL_AT45DB011B:
	case FLASH_57780VENDOR_ATMEL_AT45DB021D:
	case FLASH_57780VENDOR_ATMEL_AT45DB021B:
	case FLASH_57780VENDOR_ATMEL_AT45DB041D:
	case FLASH_57780VENDOR_ATMEL_AT45DB041B:
		tp->nvram_jedecnum = JEDEC_ATMEL;
		tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
		tp->tg3_flags2 |= TG3_FLG2_FLASH;

		switch (nvcfg1 & NVRAM_CFG1_5752VENDOR_MASK) {
		case FLASH_5752VENDOR_ATMEL_FLASH_BUFFERED:
		case FLASH_57780VENDOR_ATMEL_AT45DB011D:
		case FLASH_57780VENDOR_ATMEL_AT45DB011B:
			tp->nvram_size = TG3_NVRAM_SIZE_128KB;
			break;
		case FLASH_57780VENDOR_ATMEL_AT45DB021D:
		case FLASH_57780VENDOR_ATMEL_AT45DB021B:
			tp->nvram_size = TG3_NVRAM_SIZE_256KB;
			break;
		case FLASH_57780VENDOR_ATMEL_AT45DB041D:
		case FLASH_57780VENDOR_ATMEL_AT45DB041B:
			tp->nvram_size = TG3_NVRAM_SIZE_512KB;
			break;
		}
		break;
	case FLASH_5752VENDOR_ST_M45PE10:
	case FLASH_5752VENDOR_ST_M45PE20:
	case FLASH_5752VENDOR_ST_M45PE40:
		tp->nvram_jedecnum = JEDEC_ST;
		tp->tg3_flags |= TG3_FLAG_NVRAM_BUFFERED;
		tp->tg3_flags2 |= TG3_FLG2_FLASH;

		switch (nvcfg1 & NVRAM_CFG1_5752VENDOR_MASK) {
		case FLASH_5752VENDOR_ST_M45PE10:
			tp->nvram_size = TG3_NVRAM_SIZE_128KB;
			break;
		case FLASH_5752VENDOR_ST_M45PE20:
			tp->nvram_size = TG3_NVRAM_SIZE_256KB;
			break;
		case FLASH_5752VENDOR_ST_M45PE40:
			tp->nvram_size = TG3_NVRAM_SIZE_512KB;
			break;
		}
		break;
	default:
		tp->tg3_flags3 |= TG3_FLG3_NO_NVRAM;
		return;
	}

	switch (nvcfg1 & NVRAM_CFG1_5752PAGE_SIZE_MASK) {
	case FLASH_5752PAGE_SIZE_256:
		tp->tg3_flags3 |= TG3_FLG3_NO_NVRAM_ADDR_TRANS;
		tp->nvram_pagesize = 256;
		break;
	case FLASH_5752PAGE_SIZE_512:
		tp->tg3_flags3 |= TG3_FLG3_NO_NVRAM_ADDR_TRANS;
		tp->nvram_pagesize = 512;
		break;
	case FLASH_5752PAGE_SIZE_1K:
		tp->tg3_flags3 |= TG3_FLG3_NO_NVRAM_ADDR_TRANS;
		tp->nvram_pagesize = 1024;
		break;
	case FLASH_5752PAGE_SIZE_2K:
		tp->tg3_flags3 |= TG3_FLG3_NO_NVRAM_ADDR_TRANS;
		tp->nvram_pagesize = 2048;
		break;
	case FLASH_5752PAGE_SIZE_4K:
		tp->tg3_flags3 |= TG3_FLG3_NO_NVRAM_ADDR_TRANS;
		tp->nvram_pagesize = 4096;
		break;
	case FLASH_5752PAGE_SIZE_264:
		tp->nvram_pagesize = 264;
		break;
	case FLASH_5752PAGE_SIZE_528:
		tp->nvram_pagesize = 528;
		break;
	}
}

/* Chips other than 5700/5701 use the NVRAM for fetching info. */
PRIVATE void tg3_nvram_init(tg3_t * tp)
{
	tw32_f(GRC_EEPROM_ADDR,
	       (EEPROM_ADDR_FSM_RESET |
		(EEPROM_DEFAULT_CLOCK_PERIOD <<
		 EEPROM_ADDR_CLKPERD_SHIFT)));

	micro_delay(1000);

	/* Enable seeprom accesses. */
	tw32_f(GRC_LOCAL_CTRL,
	       tr32(GRC_LOCAL_CTRL) | GRC_LCLCTRL_AUTO_SEEPROM);
	micro_delay(100);
	if (GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5700 &&
	    GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5701) {
		tp->tg3_flags |= TG3_FLAG_NVRAM;

		if (tg3_nvram_lock(tp)) {
			printf("%s: Cannot get nvarm lock, "
			       "tg3_nvram_init failed.\n", tp->name);
			return;
		}
		tg3_enable_nvram_access(tp);

		tp->nvram_size = 0;

		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5752)
			tg3_get_5752_nvram_info(tp);
		else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5755)
			tg3_get_5755_nvram_info(tp);
		else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5787 ||
			 GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5784 ||
			 GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5785)
			tg3_get_5787_nvram_info(tp);
		else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5761)
			tg3_get_5761_nvram_info(tp);
		else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906)
			tg3_get_5906_nvram_info(tp);
		else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_57780)
			tg3_get_57780_nvram_info(tp);
		else
			tg3_get_nvram_info(tp);

		if (tp->nvram_size == 0)
			tg3_get_nvram_size(tp);

		tg3_disable_nvram_access(tp);
		tg3_nvram_unlock(tp);

	} else {
		tp->tg3_flags &= ~(TG3_FLAG_NVRAM | TG3_FLAG_NVRAM_BUFFERED);

		tg3_get_eeprom_size(tp);
	}
}

struct subsys_tbl_ent {
	u16_t subsys_vendor, subsys_devid;
	u32_t phy_id;
};

PRIVATE struct subsys_tbl_ent subsys_id_to_phy_id[] = {

	/* Broadcom boards. */
	{PCI_VENDOR_ID_BROADCOM, 0x1644, PHY_ID_BCM5401},	/* BCM95700A6 */
	{PCI_VENDOR_ID_BROADCOM, 0x0001, PHY_ID_BCM5701},	/* BCM95701A5 */
	{PCI_VENDOR_ID_BROADCOM, 0x0002, PHY_ID_BCM8002},	/* BCM95700T6 */
	{PCI_VENDOR_ID_BROADCOM, 0x0003, 0},				/* BCM95700A9 */
	{PCI_VENDOR_ID_BROADCOM, 0x0005, PHY_ID_BCM5701},	/* BCM95701T1 */
	{PCI_VENDOR_ID_BROADCOM, 0x0006, PHY_ID_BCM5701},	/* BCM95701T8 */
	{PCI_VENDOR_ID_BROADCOM, 0x0007, 0},				/* BCM95701A7 */
	{PCI_VENDOR_ID_BROADCOM, 0x0008, PHY_ID_BCM5701},	/* BCM95701A10 */
	{PCI_VENDOR_ID_BROADCOM, 0x8008, PHY_ID_BCM5701},	/* BCM95701A12 */
	{PCI_VENDOR_ID_BROADCOM, 0x0009, PHY_ID_BCM5703},	/* BCM95703Ax1 */
	{PCI_VENDOR_ID_BROADCOM, 0x8009, PHY_ID_BCM5703},	/* BCM95703Ax2 */

	/* 3com boards. */
	{PCI_VENDOR_ID_3COM, 0x1000, PHY_ID_BCM5401},		/* 3C996T */
	{PCI_VENDOR_ID_3COM, 0x1006, PHY_ID_BCM5701},		/* 3C996BT */
	{PCI_VENDOR_ID_3COM, 0x1004, 0},					/* 3C996SX */
	{PCI_VENDOR_ID_3COM, 0x1007, PHY_ID_BCM5701},		/* 3C1000T */
	{PCI_VENDOR_ID_3COM, 0x1008, PHY_ID_BCM5701},		/* 3C940BR01 */

	/* DELL boards. */
	{PCI_VENDOR_ID_DELL, 0x00d1, PHY_ID_BCM5401},		/* VIPER */
	{PCI_VENDOR_ID_DELL, 0x0106, PHY_ID_BCM5401},		/* JAGUAR */
	{PCI_VENDOR_ID_DELL, 0x0109, PHY_ID_BCM5411},		/* MERLOT */
	{PCI_VENDOR_ID_DELL, 0x010a, PHY_ID_BCM5411},		/* SLIM_MERLOT */

	/* Compaq boards. */
	{PCI_VENDOR_ID_COMPAQ, 0x007c, PHY_ID_BCM5701},		/* BANSHEE */
	{PCI_VENDOR_ID_COMPAQ, 0x009a, PHY_ID_BCM5701},		/* BANSHEE_2 */
	{PCI_VENDOR_ID_COMPAQ, 0x007d, 0},					/* CHANGELING */
	{PCI_VENDOR_ID_COMPAQ, 0x0085, PHY_ID_BCM5701},		/* NC7780 */
	{PCI_VENDOR_ID_COMPAQ, 0x0099, PHY_ID_BCM5701},		/* NC7780_2 */

	/* IBM boards. */
	{PCI_VENDOR_ID_IBM, 0x0281, 0}						/* IBM??? */
};

PRIVATE struct subsys_tbl_ent *lookup_by_subsys(tg3_t * tp)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(subsys_id_to_phy_id); i++) {
		if ((subsys_id_to_phy_id[i].subsys_vendor ==
		     tp->subsystem_vendor) &&
		    (subsys_id_to_phy_id[i].subsys_devid ==
		     tp->subsystem_device))
			return &subsys_id_to_phy_id[i];
	}
	return NULL;
}

PRIVATE void tg3_get_eeprom_hw_cfg(tg3_t * tp)
{
	u32_t val;
	u16_t pmcsr;

	/* On some early chips the SRAM cannot be accessed in D3hot state, so
	 * need make sure we're in D0. */
	pmcsr = pci_attr_r16(tp->devind, tp->pm_cap + PCI_PM_CTRL);
	pmcsr &= ~PCI_PM_CTRL_STATE_MASK;

	pci_attr_w16(tp->devind, tp->pm_cap + PCI_PM_CTRL, pmcsr);

	micro_delay(1000);
	/* Make sure register accesses (indirect or otherwise) will function
	 * correctly. */

	pci_attr_w32(tp->devind, TG3PCI_MISC_HOST_CTRL, tp->misc_host_ctrl);

	/* The memory arbiter has to be enabled in order for SRAM accesses to
	 * succeed.  Normally on powerup the tg3 chip firmware will make sure
	 * it is enabled, but other entities such as system netboot code might
	 * disable it. */
	val = tr32(MEMARB_MODE);
	tw32(MEMARB_MODE, val | MEMARB_MODE_ENABLE);

	tp->phy_id = PHY_ID_INVALID;
	tp->led_ctrl = LED_CTRL_MODE_PHY_1;

	/* Assume an onboard device and WOL capable by default. */
	tp->tg3_flags |= TG3_FLAG_EEPROM_WRITE_PROT | TG3_FLAG_WOL_CAP;

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) {
		if (!(tr32(PCIE_TRANSACTION_CFG) & PCIE_TRANS_CFG_LOM)) {
			tp->tg3_flags &= ~TG3_FLAG_EEPROM_WRITE_PROT;
			tp->tg3_flags2 |= TG3_FLG2_IS_NIC;
		}
		val = tr32(VCPU_CFGSHDW);
		if (val & VCPU_CFGSHDW_ASPM_DBNC)
			tp->tg3_flags |= TG3_FLAG_ASPM_WORKAROUND;
		if ((val & VCPU_CFGSHDW_WOL_ENABLE) &&
		    (val & VCPU_CFGSHDW_WOL_MAGPKT))
			tp->tg3_flags |= TG3_FLAG_WOL_ENABLE;
		goto done;
	}
	tg3_read_mem(tp, NIC_SRAM_DATA_SIG, &val);

	if (val == NIC_SRAM_DATA_SIG_MAGIC) {
		u32_t nic_cfg, led_cfg;
		u32_t nic_phy_id, ver, cfg2 = 0, cfg4 = 0, eeprom_phy_id;
		int eeprom_phy_serdes = 0;

		tg3_read_mem(tp, NIC_SRAM_DATA_CFG, &nic_cfg);
		tp->nic_sram_data_cfg = nic_cfg;

		tg3_read_mem(tp, NIC_SRAM_DATA_VER, &ver);
		ver >>= NIC_SRAM_DATA_VER_SHIFT;
		if ((GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5700) &&
		    (GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5701) &&
		    (GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5703) &&
		    (ver > 0) && (ver < 0x100))
			tg3_read_mem(tp, NIC_SRAM_DATA_CFG_2, &cfg2);

		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5785)
			tg3_read_mem(tp, NIC_SRAM_DATA_CFG_4, &cfg4);

		if ((nic_cfg & NIC_SRAM_DATA_CFG_PHY_TYPE_MASK) ==
		    NIC_SRAM_DATA_CFG_PHY_TYPE_FIBER)
			eeprom_phy_serdes = 1;

		tg3_read_mem(tp, NIC_SRAM_DATA_PHY_ID, &nic_phy_id);
		if (nic_phy_id != 0) {
			u32_t id1 = nic_phy_id & NIC_SRAM_DATA_PHY_ID1_MASK;
			u32_t id2 = nic_phy_id & NIC_SRAM_DATA_PHY_ID2_MASK;

			eeprom_phy_id = (id1 >> 16) << 10;
			eeprom_phy_id |= (id2 & 0xfc00) << 16;
			eeprom_phy_id |= (id2 & 0x03ff) << 0;
		} else
			eeprom_phy_id = 0;

		tp->phy_id = eeprom_phy_id;
		if (eeprom_phy_serdes) {
			if (tp->tg3_flags2 & TG3_FLG2_5780_CLASS)
				tp->tg3_flags2 |= TG3_FLG2_MII_SERDES;
			else
				tp->tg3_flags2 |= TG3_FLG2_PHY_SERDES;
		}
		if (tp->tg3_flags2 & TG3_FLG2_5750_PLUS)
			led_cfg = cfg2 & (NIC_SRAM_DATA_CFG_LED_MODE_MASK |
					  SHASTA_EXT_LED_MODE_MASK);
		else
			led_cfg = nic_cfg & NIC_SRAM_DATA_CFG_LED_MODE_MASK;

		switch (led_cfg) {
		default:
		case NIC_SRAM_DATA_CFG_LED_MODE_PHY_1:
			tp->led_ctrl = LED_CTRL_MODE_PHY_1;
			break;

		case NIC_SRAM_DATA_CFG_LED_MODE_PHY_2:
			tp->led_ctrl = LED_CTRL_MODE_PHY_2;
			break;

		case NIC_SRAM_DATA_CFG_LED_MODE_MAC:
			tp->led_ctrl = LED_CTRL_MODE_MAC;

			/* Default to PHY_1_MODE if 0 (MAC_MODE) is read on
			 * some older 5700/5701 bootcode. */
			if (GET_ASIC_REV(tp->pci_chip_rev_id) ==
			    ASIC_REV_5700 ||
			    GET_ASIC_REV(tp->pci_chip_rev_id) ==
			    ASIC_REV_5701)
				tp->led_ctrl = LED_CTRL_MODE_PHY_1;

			break;

		case SHASTA_EXT_LED_SHARED:
			tp->led_ctrl = LED_CTRL_MODE_SHARED;
			if (tp->pci_chip_rev_id != CHIPREV_ID_5750_A0 &&
			    tp->pci_chip_rev_id != CHIPREV_ID_5750_A1)
				tp->led_ctrl |= (LED_CTRL_MODE_PHY_1 |
						 LED_CTRL_MODE_PHY_2);
			break;

		case SHASTA_EXT_LED_MAC:
			tp->led_ctrl = LED_CTRL_MODE_SHASTA_MAC;
			break;

		case SHASTA_EXT_LED_COMBO:
			tp->led_ctrl = LED_CTRL_MODE_COMBO;
			if (tp->pci_chip_rev_id != CHIPREV_ID_5750_A0)
				tp->led_ctrl |= (LED_CTRL_MODE_PHY_1 |
						 LED_CTRL_MODE_PHY_2);
			break;

		}

		if ((GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5700 ||
		     GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5701) &&
		    tp->subsystem_vendor == PCI_VENDOR_ID_DELL)
			tp->led_ctrl = LED_CTRL_MODE_PHY_2;

		if (GET_CHIP_REV(tp->pci_chip_rev_id) == CHIPREV_5784_AX)
			tp->led_ctrl = LED_CTRL_MODE_PHY_1;

		if (nic_cfg & NIC_SRAM_DATA_CFG_EEPROM_WP) {
			tp->tg3_flags |= TG3_FLAG_EEPROM_WRITE_PROT;
			if ((tp->subsystem_vendor ==
			     PCI_VENDOR_ID_ARIMA) &&
			    (tp->subsystem_device == 0x205a ||
			     tp->subsystem_device == 0x2063))
				tp->tg3_flags &= ~TG3_FLAG_EEPROM_WRITE_PROT;
		} else {
			tp->tg3_flags &= ~TG3_FLAG_EEPROM_WRITE_PROT;
			tp->tg3_flags2 |= TG3_FLG2_IS_NIC;
		}

		if (nic_cfg & NIC_SRAM_DATA_CFG_ASF_ENABLE) {
			tp->tg3_flags |= TG3_FLAG_ENABLE_ASF;
			if (tp->tg3_flags2 & TG3_FLG2_5750_PLUS)
				tp->tg3_flags2 |= TG3_FLG2_ASF_NEW_HANDSHAKE;
		}
		if ((nic_cfg & NIC_SRAM_DATA_CFG_APE_ENABLE) &&
		    (tp->tg3_flags2 & TG3_FLG2_5750_PLUS))
			tp->tg3_flags3 |= TG3_FLG3_ENABLE_APE;

		if (tp->tg3_flags2 & TG3_FLG2_ANY_SERDES &&
		    !(nic_cfg & NIC_SRAM_DATA_CFG_FIBER_WOL))
			tp->tg3_flags &= ~TG3_FLAG_WOL_CAP;

		if ((tp->tg3_flags & TG3_FLAG_WOL_CAP) &&
		    (nic_cfg & NIC_SRAM_DATA_CFG_WOL_ENABLE))
			tp->tg3_flags |= TG3_FLAG_WOL_ENABLE;

		if (cfg2 & (1 << 17))
			tp->tg3_flags2 |= TG3_FLG2_CAPACITIVE_COUPLING;

		/* serdes signal pre-emphasis in register 0x590 set by bootcode
		 * if bit 18 is set */
		if (cfg2 & (1 << 18))
			tp->tg3_flags2 |= TG3_FLG2_SERDES_PREEMPHASIS;

		if (((GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5784 &&
		      GET_CHIP_REV(tp->pci_chip_rev_id) != CHIPREV_5784_AX)) &&
		    (cfg2 & NIC_SRAM_DATA_CFG_2_APD_EN))
			tp->tg3_flags3 |= TG3_FLG3_PHY_ENABLE_APD;

		if (tp->tg3_flags2 & TG3_FLG2_PCI_EXPRESS) {
			u32_t cfg3;

			tg3_read_mem(tp, NIC_SRAM_DATA_CFG_3, &cfg3);
			if (cfg3 & NIC_SRAM_ASPM_DEBOUNCE)
				tp->tg3_flags |= TG3_FLAG_ASPM_WORKAROUND;
		}
		if (cfg4 & NIC_SRAM_RGMII_STD_IBND_DISABLE)
			tp->tg3_flags3 |= TG3_FLG3_RGMII_STD_IBND_DISABLE;
		if (cfg4 & NIC_SRAM_RGMII_EXT_IBND_RX_EN)
			tp->tg3_flags3 |= TG3_FLG3_RGMII_EXT_IBND_RX_EN;
		if (cfg4 & NIC_SRAM_RGMII_EXT_IBND_TX_EN)
			tp->tg3_flags3 |= TG3_FLG3_RGMII_EXT_IBND_TX_EN;
	}
done:
	return;
}

PRIVATE int tg3_issue_otp_command(tg3_t * tp, u32_t cmd)
{
	int i;
	u32_t val;

	tw32(OTP_CTRL, cmd | OTP_CTRL_OTP_CMD_START);
	tw32(OTP_CTRL, cmd);

	/* Wait for up to 1 ms for command to execute. */
	for (i = 0; i < 100; i++) {
		val = tr32(OTP_STATUS);
		if (val & OTP_STATUS_CMD_DONE)
			break;
		micro_delay(10);
	}

	return (val & OTP_STATUS_CMD_DONE) ? 0 : -EBUSY;
}

/* Read the gphy configuration from the OTP region of the chip.  The gphy
 * configuration is a 32-bit value that straddles the alignment boundary.
 * We do two 32-bit reads and then shift and merge the results.
 */
PRIVATE u32_t tg3_read_otp_phycfg(tg3_t * tp)
{
	u32_t bhalf_otp, thalf_otp;

	tw32(OTP_MODE, OTP_MODE_OTP_THRU_GRC);

	if (tg3_issue_otp_command(tp, OTP_CTRL_OTP_CMD_INIT))
		return 0;

	tw32(OTP_ADDRESS, OTP_ADDRESS_MAGIC1);

	if (tg3_issue_otp_command(tp, OTP_CTRL_OTP_CMD_READ))
		return 0;

	thalf_otp = tr32(OTP_READ_DATA);

	tw32(OTP_ADDRESS, OTP_ADDRESS_MAGIC2);

	if (tg3_issue_otp_command(tp, OTP_CTRL_OTP_CMD_READ))
		return 0;

	bhalf_otp = tr32(OTP_READ_DATA);

	return ((thalf_otp & 0x0000ffff) << 16) | (bhalf_otp >> 16);
}

PRIVATE int tg3_phy_probe(tg3_t * tp)
{
	u32_t hw_phy_id_1, hw_phy_id_2;
	u32_t hw_phy_id, hw_phy_id_masked;
	int err;

	/* Reading the PHY ID register can conflict with ASF firmware access to
	 * the PHY hardware. */
	err = 0;
	if ((tp->tg3_flags & TG3_FLAG_ENABLE_ASF) ||
	    (tp->tg3_flags3 & TG3_FLG3_ENABLE_APE)) {
		hw_phy_id = hw_phy_id_masked = PHY_ID_INVALID;
	} else {
		/* Now read the physical PHY_ID from the chip and verify that
		 * it is sane.  If it doesn't look good, we fall back to either
		 * the hard-coded table based PHY_ID and failing that the value
		 * found in the eeprom area. */
		err |= tg3_readphy(tp, MII_PHYSID1, &hw_phy_id_1);
		err |= tg3_readphy(tp, MII_PHYSID2, &hw_phy_id_2);

		hw_phy_id = (hw_phy_id_1 & 0xffff) << 10;
		hw_phy_id |= (hw_phy_id_2 & 0xfc00) << 16;
		hw_phy_id |= (hw_phy_id_2 & 0x03ff) << 0;

		hw_phy_id_masked = hw_phy_id & PHY_ID_MASK;
	}

	if (!err && KNOWN_PHY_ID(hw_phy_id_masked)) {
		tp->phy_id = hw_phy_id;
		if (hw_phy_id_masked == PHY_ID_BCM8002)
			tp->tg3_flags2 |= TG3_FLG2_PHY_SERDES;
		else
			tp->tg3_flags2 &= ~TG3_FLG2_PHY_SERDES;
	} else {
		if (tp->phy_id != PHY_ID_INVALID) {
			/* Do nothing, phy ID already set up in
			 * tg3_get_eeprom_hw_cfg(). */
		} else {
			struct subsys_tbl_ent *p;

			/* No eeprom signature?  Try the hardcoded subsys
			 * device table. */
			p = lookup_by_subsys(tp);
			if (!p) {
				return -ENODEV;
			}
			tp->phy_id = p->phy_id;
			if (!tp->phy_id ||
			    tp->phy_id == PHY_ID_BCM8002)
				tp->tg3_flags2 |= TG3_FLG2_PHY_SERDES;
		}
	}

	if (!(tp->tg3_flags2 & TG3_FLG2_ANY_SERDES) &&
	    !(tp->tg3_flags3 & TG3_FLG3_ENABLE_APE) &&
	    !(tp->tg3_flags & TG3_FLAG_ENABLE_ASF)) {
		u32_t bmsr, adv_reg, tg3_ctrl, mask;

		tg3_readphy(tp, MII_BMSR, &bmsr);
		if (!tg3_readphy(tp, MII_BMSR, &bmsr) &&
		    (bmsr & BMSR_LSTATUS))
			goto skip_phy_reset;

		err = tg3_phy_reset(tp);
		if (err) {
			return err;
		}
		adv_reg = (ADVERTISE_10HALF | ADVERTISE_10FULL |
			   ADVERTISE_100HALF | ADVERTISE_100FULL |
			   ADVERTISE_CSMA | ADVERTISE_PAUSE_CAP);
		tg3_ctrl = 0;
		if (!(tp->tg3_flags & TG3_FLAG_10_100_ONLY)) {
			tg3_ctrl = (MII_TG3_CTRL_ADV_1000_HALF |
				    MII_TG3_CTRL_ADV_1000_FULL);
			if (tp->pci_chip_rev_id == CHIPREV_ID_5701_A0 ||
			    tp->pci_chip_rev_id == CHIPREV_ID_5701_B0)
				tg3_ctrl |= (MII_TG3_CTRL_AS_MASTER |
					     MII_TG3_CTRL_ENABLE_AS_MASTER);
		}
		mask = (ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full |
			ADVERTISED_100baseT_Half | ADVERTISED_100baseT_Full |
			ADVERTISED_1000baseT_Half | ADVERTISED_1000baseT_Full);
		if (!tg3_copper_is_advertising_all(tp, mask)) {
			tg3_writephy(tp, MII_ADVERTISE, adv_reg);

			if (!(tp->tg3_flags & TG3_FLAG_10_100_ONLY))
				tg3_writephy(tp, MII_TG3_CTRL, tg3_ctrl);

			tg3_writephy(tp, MII_BMCR,
				     BMCR_ANENABLE | BMCR_ANRESTART);
		}
		tg3_phy_set_wirespeed(tp);

		tg3_writephy(tp, MII_ADVERTISE, adv_reg);
		if (!(tp->tg3_flags & TG3_FLAG_10_100_ONLY))
			tg3_writephy(tp, MII_TG3_CTRL, tg3_ctrl);
	}
skip_phy_reset:
	if ((tp->phy_id & PHY_ID_MASK) == PHY_ID_BCM5401) {
		err = tg3_init_5401phy_dsp(tp);
		if (err)
			return err;
	}
	if (!err && ((tp->phy_id & PHY_ID_MASK) == PHY_ID_BCM5401)) {
		err = tg3_init_5401phy_dsp(tp);
	}
	if (tp->tg3_flags2 & TG3_FLG2_ANY_SERDES)
		tp->link_config.advertising =
			(ADVERTISED_1000baseT_Half |
			 ADVERTISED_1000baseT_Full |
			 ADVERTISED_Autoneg |
			 ADVERTISED_FIBRE);
	if (tp->tg3_flags & TG3_FLAG_10_100_ONLY)
		tp->link_config.advertising &=
			~(ADVERTISED_1000baseT_Half |
			  ADVERTISED_1000baseT_Full);

	return err;
}

PRIVATE void tg3_read_partno(tg3_t * tp)
{
	unsigned char vpd_data[256];	/* in little-endian format */
	unsigned int i;
	u32_t magic;

	if ((tp->tg3_flags3 & TG3_FLG3_NO_NVRAM) ||
	    tg3_nvram_read(tp, 0x0, &magic))
		goto out_not_found;

	if (magic == TG3_EEPROM_MAGIC) {
		for (i = 0; i < 256; i += 4) {
			u32_t tmp;

			/* The data is in little-endian format in NVRAM. Use
			 * the big-endian read routines to preserve the byte
			 * order as it exists in NVRAM. */
			if (tg3_nvram_read_be32(tp, 0x100 + i, &tmp))
				goto out_not_found;

			memcpy(&vpd_data[i], &tmp, sizeof(tmp));
		}
	} else {
		int vpd_cap;

		pci_find_cap(tp->devind, PCI_CAP_ID_VPD, &vpd_cap);

		for (i = 0; i < 256; i += 4) {
			u32_t tmp, j = 0;
			u32_t v;
			u16_t tmp16;

			pci_attr_w16(tp->devind, vpd_cap + PCI_VPD_ADDR, i);

			while (j++ < 100) {
				tmp16 = pci_attr_r16(tp->devind, vpd_cap +
						     PCI_VPD_ADDR);
				if (tmp16 & 0x8000)
					break;
				micro_delay(1000);
			}
			if (!(tmp16 & 0x8000))
				goto out_not_found;

			tmp = pci_attr_r32(tp->devind, vpd_cap + PCI_VPD_DATA);
			v = cpu_to_le32(tmp);
			memcpy(&vpd_data[i], &v, sizeof(v));
		}
	}

	/* Now parse and find the part number. */
	for (i = 0; i < 254;) {
		unsigned char val = vpd_data[i];
		unsigned int block_end;

		if (val == 0x82 || val == 0x91) {
			i = (i + 3 +
			     (vpd_data[i + 1] +
			      (vpd_data[i + 2] << 8)));
			continue;
		}
		if (val != 0x90)
			goto out_not_found;

		block_end = (i + 3 +
			     (vpd_data[i + 1] +
			      (vpd_data[i + 2] << 8)));
		i += 3;

		if (block_end > 256)
			goto out_not_found;

		while (i < (block_end - 2)) {
			if (vpd_data[i + 0] == 'P' &&
			    vpd_data[i + 1] == 'N') {
				int partno_len = vpd_data[i + 2];

				i += 3;
				if (partno_len > 24 || (partno_len + i) > 256)
					goto out_not_found;

				memcpy(tp->board_part_number,
				       &vpd_data[i], partno_len);

				/* Success. */
				return;
			}
			i += 3 + vpd_data[i + 2];
		}

		/* Part number not found. */
		goto out_not_found;
	}

out_not_found:
	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906)
		strcpy(tp->board_part_number, "BCM95906");
	else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_57780 &&
		 tp->device == TG3PCI_DEVICE_TIGON3_57780)
		strcpy(tp->board_part_number, "BCM57780");
	else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_57780 &&
		 tp->device == TG3PCI_DEVICE_TIGON3_57760)
		strcpy(tp->board_part_number, "BCM57760");
	else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_57780 &&
		 tp->device == TG3PCI_DEVICE_TIGON3_57790)
		strcpy(tp->board_part_number, "BCM57790");
	else
		strcpy(tp->board_part_number, "none");
}

PRIVATE int tg3_fw_img_is_valid(tg3_t * tp, u32_t offset)
{
	u32_t val;

	if (tg3_nvram_read(tp, offset, &val) ||
	    (val & 0xfc000000) != 0x0c000000 ||
	    tg3_nvram_read(tp, offset + 4, &val) ||
	    val != 0)
		return 0;

	return 1;
}

PRIVATE void tg3_read_bc_ver(tg3_t * tp)
{
	u32_t val, offset, start, ver_offset;
	int i;
	int newver = FALSE;

	if (tg3_nvram_read(tp, 0xc, &offset) ||
	    tg3_nvram_read(tp, 0x4, &start))
		return;

	offset = tg3_nvram_logical_addr(tp, offset);

	if (tg3_nvram_read(tp, offset, &val))
		return;

	if ((val & 0xfc000000) == 0x0c000000) {
		if (tg3_nvram_read(tp, offset + 4, &val))
			return;

		if (val == 0)
			newver = TRUE;
	}
	if (newver) {
		if (tg3_nvram_read(tp, offset + 8, &ver_offset))
			return;

		offset = offset + ver_offset - start;
		for (i = 0; i < 16; i += 4) {
			u32_t v;
			if (tg3_nvram_read_be32(tp, offset + i, &v))
				return;

			memcpy(tp->fw_ver + i, &v, sizeof(v));
		}
	} else {
		u32_t major, minor;

		if (tg3_nvram_read(tp, TG3_NVM_PTREV_BCVER, &ver_offset))
			return;

		major = (ver_offset & TG3_NVM_BCVER_MAJMSK) >>
			TG3_NVM_BCVER_MAJSFT;
		minor = ver_offset & TG3_NVM_BCVER_MINMSK;
		snprintf(&tp->fw_ver[0], 32, "v%d.%02d", major, minor);
	}
}

PRIVATE void tg3_read_hwsb_ver(tg3_t * tp)
{
	u32_t val, major, minor;

	/* Use native endian representation */
	if (tg3_nvram_read(tp, TG3_NVM_HWSB_CFG1, &val))
		return;

	major = (val & TG3_NVM_HWSB_CFG1_MAJMSK) >>
		TG3_NVM_HWSB_CFG1_MAJSFT;
	minor = (val & TG3_NVM_HWSB_CFG1_MINMSK) >>
		TG3_NVM_HWSB_CFG1_MINSFT;

	snprintf(&tp->fw_ver[0], 32, "sb v%d.%02d", major, minor);
}

PRIVATE void tg3_read_sb_ver(tg3_t * tp, u32_t val)
{
	u32_t offset, major, minor, build;

	tp->fw_ver[0] = 's';
	tp->fw_ver[1] = 'b';
	tp->fw_ver[2] = '\0';

	if ((val & TG3_EEPROM_SB_FORMAT_MASK) != TG3_EEPROM_SB_FORMAT_1)
		return;

	switch (val & TG3_EEPROM_SB_REVISION_MASK) {
	case TG3_EEPROM_SB_REVISION_0:
		offset = TG3_EEPROM_SB_F1R0_EDH_OFF;
		break;
	case TG3_EEPROM_SB_REVISION_2:
		offset = TG3_EEPROM_SB_F1R2_EDH_OFF;
		break;
	case TG3_EEPROM_SB_REVISION_3:
		offset = TG3_EEPROM_SB_F1R3_EDH_OFF;
		break;
	default:
		return;
	}

	if (tg3_nvram_read(tp, offset, &val))
		return;

	build = (val & TG3_EEPROM_SB_EDH_BLD_MASK) >>
		TG3_EEPROM_SB_EDH_BLD_SHFT;
	major = (val & TG3_EEPROM_SB_EDH_MAJ_MASK) >>
		TG3_EEPROM_SB_EDH_MAJ_SHFT;
	minor = val & TG3_EEPROM_SB_EDH_MIN_MASK;

	if (minor > 99 || build > 26)
		return;

	snprintf(&tp->fw_ver[2], 30, " v%d.%02d", major, minor);

	if (build > 0) {
		tp->fw_ver[8] = 'a' + build - 1;
		tp->fw_ver[9] = '\0';
	}
}

PRIVATE void tg3_read_mgmtfw_ver(tg3_t * tp)
{
	u32_t val, offset, start;
	int i, vlen;

	for (offset = TG3_NVM_DIR_START;
	     offset < TG3_NVM_DIR_END;
	     offset += TG3_NVM_DIRENT_SIZE) {
		if (tg3_nvram_read(tp, offset, &val))
			return;

		if ((val >> TG3_NVM_DIRTYPE_SHIFT) == TG3_NVM_DIRTYPE_ASFINI)
			break;
	}

	if (offset == TG3_NVM_DIR_END)
		return;

	if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS))
		start = 0x08000000;
	else if (tg3_nvram_read(tp, offset - 4, &start))
		return;

	if (tg3_nvram_read(tp, offset + 4, &offset) ||
	    !tg3_fw_img_is_valid(tp, offset) ||
	    tg3_nvram_read(tp, offset + 8, &val))
		return;

	offset += val - start;

	vlen = strlen(tp->fw_ver);

	tp->fw_ver[vlen++] = ',';
	tp->fw_ver[vlen++] = ' ';

	for (i = 0; i < 4; i++) {
		u32_t v;
		if (tg3_nvram_read_be32(tp, offset, &v))
			return;

		offset += sizeof(v);

		if (vlen > TG3_VER_SIZE - sizeof(v)) {
			memcpy(&tp->fw_ver[vlen], &v, TG3_VER_SIZE - vlen);
			break;
		}
		memcpy(&tp->fw_ver[vlen], &v, sizeof(v));
		vlen += sizeof(v);
	}
}

PRIVATE void tg3_read_dash_ver(tg3_t * tp)
{
	int vlen;
	u32_t apedata;

	if (!(tp->tg3_flags3 & TG3_FLG3_ENABLE_APE) ||
	    !(tp->tg3_flags & TG3_FLAG_ENABLE_ASF))
		return;

	apedata = tg3_ape_read32(tp, TG3_APE_SEG_SIG);
	if (apedata != APE_SEG_SIG_MAGIC)
		return;

	apedata = tg3_ape_read32(tp, TG3_APE_FW_STATUS);
	if (!(apedata & APE_FW_STATUS_READY))
		return;

	apedata = tg3_ape_read32(tp, TG3_APE_FW_VERSION);

	vlen = strlen(tp->fw_ver);

	snprintf(&tp->fw_ver[vlen], TG3_VER_SIZE - vlen, " DASH v%d.%d.%d.%d",
		 (apedata & APE_FW_VERSION_MAJMSK) >> APE_FW_VERSION_MAJSFT,
		 (apedata & APE_FW_VERSION_MINMSK) >> APE_FW_VERSION_MINSFT,
		 (apedata & APE_FW_VERSION_REVMSK) >> APE_FW_VERSION_REVSFT,
		 (apedata & APE_FW_VERSION_BLDMSK));
}

PRIVATE void tg3_read_fw_ver(tg3_t * tp)
{
	u32_t val;

	if (tp->tg3_flags3 & TG3_FLG3_NO_NVRAM) {
		tp->fw_ver[0] = 's';
		tp->fw_ver[1] = 'b';
		tp->fw_ver[2] = '\0';

		return;
	}
	if (tg3_nvram_read(tp, 0, &val))
		return;

	if (val == TG3_EEPROM_MAGIC)
		tg3_read_bc_ver(tp);
	else if ((val & TG3_EEPROM_MAGIC_FW_MSK) == TG3_EEPROM_MAGIC_FW)
		tg3_read_sb_ver(tp, val);
	else if ((val & TG3_EEPROM_MAGIC_HW_MSK) == TG3_EEPROM_MAGIC_HW)
		tg3_read_hwsb_ver(tp);
	else
		return;

	if (!(tp->tg3_flags & TG3_FLAG_ENABLE_ASF) ||
	    (tp->tg3_flags3 & TG3_FLG3_ENABLE_APE))
		return;

	tg3_read_mgmtfw_ver(tp);

	tp->fw_ver[TG3_VER_SIZE - 1] = 0;
}


PRIVATE int tg3_get_invariants(tg3_t * tp)
{
	u32_t misc_ctrl_reg;
	u32_t pci_state_reg, grc_misc_cfg;
	u32_t val;
	u16_t pci_cmd;
	int err;

	/* Force memory write invalidate off.  If we leave it on, then on
	 * 5700_BX chips we have to enable a workaround. The workaround is to
	 * set the TG3PCI_DMA_RW_CTRL boundary to match the cacheline size. The
	 * Broadcom driver have this workaround but turns MWI off all the times
	 * so never uses it.  This seems to suggest that the workaround is
	 * insufficient. */
	pci_cmd = pci_attr_r16(tp->devind, PCI_CR);
#define PCI_COMMAND_INVALIDATE 0x10
	pci_cmd &= ~PCI_COMMAND_INVALIDATE;
	pci_attr_w16(tp->devind, PCI_CR, pci_cmd);



	/* It is absolutely critical that TG3PCI_MISC_HOST_CTRL has the
	 * register indirect write enable bit set before we try to access any
	 * of the MMIO registers.  It is also critical that the PCI-X hw
	 * workaround situation is decided before that as well. */
	misc_ctrl_reg = pci_attr_r32(tp->devind, TG3PCI_MISC_HOST_CTRL);
	tp->pci_chip_rev_id = (misc_ctrl_reg >>
			       MISC_HOST_CTRL_CHIPREV_SHIFT);

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_USE_PROD_ID_REG) {

		tp->pci_chip_rev_id = pci_attr_r32(tp->devind,
						   TG3PCI_PRODID_ASICREV);

	}
	/* Wrong chip ID in 5752 A0. This code can be removed later as A0 is
	 * not in production. */
	if (tp->pci_chip_rev_id == CHIPREV_ID_5752_A0_HW)
		tp->pci_chip_rev_id = CHIPREV_ID_5752_A0;

	/* If we have 5702/03 A1 or A2 on certain ICH chipsets, we need to
	 * disable memory and use config. cycles only to access all registers.
	 * The 5702/03 chips can mistakenly decode the special cycles from the
	 * ICH chipsets as memory write cycles, causing corruption of register
	 * and memory space. Only certain ICH bridges will drive special cycles
	 * with non-zero data during the address phase which can fall within
	 * the 5703's address range. This is not an ICH bug as the PCI spec
	 * allows non-zero address during special cycles. However, only these
	 * ICH bridges are known to drive non-zero addresses during special
	 * cycles.
	 * 
	 * Since special cycles do not cross PCI bridges, we only enable this
	 * workaround if the 5703 is on the secondary bus of these ICH bridges. */


	/* On Minix, We assume it's going to be a problem */
	if ((tp->pci_chip_rev_id == CHIPREV_ID_5703_A1) ||
	    (tp->pci_chip_rev_id == CHIPREV_ID_5703_A2)) {
		printf("The chipset may have problems, enabling workround\n");
		tp->tg3_flags2 |= TG3_FLG2_ICH_WORKAROUND;
	}
	/* Initialize misc host control in PCI block. */
	tp->misc_host_ctrl |= (misc_ctrl_reg &
			       MISC_HOST_CTRL_CHIPREV);

	pci_attr_w32(tp->devind, TG3PCI_MISC_HOST_CTRL, tp->misc_host_ctrl);


	/* Intentionally exclude ASIC_REV_5906 */
	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5755 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5787 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5784 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5761 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5785 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_57780)
		tp->tg3_flags3 |= TG3_FLG3_5755_PLUS;

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5750 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5752 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906 ||
	    (tp->tg3_flags3 & TG3_FLG3_5755_PLUS) ||
	    (tp->tg3_flags2 & TG3_FLG2_5780_CLASS))
		tp->tg3_flags2 |= TG3_FLG2_5750_PLUS;

	if ((GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5705) ||
	    (tp->tg3_flags2 & TG3_FLG2_5750_PLUS))
		tp->tg3_flags2 |= TG3_FLG2_5705_PLUS;

	/* 5700 B0 chips do not support checksumming correctly due to hardware
	 * bugs. */
	if (tp->pci_chip_rev_id == CHIPREV_ID_5700_B0)
		tp->tg3_flags |= TG3_FLAG_BROKEN_CHECKSUMS;
	else {
		tp->tg3_flags |= TG3_FLAG_RX_CHECKSUMS;
	}

	if (tp->tg3_flags2 & TG3_FLG2_5750_PLUS) {
		tp->tg3_flags |= TG3_FLAG_SUPPORT_MSI;
		if (GET_CHIP_REV(tp->pci_chip_rev_id) == CHIPREV_5750_AX ||
		    GET_CHIP_REV(tp->pci_chip_rev_id) == CHIPREV_5750_BX ||
		    (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5714 &&
		     tp->pci_chip_rev_id <= CHIPREV_ID_5714_A2	/* && */
		      /* tp->pdev_peer == tp->pdev */ ))
			tp->tg3_flags &= ~TG3_FLAG_SUPPORT_MSI;

		if ((tp->tg3_flags3 & TG3_FLG3_5755_PLUS) ||
		    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) {
			tp->tg3_flags2 |= TG3_FLG2_HW_TSO_2;
			tp->tg3_flags2 |= TG3_FLG2_1SHOT_MSI;
		} else {
			tp->tg3_flags2 |= TG3_FLG2_HW_TSO_1 | TG3_FLG2_TSO_BUG;
			if (GET_ASIC_REV(tp->pci_chip_rev_id) ==
			    ASIC_REV_5750 &&
			    tp->pci_chip_rev_id >= CHIPREV_ID_5750_C2)
				tp->tg3_flags2 &= ~TG3_FLG2_TSO_BUG;
		}
	}
	if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS) ||
	    (tp->tg3_flags2 & TG3_FLG2_5780_CLASS))
		tp->tg3_flags2 |= TG3_FLG2_JUMBO_CAPABLE;

	pci_state_reg = pci_attr_r32(tp->devind, TG3PCI_PCISTATE);

	pci_find_cap(tp->devind, PCI_CAP_ID_EXP, &(tp->cap.pcie_cap));
	if (tp->cap.pcie_cap != 0) {
		u16_t lnkctl;

		tp->tg3_flags2 |= TG3_FLG2_PCI_EXPRESS;

		pcie_set_readrq(tp->devind, 4096);

		lnkctl = pci_attr_r16(tp->devind, tp->cap.pcie_cap + PCI_EXP_LNKCTL);
		if (lnkctl & PCI_EXP_LNKCTL_CLKREQ_EN) {
			if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906)
				tp->tg3_flags2 &= ~TG3_FLG2_HW_TSO_2;
			if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5784 ||
			 GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5761 ||
			    tp->pci_chip_rev_id == CHIPREV_ID_57780_A0 ||
			    tp->pci_chip_rev_id == CHIPREV_ID_57780_A1)
				tp->tg3_flags3 |= TG3_FLG3_CLKREQ_BUG;
		}
	} else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5785) {
		tp->tg3_flags2 |= TG3_FLG2_PCI_EXPRESS;
	} else if (!(tp->tg3_flags2 & TG3_FLG2_5705_PLUS) ||
		   (tp->tg3_flags2 & TG3_FLG2_5780_CLASS)) {
		pci_find_cap(tp->devind, PCI_CAP_ID_PCIX, &(tp->cap.pcix_cap));
		if (!tp->cap.pcix_cap) {
			printf("Cannot find PCI-X capability, aborting.\n");
			return -EIO;
		}
		if (!(pci_state_reg & PCISTATE_CONV_PCI_MODE))
			tp->tg3_flags |= TG3_FLAG_PCIX_MODE;
	}

	/* Minix port does not currently handle this */
	/* If we have an AMD 762 or VIA K8T800 chipset, write reordering to the
	 * mailbox registers done by the host controller can cause major
	 * troubles.  We read back from every mailbox register write to force
	 * the writes to be posted to the chip in order. */
/*	if (pci_dev_present(write_reorder_chipsets) &&*/
/*	    !(tp->tg3_flags2 & TG3_FLG2_PCI_EXPRESS))*/
/*		tp->tg3_flags |= TG3_FLAG_MBOX_WRITE_REORDER;*/

	tp->pci_cacheline_sz = pci_attr_r8(tp->devind, PCI_CACHE_LINE_SIZE);

	tp->pci_lat_timer = pci_attr_r8(tp->devind, PCI_LATENCY_TIMER);
	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5703 &&
	    tp->pci_lat_timer < 64) {
		tp->pci_lat_timer = 64;
		pci_attr_w8(tp->devind, PCI_LATENCY_TIMER, tp->pci_lat_timer);
	}

	if (GET_CHIP_REV(tp->pci_chip_rev_id) == CHIPREV_5700_BX) {
		/* 5700 BX chips need to have their TX producer index mailboxes
		 * written twice to workaround a bug. */
		tp->tg3_flags |= TG3_FLAG_TXD_MBOX_HWBUG;

		/* If we are in PCI-X mode, enable register write workaround.
		 * 
		 * The workaround is to use indirect register accesses for all
		 * chip writes not to mailbox registers. */
		if (tp->tg3_flags & TG3_FLAG_PCIX_MODE) {
			u32_t pm_reg;

			tp->tg3_flags |= TG3_FLAG_PCIX_TARGET_HWBUG;

		/* The chip can have it's power management PCI config space
		 * registers clobbered due to this bug. So explicitly force the
		 * chip into D0 here. */
			pm_reg = pci_attr_r32(tp->devind,
					      tp->pm_cap + PCI_PM_CTRL);
			pm_reg &= ~PCI_PM_CTRL_STATE_MASK;
			pm_reg |= PCI_PM_CTRL_PME_ENABLE | 0; /* D0 */
			pci_attr_w32(tp->devind,
					tp->pm_cap + PCI_PM_CTRL,
					pm_reg);

		/* Also, force SERR#/PERR# in PCI command. */
			pci_cmd = pci_attr_r16(tp->devind, PCI_CR);
			pci_cmd |= PCI_COMMAND_PARITY | PCI_COMMAND_SERR;
			pci_attr_w16(tp->devind, PCI_CR, pci_cmd);
		}
	}
	if ((pci_state_reg & PCISTATE_BUS_SPEED_HIGH) != 0)
		tp->tg3_flags |= TG3_FLAG_PCI_HIGH_SPEED;
	if ((pci_state_reg & PCISTATE_BUS_32BIT) != 0)
		tp->tg3_flags |= TG3_FLAG_PCI_32BIT;

	/* Chip-specific fixup from Broadcom driver */
	if ((tp->pci_chip_rev_id == CHIPREV_ID_5704_A0) &&
	    (!(pci_state_reg & PCISTATE_RETRY_SAME_DMA))) {
		pci_state_reg |= PCISTATE_RETRY_SAME_DMA;
		pci_attr_w32(tp->devind, TG3PCI_PCISTATE, pci_state_reg);
	}
	/* Default fast path register access methods */
	tp->read32 = tg3_read32;
	tp->write32 = tg3_write32;
	tp->read32_mbox = tg3_read32;
	tp->write32_mbox = tg3_write32;
	tp->write32_tx_mbox = tg3_write32;
	tp->write32_rx_mbox = tg3_write32;

	/* Various workaround register access methods */
	if (tp->tg3_flags & TG3_FLAG_PCIX_TARGET_HWBUG)
		tp->write32 = tg3_write_indirect_reg32;
	else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5701 ||
		 ((tp->tg3_flags2 & TG3_FLG2_PCI_EXPRESS) &&
		  tp->pci_chip_rev_id == CHIPREV_ID_5750_A0)) {
		/* Back to back register writes can cause problems on these
		 * chips, the workaround is to read back all reg writes except
		 * those to mailbox regs.
		 * 
		 * See tg3_write_indirect_reg32(). */
		tp->write32 = tg3_write_flush_reg32;
	}
	if ((tp->tg3_flags & TG3_FLAG_TXD_MBOX_HWBUG) ||
	    (tp->tg3_flags & TG3_FLAG_MBOX_WRITE_REORDER)) {
		tp->write32_tx_mbox = tg3_write32_tx_mbox;
		if (tp->tg3_flags & TG3_FLAG_MBOX_WRITE_REORDER)
			tp->write32_rx_mbox = tg3_write_flush_reg32;
	}
	if (tp->tg3_flags2 & TG3_FLG2_ICH_WORKAROUND) {
		tp->read32 = tg3_read_indirect_reg32;
		tp->write32 = tg3_write_indirect_reg32;
		tp->read32_mbox = tg3_read_indirect_mbox;
		tp->write32_mbox = tg3_write_indirect_mbox;
		tp->write32_tx_mbox = tg3_write_indirect_mbox;
		tp->write32_rx_mbox = tg3_write_indirect_mbox;


		vm_unmap_phys(SELF, tp->regs, 0xFFFF);
		tp->regs = NULL;

		pci_cmd = pci_attr_r16(tp->devind, PCI_CR); 
		pci_cmd &= ~PCI_CR_MEM_EN;
		pci_attr_w16(tp->devind, PCI_CR, pci_cmd);
	}
	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) {
		tp->read32_mbox = tg3_read32_mbox_5906;
		tp->write32_mbox = tg3_write32_mbox_5906;
		tp->write32_tx_mbox = tg3_write32_mbox_5906;
		tp->write32_rx_mbox = tg3_write32_mbox_5906;
	}
	if (tp->write32 == tg3_write_indirect_reg32 ||
	    ((tp->tg3_flags & TG3_FLAG_PCIX_MODE) &&
	     (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5700 ||
	      GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5701)))
		tp->tg3_flags |= TG3_FLAG_SRAM_USE_CONFIG;

	/* Get eeprom hw config before calling tg3_set_power_state(). In
	 * particular, the TG3_FLG2_IS_NIC flag must be determined before
	 * calling tg3_set_power_state() so that we know whether or not to
	 * switch out of Vaux power. When the flag is set, it means that GPIO1
	 * is used for eeprom write protect and also implies that it is a LOM
	 * where GPIOs are not used to switch power. */


	tg3_get_eeprom_hw_cfg(tp);



	if (tp->tg3_flags3 & TG3_FLG3_ENABLE_APE) {
		/* Allow reads and writes to the APE register and memory space. */
		pci_state_reg |= PCISTATE_ALLOW_APE_CTLSPC_WR |
				 PCISTATE_ALLOW_APE_SHMEM_WR;
		pci_attr_w32(tp->devind, TG3PCI_PCISTATE, pci_state_reg);		
	}

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5784 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5761 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5785 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_57780)
		tp->tg3_flags |= TG3_FLAG_CPMU_PRESENT;

	/* Set up tp->grc_local_ctrl before calling tg3_set_power_state().
	 * GPIO1 driven high will bring 5700's external PHY out of reset. It is
	 * also used as eeprom write protect on LOMs. */
	tp->grc_local_ctrl = GRC_LCLCTRL_INT_ON_ATTN | GRC_LCLCTRL_AUTO_SEEPROM;
	if ((GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5700) ||
	    (tp->tg3_flags & TG3_FLAG_EEPROM_WRITE_PROT))
		tp->grc_local_ctrl |= (GRC_LCLCTRL_GPIO_OE1 |
				       GRC_LCLCTRL_GPIO_OUTPUT1);
	/* Unused GPIO3 must be driven as output on 5752 because there are no
	 * pull-up resistors on unused GPIO pins. */
	else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5752)
		tp->grc_local_ctrl |= GRC_LCLCTRL_GPIO_OE3;

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5755 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_57780)
		tp->grc_local_ctrl |= GRC_LCLCTRL_GPIO_UART_SEL;

#define PCI_DEVICE_ID_TIGON3_5761	0x1681

	if (tp->device == PCI_DEVICE_ID_TIGON3_5761 ||
	    tp->device == TG3PCI_DEVICE_TIGON3_5761S) {
		/* Turn off the debug UART. */
		tp->grc_local_ctrl |= GRC_LCLCTRL_GPIO_UART_SEL;
		if (tp->tg3_flags2 & TG3_FLG2_IS_NIC)
			/* Keep VMain power. */
			tp->grc_local_ctrl |= GRC_LCLCTRL_GPIO_OE0 |
				GRC_LCLCTRL_GPIO_OUTPUT0;
	}
	/* Force the chip into D0. */
	err = tg3_set_power_state(tp, PCI_D0);
	if (err) {
		printf("(%s) transition to D0 failed\n",
		       "device_name(tp->pdev)");
		return err;
	}

	/* When Minix gets Jumbo support we can enable this */
/*	if (tp->mtu > ETH_DATA_LEN &&*/
/*	    !(tp->tg3_flags2 & TG3_FLG2_5780_CLASS))*/
/*		tp->tg3_flags |= TG3_FLAG_JUMBO_RING_ENABLE;*/

	/* Determine WakeOnLan speed to use. */
	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5700 ||
	    tp->pci_chip_rev_id == CHIPREV_ID_5701_A0 ||
	    tp->pci_chip_rev_id == CHIPREV_ID_5701_B0 ||
	    tp->pci_chip_rev_id == CHIPREV_ID_5701_B2) {
		tp->tg3_flags &= ~(TG3_FLAG_WOL_SPEED_100MB);
	} else {
		tp->tg3_flags |= TG3_FLAG_WOL_SPEED_100MB;
	}

	/* A few boards don't want Ethernet@WireSpeed phy feature */
	if ((GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5700) ||
	    ((GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5705) &&
	     (tp->pci_chip_rev_id != CHIPREV_ID_5705_A0) &&
	     (tp->pci_chip_rev_id != CHIPREV_ID_5705_A1)) ||
	    (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) ||
	    (tp->tg3_flags2 & TG3_FLG2_ANY_SERDES))
		tp->tg3_flags2 |= TG3_FLG2_NO_ETH_WIRE_SPEED;

	if (GET_CHIP_REV(tp->pci_chip_rev_id) == CHIPREV_5703_AX ||
	    GET_CHIP_REV(tp->pci_chip_rev_id) == CHIPREV_5704_AX)
		tp->tg3_flags2 |= TG3_FLG2_PHY_ADC_BUG;
	if (tp->pci_chip_rev_id == CHIPREV_ID_5704_A0)
		tp->tg3_flags2 |= TG3_FLG2_PHY_5704_A0_BUG;

#define PCI_DEVICE_ID_TIGON3_5756	0x1674
#define PCI_DEVICE_ID_TIGON3_5722	0x165a
#define PCI_DEVICE_ID_TIGON3_5755M	0x1673

	if ((tp->tg3_flags2 & TG3_FLG2_5705_PLUS) &&
	    GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5906 &&
	    GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5785 &&
	    GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_57780) {
		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5755 ||
		    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5787 ||
		    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5784 ||
		    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5761) {
			if (tp->device != PCI_DEVICE_ID_TIGON3_5756 &&
			    tp->device != PCI_DEVICE_ID_TIGON3_5722)
				tp->tg3_flags2 |= TG3_FLG2_PHY_JITTER_BUG;
			if (tp->device == PCI_DEVICE_ID_TIGON3_5755M)
				tp->tg3_flags2 |= TG3_FLG2_PHY_ADJUST_TRIM;
		} else
			tp->tg3_flags2 |= TG3_FLG2_PHY_BER_BUG;
	}
	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5784 &&
	    GET_CHIP_REV(tp->pci_chip_rev_id) != CHIPREV_5784_AX) {
		tp->phy_otp = tg3_read_otp_phycfg(tp);
		if (tp->phy_otp == 0)
			tp->phy_otp = TG3_OTP_DEFAULT;
	}
	if (tp->tg3_flags & TG3_FLAG_CPMU_PRESENT)
		tp->mi_mode = MAC_MI_MODE_500KHZ_CONST;
	else
		tp->mi_mode = MAC_MI_MODE_BASE;

	tp->coalesce_mode = 0;
	if (GET_CHIP_REV(tp->pci_chip_rev_id) != CHIPREV_5700_AX &&
	    GET_CHIP_REV(tp->pci_chip_rev_id) != CHIPREV_5700_BX)
		tp->coalesce_mode |= HOSTCC_MODE_32BYTE;

	err = tg3_mdio_init(tp);
	if (err)
		return err;

	/* Initialize data/descriptor byte/word swapping. */
	val = tr32(GRC_MODE);
	val &= GRC_MODE_HOST_STACKUP;
	tw32(GRC_MODE, val | tp->grc_mode);

	tg3_switch_clocks(tp);

	/* Clear this out for sanity. */
	tw32(TG3PCI_MEM_WIN_BASE_ADDR, 0);

	pci_state_reg = pci_attr_r32(tp->devind, TG3PCI_PCISTATE);


	if ((pci_state_reg & PCISTATE_CONV_PCI_MODE) == 0 &&
	    (tp->tg3_flags & TG3_FLAG_PCIX_TARGET_HWBUG) == 0) {
		u32_t chiprevid = GET_CHIP_REV_ID(tp->misc_host_ctrl);

		if (chiprevid == CHIPREV_ID_5701_A0 ||
		    chiprevid == CHIPREV_ID_5701_B0 ||
		    chiprevid == CHIPREV_ID_5701_B2 ||
		    chiprevid == CHIPREV_ID_5701_B5) {
			u8_t *sram_base;

			/* Write some dummy words into the SRAM status block
			 * area, see if it reads back correctly.  If the return
			 * value is bad, force enable the PCIX workaround. */
			sram_base = tp->regs + NIC_SRAM_WIN_BASE + NIC_SRAM_STATS_BLK;

			writel(0x00000000, sram_base);
			writel(0x00000000, sram_base + 4);
			writel(0xffffffff, sram_base + 4);
			if (readl(sram_base) != 0x00000000)
				tp->tg3_flags |= TG3_FLAG_PCIX_TARGET_HWBUG;
		}
	}
	micro_delay(50);
	tg3_nvram_init(tp);

	grc_misc_cfg = tr32(GRC_MISC_CFG);
	grc_misc_cfg &= GRC_MISC_CFG_BOARD_ID_MASK;

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5705 &&
	    (grc_misc_cfg == GRC_MISC_CFG_BOARD_ID_5788 ||
	     grc_misc_cfg == GRC_MISC_CFG_BOARD_ID_5788M))
		tp->tg3_flags2 |= TG3_FLG2_IS_5788;

	if (!(tp->tg3_flags2 & TG3_FLG2_IS_5788) &&
	    (GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5700))
		tp->tg3_flags |= TG3_FLAG_TAGGED_STATUS;
	if (tp->tg3_flags & TG3_FLAG_TAGGED_STATUS) {
		tp->coalesce_mode |= (HOSTCC_MODE_CLRTICK_RXBD |
				      HOSTCC_MODE_CLRTICK_TXBD);

		tp->misc_host_ctrl |= MISC_HOST_CTRL_TAGGED_STATUS;
		pci_attr_w32(tp->devind, TG3PCI_MISC_HOST_CTRL,
			     tp->misc_host_ctrl);
	}
	/* Preserve the APE MAC_MODE bits */
	if (tp->tg3_flags3 & TG3_FLG3_ENABLE_APE)
		tp->mac_mode = tr32(MAC_MODE) |
			MAC_MODE_APE_TX_EN | MAC_MODE_APE_RX_EN;
	else
		tp->mac_mode = TG3_DEF_MAC_MODE;

	/* these are limited to 10/100 only */
	if ((GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5703 &&
	     (grc_misc_cfg == 0x8000 || grc_misc_cfg == 0x4000)) ||
	    (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5705 &&
	     tp->vendor == PCI_VENDOR_ID_BROADCOM &&
	     (tp->device == PCI_DEVICE_ID_TIGON3_5901 ||
	      tp->device == PCI_DEVICE_ID_TIGON3_5901_2 ||
	      tp->device == PCI_DEVICE_ID_TIGON3_5705F)) ||
	    (tp->vendor == PCI_VENDOR_ID_BROADCOM &&
	     (tp->device == PCI_DEVICE_ID_TIGON3_5751F ||
	      tp->device == PCI_DEVICE_ID_TIGON3_5753F ||
	      tp->device == PCI_DEVICE_ID_TIGON3_5787F)) ||
	    tp->device == TG3PCI_DEVICE_TIGON3_57790 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906)
		tp->tg3_flags |= TG3_FLAG_10_100_ONLY;

	err = tg3_phy_probe(tp);
	if (err) {
		printf("(%s) phy probe failed, err %d\n",
		       "device_name(tp->pdev)", err);
		/* ... but do not return immediately ... */
		tg3_mdio_fini(tp);
	}
	tg3_read_partno(tp);
	tg3_read_fw_ver(tp);

	if (tp->tg3_flags2 & TG3_FLG2_PHY_SERDES) {
		tp->tg3_flags &= ~TG3_FLAG_USE_MI_INTERRUPT;
	} else {
		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5700)
			tp->tg3_flags |= TG3_FLAG_USE_MI_INTERRUPT;
		else
			tp->tg3_flags &= ~TG3_FLAG_USE_MI_INTERRUPT;
	}

	/* 5700 {AX,BX} chips have a broken status block link change bit
	 * implementation, so we must use the status register in those cases. */
	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5700)
		tp->tg3_flags |= TG3_FLAG_USE_LINKCHG_REG;
	else
		tp->tg3_flags &= ~TG3_FLAG_USE_LINKCHG_REG;

	/* The led_ctrl is set during tg3_phy_probe, here we might have to
	 * force the link status polling mechanism based upon subsystem IDs. */
	if (tp->subsystem_vendor == PCI_VENDOR_ID_DELL &&
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5701 &&
	    !(tp->tg3_flags2 & TG3_FLG2_PHY_SERDES)) {
		tp->tg3_flags |= (TG3_FLAG_USE_MI_INTERRUPT |
				  TG3_FLAG_USE_LINKCHG_REG);
	}
	/* For all SERDES we poll the MAC status register. */
	if (tp->tg3_flags2 & TG3_FLG2_PHY_SERDES)
		tp->tg3_flags |= TG3_FLAG_POLL_SERDES;
	else
		tp->tg3_flags &= ~TG3_FLAG_POLL_SERDES;

	tp->rx_offset = 0;

	tp->rx_std_max_post = TG3_RX_RING_SIZE;

	/* Increment the rx prod index on the rx std ring by at most 8 for
	 * these chips to workaround hw errata. */
	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5750 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5752 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5755)
		tp->rx_std_max_post = 8;

	if (tp->tg3_flags & TG3_FLAG_ASPM_WORKAROUND)
		tp->pwrmgmt_thresh = tr32(PCIE_PWR_MGMT_THRESH) &
			PCIE_PWR_MGMT_L1_THRESH_MSK;

	return err;
}

PRIVATE int tg3_get_device_address(tg3_t * tp)
{
	u32_t hi, lo, mac_offset;
	int addr_ok = 0;

	mac_offset = 0x7c;
	if ((GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5704) ||
	    (tp->tg3_flags2 & TG3_FLG2_5780_CLASS)) {
		if (tr32(TG3PCI_DUAL_MAC_CTRL) & DUAL_MAC_CTRL_ID)
			mac_offset = 0xcc;
		if (tg3_nvram_lock(tp))
			tw32_f(NVRAM_CMD, NVRAM_CMD_RESET);
		else
			tg3_nvram_unlock(tp);
	}
	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906)
		mac_offset = 0x10;

	/* First try to get it from MAC address mailbox. */
	tg3_read_mem(tp, NIC_SRAM_MAC_ADDR_HIGH_MBOX, &hi);
	if ((hi >> 16) == 0x484b) {
		tp->mac_address.ea_addr[0] = (hi >> 8) & 0xff;
		tp->mac_address.ea_addr[1] = (hi >> 0) & 0xff;

		tg3_read_mem(tp, NIC_SRAM_MAC_ADDR_LOW_MBOX, &lo);

		tp->mac_address.ea_addr[2] = (lo >> 24) & 0xff;
		tp->mac_address.ea_addr[3] = (lo >> 16) & 0xff;
		tp->mac_address.ea_addr[4] = (lo >> 8) & 0xff;
		tp->mac_address.ea_addr[5] = (lo >> 0) & 0xff;

		/* Some old bootcode may report a 0 MAC address in SRAM */
		addr_ok = is_valid_ether_addr(tp->mac_address.ea_addr);
	}
	if (!addr_ok) {
		/* Next, try NVRAM. */
		if (!(tp->tg3_flags3 & TG3_FLG3_NO_NVRAM) &&
		    !tg3_nvram_read_be32(tp, mac_offset + 0, &hi) &&
		    !tg3_nvram_read_be32(tp, mac_offset + 4, &lo)) {
			memcpy(&tp->mac_address.ea_addr[0], ((char *) &hi) + 2, 2);
			memcpy(&tp->mac_address.ea_addr[2], (char *) &lo, sizeof(lo));
		}
		/* Finally just fetch it out of the MAC control regs. */
		else {
			hi = tr32(MAC_ADDR_0_HIGH);
			lo = tr32(MAC_ADDR_0_LOW);

			tp->mac_address.ea_addr[5] = lo & 0xff;
			tp->mac_address.ea_addr[4] = (lo >> 8) & 0xff;
			tp->mac_address.ea_addr[3] = (lo >> 16) & 0xff;
			tp->mac_address.ea_addr[2] = (lo >> 24) & 0xff;
			tp->mac_address.ea_addr[1] = hi & 0xff;
			tp->mac_address.ea_addr[0] = (hi >> 8) & 0xff;
		}
	}
	return 0;
}


PRIVATE int tg3_do_test_dma(tg3_t * tp, u32_t * buf, vir_bytes buf_dma,
			int size, int to_device)
{
	struct tg3_internal_buffer_desc test_desc;
	u32_t sram_dma_descs;
	int i, ret;

	sram_dma_descs = NIC_SRAM_DMA_DESC_POOL_BASE;

	tw32(FTQ_RCVBD_COMP_FIFO_ENQDEQ, 0);
	tw32(FTQ_RCVDATA_COMP_FIFO_ENQDEQ, 0);
	tw32(RDMAC_STATUS, 0);
	tw32(WDMAC_STATUS, 0);

	tw32(BUFMGR_MODE, 0);
	tw32(FTQ_RESET, 0);

	test_desc.addr_hi = 0;	/* Minix is 32bit so top 32bits are 0 */
	test_desc.addr_lo = buf_dma;
	test_desc.nic_mbuf = 0x00002100;
	test_desc.len = size;


	/* HP ZX1 was seeing test failures for 5701 cards running at 33Mhz the
	 * *second* time the tg3 driver was getting loaded after an initial
	 * scan.
	 * 
	 * Broadcom tells me: ...the DMA engine is connected to the GRC block and
	 * a DMA reset may affect the GRC block in some unpredictable way...
	 * The behavior of resets to individual blocks has not been tested.
	 * 
	 * Broadcom noted the GRC reset will also reset all sub-components. */
	if (to_device) {
		test_desc.cqid_sqid = (13 << 8) | 2;

		tw32_f(RDMAC_MODE, RDMAC_MODE_ENABLE);
		/* V micro_delay(40); */
		micro_delay(40);
	} else {
		test_desc.cqid_sqid = (16 << 8) | 7;

		tw32_f(WDMAC_MODE, WDMAC_MODE_ENABLE);
		/* V micro_delay(40); */
		micro_delay(40);
	}
	test_desc.flags = 0x00000005;

	for (i = 0; i < (sizeof(test_desc) / sizeof(u32_t)); i++) {
		u32_t val;

		val = *(((u32_t *) & test_desc) + i);
		pci_attr_w32(tp->devind, TG3PCI_MEM_WIN_BASE_ADDR,
			     sram_dma_descs + (i * sizeof(u32_t)));
		pci_attr_w32(tp->devind, TG3PCI_MEM_WIN_DATA, val);


	}
	pci_attr_w32(tp->devind, TG3PCI_MEM_WIN_BASE_ADDR, 0);

	if (to_device) {
		tw32(FTQ_DMA_HIGH_READ_FIFO_ENQDEQ, sram_dma_descs);
	} else {
		tw32(FTQ_DMA_HIGH_WRITE_FIFO_ENQDEQ, sram_dma_descs);
	}

	ret = -ENODEV;
	for (i = 0; i < 40; i++) {
		u32_t val;

		if (to_device)
			val = tr32(FTQ_RCVBD_COMP_FIFO_ENQDEQ);
		else
			val = tr32(FTQ_RCVDATA_COMP_FIFO_ENQDEQ);
		if ((val & 0xffff) == sram_dma_descs) {
			ret = 0;
			break;
		}
		micro_delay(100);
	}

	return ret;
}



PRIVATE int tg3_test_dma(tg3_t * tp)
{
	vir_bytes buf_dma;
	u32_t *buf, saved_dma_rwctrl;
	int ret;

#define TEST_BUFFER_SIZE	0x2000
	buf = alloc_contig(TEST_BUFFER_SIZE, 0, (phys_bytes *) & buf_dma);

	if (!buf) {
		ret = -ENOMEM;
		goto out_nofree;
	}
	tp->dma_rwctrl = ((0x7 << DMA_RWCTRL_PCI_WRITE_CMD_SHIFT) |
			  (0x6 << DMA_RWCTRL_PCI_READ_CMD_SHIFT));


	if (tp->tg3_flags2 & TG3_FLG2_PCI_EXPRESS) {
		/* DMA read watermark not used on PCIE */
		tp->dma_rwctrl |= 0x00180000;
	} else if (!(tp->tg3_flags & TG3_FLAG_PCIX_MODE)) {
		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5705 ||
		    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5750)
			tp->dma_rwctrl |= 0x003f0000;
		else
			tp->dma_rwctrl |= 0x003f000f;
	} else {
		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5703 ||
		    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5704) {
			u32_t ccval = (tr32(TG3PCI_CLOCK_CTRL) & 0x1f);
			u32_t read_water = 0x7;

			/* If the 5704 is behind the EPB bridge, we can do the
			 * less restrictive ONE_DMA workaround for better
			 * performance. */
			if ((tp->tg3_flags & TG3_FLAG_40BIT_DMA_BUG) &&
			    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5704)
				tp->dma_rwctrl |= 0x8000;
			else if (ccval == 0x6 || ccval == 0x7)
				tp->dma_rwctrl |= DMA_RWCTRL_ONE_DMA;

			if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5703)
				read_water = 4;
			/* Set bit 23 to enable PCIX hw bug fix */
			tp->dma_rwctrl |=
				(read_water << DMA_RWCTRL_READ_WATER_SHIFT) |
				(0x3 << DMA_RWCTRL_WRITE_WATER_SHIFT) |
				(1 << 23);
		} else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5780) {
			/* 5780 always in PCIX mode */
			tp->dma_rwctrl |= 0x00144000;
		} else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5714) {
			/* 5714 always in PCIX mode */
			tp->dma_rwctrl |= 0x00148000;
		} else {
			tp->dma_rwctrl |= 0x001b000f;
		}
	}

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5703 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5704)
		tp->dma_rwctrl &= 0xfffffff0;

	if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5700 ||
	    GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5701) {
		/* Remove this if it causes problems for some boards. */
		tp->dma_rwctrl |= DMA_RWCTRL_USE_MEM_READ_MULT;

		/* On 5700/5701 chips, we need to set this bit. Otherwise the
		 * chip will issue cacheline transactions to streamable DMA
		 * memory with not all the byte enables turned on.  This is an
		 * error on several RISC PCI controllers, in particular
		 * sparc64.
		 * 
		 * On 5703/5704 chips, this bit has been reassigned a different
		 * meaning.  In particular, it is used on those chips to enable
		 * a PCI-X workaround. */
		tp->dma_rwctrl |= DMA_RWCTRL_ASSERT_ALL_BE;
	}
	tw32(TG3PCI_DMA_RW_CTRL, tp->dma_rwctrl);

	ret = 0;
	if (GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5700 &&
	    GET_ASIC_REV(tp->pci_chip_rev_id) != ASIC_REV_5701)
		goto out;

	/* It is best to perform DMA test with maximum write burst size to
	 * expose the 5700/5701 write DMA bug. */
	saved_dma_rwctrl = tp->dma_rwctrl;
	tp->dma_rwctrl &= ~DMA_RWCTRL_WRITE_BNDRY_MASK;
	tw32(TG3PCI_DMA_RW_CTRL, tp->dma_rwctrl);

	while (1) {
		u32_t *p = buf, i;

		for (i = 0; i < TEST_BUFFER_SIZE / sizeof(u32_t); i++)
			p[i] = i;

		/* Send the buffer to the chip. */
		ret = tg3_do_test_dma(tp, buf, buf_dma, TEST_BUFFER_SIZE, 1);
		if (ret) {
			printf("tg3_test_dma() Write the buffer failed %d\n", ret);
			break;
		}
		/* Now read it back. */
		ret = tg3_do_test_dma(tp, buf, buf_dma, TEST_BUFFER_SIZE, 0);
		if (ret) {
			printf("tg3_test_dma() Read the buffer failed %d\n", ret);

			break;
		}
		/* Verify it. */
		for (i = 0; i < TEST_BUFFER_SIZE / sizeof(u32_t); i++) {
			if (p[i] == i)
				continue;

			if ((tp->dma_rwctrl & DMA_RWCTRL_WRITE_BNDRY_MASK) !=
			    DMA_RWCTRL_WRITE_BNDRY_16) {
				tp->dma_rwctrl &= ~DMA_RWCTRL_WRITE_BNDRY_MASK;
				tp->dma_rwctrl |= DMA_RWCTRL_WRITE_BNDRY_16;
				tw32(TG3PCI_DMA_RW_CTRL, tp->dma_rwctrl);
				break;
			} else {
				printf("tg3_test_dma() buffer corrupted on read back! \
							(%d != %d)\n", p[i], i);
				ret = -ENODEV;
				goto out;
			}
		}

		if (i == (TEST_BUFFER_SIZE / sizeof(u32_t))) {
			/* Success. */
			ret = 0;
			break;
		}
	}
out:
	minix_munmap(buf, TEST_BUFFER_SIZE);

out_nofree:
	return ret;
}

PRIVATE void tg3_init_link_config(tg3_t * tp)
{
	tp->link_config.advertising =
	(ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full |
	 ADVERTISED_100baseT_Half | ADVERTISED_100baseT_Full |
	 ADVERTISED_1000baseT_Half | ADVERTISED_1000baseT_Full |
	 ADVERTISED_Autoneg | ADVERTISED_MII);
	tp->link_config.speed = SPEED_INVALID;
	tp->link_config.duplex = DUPLEX_INVALID;
	tp->link_config.autoneg = AUTONEG_ENABLE;
	tp->link_config.active_speed = SPEED_INVALID;
	tp->link_config.active_duplex = DUPLEX_INVALID;
	tp->link_config.phy_is_low_power = 0;
	tp->link_config.orig_speed = SPEED_INVALID;
	tp->link_config.orig_duplex = DUPLEX_INVALID;
	tp->link_config.orig_autoneg = AUTONEG_INVALID;
}

PRIVATE void tg3_init_bufmgr_config(tg3_t * tp)
{

	if (tp->tg3_flags2 & TG3_FLG2_5705_PLUS) {
		tp->bufmgr_config.mbuf_read_dma_low_water =
		DEFAULT_MB_RDMA_LOW_WATER_5705;
		tp->bufmgr_config.mbuf_mac_rx_low_water =
			DEFAULT_MB_MACRX_LOW_WATER_5705;
		tp->bufmgr_config.mbuf_high_water =
			DEFAULT_MB_HIGH_WATER_5705;
		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906) {
			tp->bufmgr_config.mbuf_mac_rx_low_water =
				DEFAULT_MB_MACRX_LOW_WATER_5906;
			tp->bufmgr_config.mbuf_high_water =
				DEFAULT_MB_HIGH_WATER_5906;
		}
		tp->bufmgr_config.mbuf_read_dma_low_water_jumbo =
			DEFAULT_MB_RDMA_LOW_WATER_JUMBO_5780;
		tp->bufmgr_config.mbuf_mac_rx_low_water_jumbo =
			DEFAULT_MB_MACRX_LOW_WATER_JUMBO_5780;
		tp->bufmgr_config.mbuf_high_water_jumbo =
			DEFAULT_MB_HIGH_WATER_JUMBO_5780;
	} else {
		tp->bufmgr_config.mbuf_read_dma_low_water =
			DEFAULT_MB_RDMA_LOW_WATER;
		tp->bufmgr_config.mbuf_mac_rx_low_water =
			DEFAULT_MB_MACRX_LOW_WATER;
		tp->bufmgr_config.mbuf_high_water =
			DEFAULT_MB_HIGH_WATER;

		tp->bufmgr_config.mbuf_read_dma_low_water_jumbo =
			DEFAULT_MB_RDMA_LOW_WATER_JUMBO;
		tp->bufmgr_config.mbuf_mac_rx_low_water_jumbo =
			DEFAULT_MB_MACRX_LOW_WATER_JUMBO;
		tp->bufmgr_config.mbuf_high_water_jumbo =
			DEFAULT_MB_HIGH_WATER_JUMBO;
	}

	tp->bufmgr_config.dma_low_water = DEFAULT_DMA_LOW_WATER;
	tp->bufmgr_config.dma_high_water = DEFAULT_DMA_HIGH_WATER;
}

PRIVATE char *tg3_phy_string(tg3_t * tp)
{
	switch (tp->phy_id & PHY_ID_MASK) {
		case PHY_ID_BCM5400:return "5400";
	case PHY_ID_BCM5401:
		return "5401";
	case PHY_ID_BCM5411:
		return "5411";
	case PHY_ID_BCM5701:
		return "5701";
	case PHY_ID_BCM5703:
		return "5703";
	case PHY_ID_BCM5704:
		return "5704";
	case PHY_ID_BCM5705:
		return "5705";
	case PHY_ID_BCM5750:
		return "5750";
	case PHY_ID_BCM5752:
		return "5752";
	case PHY_ID_BCM5714:
		return "5714";
	case PHY_ID_BCM5780:
		return "5780";
	case PHY_ID_BCM5755:
		return "5755";
	case PHY_ID_BCM5787:
		return "5787";
	case PHY_ID_BCM5784:
		return "5784";
	case PHY_ID_BCM5756:
		return "5722/5756";
	case PHY_ID_BCM5906:
		return "5906";
	case PHY_ID_BCM5761:
		return "5761";
	case PHY_ID_BCM50610:
		return "50610";
	case PHY_ID_BCM50610M:
		return "50610M";
	case PHY_ID_BCMAC131:
		return "AC131";
	case PHY_ID_BCM57780:
		return "57780";
	case PHY_ID_BCM8002:
		return "8002/serdes";
	case 0:
		return "serdes";
	default:
		return "unknown";
	}
}

PRIVATE char *tg3_bus_string(tg3_t * tp, char *str)
{
	if (tp->tg3_flags2 & TG3_FLG2_PCI_EXPRESS) {
		strcpy(str, "PCI Express");
		return str;
	} else if (tp->tg3_flags & TG3_FLAG_PCIX_MODE) {
		u32_t clock_ctrl = tr32(TG3PCI_CLOCK_CTRL) & 0x1f;

		strcpy(str, "PCIX:");

		if ((clock_ctrl == 7) ||
		    ((tr32(GRC_MISC_CFG) & GRC_MISC_CFG_BOARD_ID_MASK) ==
		     GRC_MISC_CFG_BOARD_ID_5704CIOBE))
			strcat(str, "133MHz");
		else if (clock_ctrl == 0)
			strcat(str, "33MHz");
		else if (clock_ctrl == 2)
			strcat(str, "50MHz");
		else if (clock_ctrl == 4)
			strcat(str, "66MHz");
		else if (clock_ctrl == 6)
			strcat(str, "100MHz");
	} else {
		strcpy(str, "PCI:");
		if (tp->tg3_flags & TG3_FLAG_PCI_HIGH_SPEED)
			strcat(str, "66MHz");
		else
			strcat(str, "33MHz");
	}
	if (tp->tg3_flags & TG3_FLAG_PCI_32BIT)
		strcat(str, ":32-bit");
	else
		strcat(str, ":64-bit");
	return str;
}

PRIVATE void tg3_init_coal(tg3_t * tp)
{

	struct coalesce *ec = &tp->coal;

	memset(ec, 0, sizeof(*ec));
	ec->rx_coalesce_usecs = LOW_RXCOL_TICKS;	/* 0x32 */
	ec->tx_coalesce_usecs = LOW_TXCOL_TICKS;	/* 0x96 */
	ec->rx_max_coalesced_frames = LOW_RXMAX_FRAMES;	/* 0x05 */
	ec->tx_max_coalesced_frames = LOW_TXMAX_FRAMES;	/* 0x35 */
	ec->rx_coalesce_usecs_irq = DEFAULT_RXCOAL_TICK_INT;	/* 0x19 */
	ec->tx_coalesce_usecs_irq = DEFAULT_TXCOAL_TICK_INT;	/* 0x19	 */
	ec->rx_max_coalesced_frames_irq = DEFAULT_RXCOAL_MAXF_INT;/* 0x05 */
	ec->tx_max_coalesced_frames_irq = DEFAULT_TXCOAL_MAXF_INT;/* 0x05 */
	ec->stats_block_coalesce_usecs = DEFAULT_STAT_COAL_TICKS;/* 0xf4240 */

	if (tp->coalesce_mode & (HOSTCC_MODE_CLRTICK_RXBD |
				 HOSTCC_MODE_CLRTICK_TXBD)) {
		ec->rx_coalesce_usecs = LOW_RXCOL_TICKS_CLRTCKS;/* 0x14	*/
		ec->rx_coalesce_usecs_irq = DEFAULT_RXCOAL_TICK_INT_CLRTCKS;/* 0x14 */
		ec->tx_coalesce_usecs = LOW_TXCOL_TICKS_CLRTCKS;/* 0x14 */
		ec->tx_coalesce_usecs_irq = DEFAULT_TXCOAL_TICK_INT_CLRTCKS;/* 0x14 */
	}
	if (tp->tg3_flags2 & TG3_FLG2_5705_PLUS) {
		ec->rx_coalesce_usecs_irq = 0;
		ec->tx_coalesce_usecs_irq = 0;
		ec->stats_block_coalesce_usecs = 0;
	}
}


PRIVATE int tg3_init_one(tg3_t * tp)
{
	static int tg3_version_printed = 0;
	int err, pm_cap;
	char str[40];

	if (tg3_version_printed++ == 0)
		printf("%s", version);

	pci_find_cap(tp->devind, PCI_CAP_ID_PM, &pm_cap);
	if (pm_cap == 0) {
		printf("Cannot find PowerManagement capability aborting.\n");
		err = -EIO;
		goto err_out_free_res;
	}
	tp->device = pci_attr_r16(tp->devind, PCI_VID);
	tp->vendor = pci_attr_r16(tp->devind, PCI_DID);
	tp->subsystem_vendor = pci_attr_r16(tp->devind, PCI_SUBVID);
	tp->subsystem_device = pci_attr_r16(tp->devind, PCI_SUBDID);

	tp->device_name = pci_dev_name(tp->vendor, tp->device);
	tp->mtu = 1500;
	if (!tp->name)
		tp->device_name = "Unknown Device";

	tp->pm_cap = pm_cap;
	tp->rx_mode = TG3_DEF_RX_MODE;
	tp->tx_mode = TG3_DEF_TX_MODE;

	/* The word/byte swap controls here control register access byte
	 * swapping.  DMA data byte swapping is controlled in the GRC_MODE
	 * setting below. */
	tp->misc_host_ctrl =
		MISC_HOST_CTRL_MASK_PCI_INT |
		MISC_HOST_CTRL_WORD_SWAP |
		MISC_HOST_CTRL_INDIR_ACCESS |
		MISC_HOST_CTRL_PCISTATE_RW;

	/* The NONFRM (non-frame) byte/word swap controls take effect on
	 * descriptor entries, anything which isn't packet data.
	 * 
	 * The StrongARM chips on the board (one for tx, one for rx) are running
	 * in big-endian mode. */
	tp->grc_mode = (GRC_MODE_WSWAP_DATA | GRC_MODE_BSWAP_DATA |
			GRC_MODE_WSWAP_NONFRM_DATA);
#ifdef __BIG_ENDIAN
	tp->grc_mode |= GRC_MODE_BSWAP_NONFRM_DATA;
#endif

	tp->regs = (u8_t *) vm_map_phys(SELF, (void *) (tp->bar), 0xFFFF);

	pci_attr_w32(tp->devind, 0x14, 0x0);
	micro_delay(10000);

	if (!tp->regs) {
		printf("Cannot map device registers aborting.\n");
		err = -ENOMEM;
		goto err_out_free_dev;
	}
	tg3_init_link_config(tp);

	tp->rx_pending = TG3_DEF_RX_RING_PENDING;
	tp->rx_jumbo_pending = TG3_DEF_RX_JUMBO_RING_PENDING;
	tp->tx_pending = TG3_DEF_TX_RING_PENDING;

	tp->irq = pci_attr_r8(tp->devind, PCI_ILR);

	err = tg3_get_invariants(tp);

	if (err) {
		printf("Problem fetching invariants of chip, aborting.\n");
		goto err_out_iounmap;
	}
	tg3_init_bufmgr_config(tp);

	if (tp->pci_chip_rev_id == CHIPREV_ID_5701_A0) {
		printf("FIRMWARE_TG3\n");
		tp->fw_needed = FIRMWARE_TG3;
	}
	if (tp->tg3_flags2 & TG3_FLG2_HW_TSO) {
		tp->tg3_flags2 |= TG3_FLG2_TSO_CAPABLE;
	} else if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5700 ||
		   GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5701 ||
		   tp->pci_chip_rev_id == CHIPREV_ID_5705_A0 ||
		   GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5906 ||
		   (tp->tg3_flags & TG3_FLAG_ENABLE_ASF) != 0) {
		tp->tg3_flags2 &= ~TG3_FLG2_TSO_CAPABLE;
	} else {
		tp->tg3_flags2 |= TG3_FLG2_TSO_CAPABLE | TG3_FLG2_TSO_BUG;
		if (GET_ASIC_REV(tp->pci_chip_rev_id) == ASIC_REV_5705) {
			printf("FIRMWARE_TG3\n");
			tp->fw_needed = FIRMWARE_TG3TSO5;
		} else {
			printf("FIRMWARE_TG3\n");
			tp->fw_needed = FIRMWARE_TG3TSO;
		}
	}

	if (tp->pci_chip_rev_id == CHIPREV_ID_5705_A1 &&
	    !(tp->tg3_flags2 & TG3_FLG2_TSO_CAPABLE) &&
	    !(tr32(TG3PCI_PCISTATE) & PCISTATE_BUS_SPEED_HIGH)) {
		tp->tg3_flags2 |= TG3_FLG2_MAX_RXPEND_64;
		tp->rx_pending = 63;
	}
	err = tg3_get_device_address(tp);
	if (err) {
		printf("Could not obtain valid ethernet address: aborting.\n");
		goto err_out_fw;
	}

	if (tp->tg3_flags3 & TG3_FLG3_ENABLE_APE) {
		u32_t bar2;		
		printf("TG3 : APE not yet tested\n");
		bar2 = pci_attr_r32(tp->devind, PCI_BAR_2) & 0xffffffe0;

		if (bar2 < 0x400)
			panic("TG3: Bar2 base address is not properly configured");

		tp->aperegs = (u8_t *) vm_map_phys(SELF, (void *)bar2, 0xFFFF);
		if (!tp->aperegs) {
			printf("Cannot map APE registers, aborting.\n");
			err = -ENOMEM;
			goto err_out_fw;
		}

		tg3_ape_lock_init(tp);

		if (tp->tg3_flags & TG3_FLAG_ENABLE_ASF)
			tg3_read_dash_ver(tp);
	}
	/* Reset chip in case UNDI or EFI driver did not shutdown DMA self test
	 * will enable WDMAC and we'll see (spurious) pending DMA on the PCI
	 * bus at that point. */
	if ((tr32(HOSTCC_MODE) & HOSTCC_MODE_ENABLE) ||
	    (tr32(WDMAC_MODE) & WDMAC_MODE_ENABLE)) {
		tw32(MEMARB_MODE, MEMARB_MODE_ENABLE);
		tg3_halt(tp, RESET_KIND_SHUTDOWN, 1);
	}
	err = tg3_test_dma(tp);
	if (err) {
		printf("%s DMA engine test failed\n", tp->name);
		goto err_out_apeunmap;
	}
	/* flow control autonegotiation is default behavior */
	tp->tg3_flags |= TG3_FLAG_PAUSE_AUTONEG;
	tp->link_config.flowctrl = FLOW_CTRL_TX | FLOW_CTRL_RX;

	tg3_init_coal(tp);

	printf("%s: Tigon3 [partno(%s) rev %04x] (%s)\n",
	       tp->name,
	       tp->board_part_number,
	       tp->pci_chip_rev_id,
	       tg3_bus_string(tp, str));

	printf("%s: attached PHY is %s (%s Ethernet) (WireSpeed[%d])\n",
	       tp->name, tg3_phy_string(tp),
	       ((tp->tg3_flags & TG3_FLAG_10_100_ONLY) ? "10/100Base-TX" :
		((tp->tg3_flags2 & TG3_FLG2_ANY_SERDES) ? "1000Base-SX" :
		 "10/100/1000Base-T")),
	       (tp->tg3_flags2 & TG3_FLG2_NO_ETH_WIRE_SPEED) == 0);

	printf("%s: RXcsums[%d] LinkChgREG[%d] MIirq[%d] ASF[%d] TSOcap[%d]\n",
	       tp->name,
	       (tp->tg3_flags & TG3_FLAG_RX_CHECKSUMS) != 0,
	       (tp->tg3_flags & TG3_FLAG_USE_LINKCHG_REG) != 0,
	       (tp->tg3_flags & TG3_FLAG_USE_MI_INTERRUPT) != 0,
	       (tp->tg3_flags & TG3_FLAG_ENABLE_ASF) != 0,
	       (tp->tg3_flags2 & TG3_FLG2_TSO_CAPABLE) != 0);

	return 0;

err_out_apeunmap:
	if (tp->aperegs) {
		vm_unmap_phys(SELF, tp->aperegs, 0xFFFF);
		tp->aperegs = NULL;
	}

err_out_fw:
	/* Minix doesn't currently support external firmware loads */
/*	if (tp->fw)*/
/*		release_firmware(tp->fw);*/

err_out_iounmap:
	if (tp->regs) {
		vm_unmap_phys(SELF, tp->regs, 0xFFFF);
		tp->regs = NULL;
	}
err_out_free_dev:

err_out_free_res:
	return err;
}

PRIVATE void tg3_remove_one(tg3_t * tp)
{
	if (tp->fw) {
		printf("NO FIRMWARE SUPPORT\n");
	}
	if (tp->tg3_flags3 & TG3_FLG3_USE_PHYLIB) {
		tg3_phy_fini(tp);
		tg3_mdio_fini(tp);
	}
	if (tp->aperegs) {
		vm_unmap_phys(SELF, tp->aperegs, 0xFFFF);
		tp->aperegs = NULL;
	}
	if (tp->regs) {
		vm_unmap_phys(SELF, tp->regs, 0xFFFF);
		tp->regs = NULL;
	}
}
