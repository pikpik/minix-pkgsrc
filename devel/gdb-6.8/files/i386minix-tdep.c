/* Target-dependent code for MINIX/i386.
 */

#include "defs.h"
#include "arch-utils.h"
#include "frame.h"
#include "gdbcore.h"
#include "regcache.h"
#include "regset.h"
#include "osabi.h"
#include "symtab.h"

#include "gdb_assert.h"
#include "gdb_string.h"

#include "i386-tdep.h"
#include "i387-tdep.h"

#ifdef __minix
#include <i386/stackframe.h>
#endif

/* At i386minix_r_reg_offsets[REGNUM] you'll find the offset in
  `struct stackframe_s' where the GDB register REGNUM is stored. */
static int i386minix_r_reg_offset[] =
{
#ifdef STACK_FRAME_H
  offsetof (struct stackframe_s, retreg),
  offsetof (struct stackframe_s, cx),
  offsetof (struct stackframe_s, dx),
  offsetof (struct stackframe_s, bx),
  offsetof (struct stackframe_s, sp),
  offsetof (struct stackframe_s, fp),
  offsetof (struct stackframe_s, si),
  offsetof (struct stackframe_s, di),
  offsetof (struct stackframe_s, pc),
  offsetof (struct stackframe_s, psw),
  offsetof (struct stackframe_s, cs),
  offsetof (struct stackframe_s, ss),
  offsetof (struct stackframe_s, ds),
  offsetof (struct stackframe_s, es),
  offsetof (struct stackframe_s, fs),
  offsetof (struct stackframe_s, gs)
#else
  7 * 4 + 8,			/* %eax */
  6 * 4 + 8,			/* %ecx */
  5 * 4 + 8,			/* %edx */
  4 * 4 + 8,			/* %ebx */
  12 * 4 + 8,			/* %esp */
  2 * 4 + 8,			/* %ebp */
  1 * 4 + 8,			/* %esi */
  0 * 4 + 8,			/* %edi */
  9 * 4 + 8,			/* %eip */
  11 * 4 + 8,			/* %eflags */
  10 * 4 + 8,			/* %cs */
  13 * 4 + 8,			/* %ss */
  3 * 2,			/* %ds */
  2 * 2,			/* %es */
  1 * 2,			/* %fs */
  0 * 2 			/* %gs */ 
#endif
};

/* Return whether the frame preceding NEXT_FRAME corresponds to a
   MINIX sigtramp routine.  */

static int
i386minix_sigtramp_p (struct frame_info *next_frame)
{
  CORE_ADDR pc = frame_pc_unwind (next_frame);
  char *name;

  find_pc_partial_function (pc, &name, NULL, NULL);
  return ( name && strcmp(name, "_sigreturn") == 0 );
}

/* From <sys/sigcontext.h>.  */
/* normal stackframe_s with flags and mask in front */
int i386minix_sc_reg_offset[] =
{
#ifdef STACK_FRAME_H
  offsetof (struct stackframe_s, retreg) + 8,
  offsetof (struct stackframe_s, cx) + 8,
  offsetof (struct stackframe_s, dx) + 8,
  offsetof (struct stackframe_s, bx) + 8,
  offsetof (struct stackframe_s, sp) + 8,
  offsetof (struct stackframe_s, fp) + 8,
  offsetof (struct stackframe_s, si) + 8,
  offsetof (struct stackframe_s, di) + 8,
  offsetof (struct stackframe_s, pc) + 8,
  offsetof (struct stackframe_s, psw) + 8,
  offsetof (struct stackframe_s, cs) + 8,
  offsetof (struct stackframe_s, ss) + 8,
  offsetof (struct stackframe_s, ds) + 8,
  offsetof (struct stackframe_s, es) + 8,
  offsetof (struct stackframe_s, fs) + 8,
  offsetof (struct stackframe_s, gs) + 8
#else
#define SC_REG(n) (n + 8)
	SC_REG(36), 
	SC_REG(32),
	SC_REG(28),
	SC_REG(24),
	SC_REG(56),
	SC_REG(16),
	SC_REG(12),
	SC_REG(8),
	SC_REG(44), 
	SC_REG(52), 
	SC_REG(48), 
	SC_REG(60), 
  #if 0
	-1, 
	-1, 
	-1, 
	-1 
  #else
  SC_REG(6),			/* %ds */
  SC_REG(4),			/* %es */
  SC_REG(2),			/* %fs */
  SC_REG(0) 			/* %gs */
#undef SC_REG
  #endif
#endif
};

static enum gdb_osabi
i386minix_elf_osabi_sniffer (bfd *abfd)
{

  if (strcmp (bfd_get_target (abfd), "elf32-i386-minix") == 0)
    return GDB_OSABI_MINIX;

  return GDB_OSABI_UNKNOWN;
}

static CORE_ADDR
i386minix_sigcontext_addr (struct frame_info *next_frame)
{
  gdb_byte buf[4];
  CORE_ADDR sp;

  frame_unwind_register (next_frame, I386_ESP_REGNUM, buf);
  sp = extract_unsigned_integer (buf, 4);

/* #warning "Controlleer deze sp + 8" */
  return read_memory_unsigned_integer (sp + 8, 4);
}

static void 
i386minix_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
{
  struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);

  tdep->jb_pc_offset = 8;
  tdep->sigcontext_addr = i386minix_sigcontext_addr;
  
  tdep->gregset_reg_offset = i386minix_r_reg_offset;
  tdep->gregset_num_regs = ARRAY_SIZE (i386minix_r_reg_offset);
  tdep->sizeof_gregset = 16 * 4;

  /* MINIX do not use -freg-struct-return by default. */
  tdep->struct_return = pcc_struct_return;

  /* MINIX has different signal trampoline conventions.  */
  tdep->sigtramp_start = 0;
  tdep->sigtramp_end = 0;
  tdep->sigtramp_p = i386minix_sigtramp_p;

/* CHECKME */
  tdep->sc_reg_offset = i386minix_sc_reg_offset;
  tdep->sc_num_regs = ARRAY_SIZE (i386minix_sc_reg_offset);

  i386_elf_init_abi (info, gdbarch);

/*
  tramp_frame_prepend_unwinder (gdbarch, &i386minix_sigtramp_scxx);
 */
  
/*
  set_gdbarch_cannot_store_register( gdbarch, i386minix_cannot_store_register );
 */

  tdep->st0_regnum = -1;
  tdep->mm0_regnum = -1;
  tdep->num_xmm_regs = 0;
  
  set_gdbarch_num_regs( gdbarch, 16 );
  set_gdbarch_num_pseudo_regs( gdbarch, 0 );
}

void
_initialize_i386minix_tdep (void)
{

  /* Register a sniffer for ELF files - this overrides
   * the generic elf osabi sniffer in osabi.c */
  gdbarch_register_osabi_sniffer (bfd_arch_i386, bfd_target_elf_flavour,
				  i386minix_elf_osabi_sniffer);	

  gdbarch_register_osabi (bfd_arch_i386, 0, GDB_OSABI_MINIX,
			  i386minix_init_abi);
}
