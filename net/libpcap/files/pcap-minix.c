#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "pcap-int.h"
#include "pcap/sll.h"
#include "pcap/vlan.h"

#include <sys/param.h>			/* optionally get BSD define */

#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>

#include <net/netlib.h>
#include <net/gen/ether.h>
#include <net/gen/eth_io.h>
#include <sys/ioc_net.h>
#include <netinet/in.h>

#include "pcap-int.h"

static int
pcap_read_minix3(pcap_t *handle, int max_packets,
	pcap_handler callback, u_char *user)
{
	unsigned char frame[ETH_MAX_PACK_SIZE_TAGGED];
	ssize_t n;
	struct pcap_pkthdr hdr;

	if (handle->break_loop) {
		handle->break_loop = 0;
		return -2;
	}

	n = read(handle->fd, frame, sizeof(frame));

	if(n < 0) {
		snprintf(handle->errbuf, PCAP_ERRBUF_SIZE,
                	"read: %s", pcap_strerror(errno));
		return -1;
	}

	hdr.caplen = n > handle->snapshot ? handle->snapshot : n;

        /* Run the packet filter if not using kernel filter. */
        if (handle->fcode.bf_insns) {
                if (bpf_filter(handle->fcode.bf_insns, frame,
                                n, hdr.caplen) == 0)
                {
                        /* rejected by filter */
                        return 0;
                }
        }

	hdr.len = n;
	gettimeofday(&hdr.ts, NULL);

	callback(user, &hdr, frame);

	return 1;
}

static void pcap_cleanup_minix3(pcap_t *handle)
{
	close(handle->fd);
}

static int
pcap_stats_minix3(pcap_t *handle, struct pcap_stat *stat)
{
	stat->ps_recv = handle->md.TotAccepted;
	stat->ps_drop = 0;

	return 0;
}

static int
pcap_activate_minix3(pcap_t *handle)
{
	nwio_ethopt_t ethopt;
	int fd, opts;
	static char name[20];

        handle->setfilter_op = install_bpf_program;
        handle->getnonblock_op = pcap_getnonblock_fd;
        handle->setnonblock_op = pcap_setnonblock_fd;
        handle->cleanup_op = pcap_cleanup_minix3;
        handle->read_op = pcap_read_minix3;
        handle->stats_op = pcap_stats_minix3;

	opts = NWEO_COPY | /* receive copies of incoming packets */
        NWEO_EN_LOC |      /* receive local packets */
        NWEO_EN_BROAD |   /* receive broadcast packets */
        NWEO_EN_MULTI |   /* receive multicast packets */
        NWEO_REMANY |     /* no restriction on destinations */
        NWEO_TYPEANY |     /* no restriction on packet types */
        NWEO_RWDATALL;     /* ethernet header included */

	if(!handle->opt.source)
		strcpy(name, ETH_DEVICE);
	else
		snprintf(name, sizeof(name), "/dev/%s", handle->opt.source);

	if((fd = open(name, O_RDONLY)) < 0) {
		snprintf(handle->errbuf, PCAP_ERRBUF_SIZE,
			"open: %s", pcap_strerror(errno));
		return PCAP_ERROR;
	}

	if(handle->opt.promisc)
		opts |= NWEO_EN_PROMISC;

	memset(&ethopt, 0, sizeof(ethopt));
	ethopt.nweo_flags = opts;

	if(ioctl(fd, NWIOSETHOPT, &ethopt) < 0) {
		close(fd);
		snprintf(handle->errbuf, PCAP_ERRBUF_SIZE,
			"NWIOSETHOPT: %s", pcap_strerror(errno));

		return PCAP_ERROR;
	}

	handle->fd = handle->selectable_fd = fd;
	handle->linktype = DLT_EN10MB;

	/* OK. */
	return 0;
}

pcap_t *
pcap_create(const char *dev, char *e)
{
	pcap_t *p;

	if(!(p = pcap_create_common(dev, e)))
		return NULL;

	p->activate_op = pcap_activate_minix3;

	return p;
}


int    
pcap_platform_finddevs(pcap_if_t **alldevsp, char *errbuf)
{
	int i;

	for(i = 0; i < 100; i++) {
		int f;
		char name[20];
		snprintf(name, sizeof(name), "/dev/eth%d", i);

		if((f=open(name, O_RDONLY)) >= 0) {
			char *node;
			if(!(node = strrchr(name, '/'))) {
				continue; /* "can't happen" */
			}
			node++;
        		if (pcap_add_if(alldevsp, node,
				0, NULL, errbuf) < 0)
				return -1;
			close(f);
		}
	}

	return 0;
}
