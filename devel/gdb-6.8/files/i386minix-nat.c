/* 
 * Native-dependent code for MINIX/i386.
 */

#include "defs.h"
#include "inferior.h"
#include "gdbcore.h"
#include "regcache.h"
#include "target.h"

#include "gdb_ptrace.h"
#include "inf-ptrace.h"
#include "minix-nat.h"

#ifdef __minix
#include <i386/stackframe.h>
#endif

/* In this file we teach GDB how to use ptrace (to fetch registers) */

/* Provide prototypes to silence -Wmissing-prototypes.  */
void _initialize_i386minix_nat (void);
static void i386minix_fetch_register (struct regcache *, int);
static void i386minix_fetch_registers (struct regcache *, int);
static void i386minix_store_register (const struct regcache *, int);
static void i386minix_store_registers (struct regcache *, int);


/* At i386minix_reg_offsets[REGNUM] you'll find the offset in
  `struct stackframe_s' where the GDB register REGNUM is stored. */
static CORE_ADDR i386minix_reg_offsets[] = {
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

/* ds, es, fs, gs are 16-bit registers; the others are 32-bit */
#define MINIX_IS_REG16(regno) (i386minix_reg_offsets[regno] <= 3*2)

/* Fetch register REGNUM from the inferior.  */
static void
i386minix_fetch_register (struct regcache *regcache, int regnum)
{
  struct gdbarch *gdbarch = get_regcache_arch (regcache);
  CORE_ADDR addr, addr_sreg;
  size_t size;
  PTRACE_TYPE_RET *buf;
  int pid, i;

  /* This isn't really an address, but ptrace thinks of it as one.  */
  /* Registers are at beginning of user area; bounds are already checked (?) */
  addr_sreg = i386minix_reg_offsets[regnum];

  /* Some segment registers are not aligned.
   * This is checked in kernel/system/do_trace.c,
   * so we must align them at sizeof (PTRACE_TYPE_RET) */
  addr = addr_sreg & (~ (sizeof (PTRACE_TYPE_RET) - 1));

  if ((addr == (CORE_ADDR)-1)
      || (gdbarch_cannot_fetch_register (gdbarch, regnum)))
    {
      regcache_raw_supply (regcache, regnum, NULL);
      return;
    }

#if 0
  /* Cater for systems like GNU/Linux, that implement threads as
     separate processes.  */
  pid = ptid_get_lwp (inferior_ptid);
  if (pid == 0)
    pid = ptid_get_pid (inferior_ptid);
#else
  pid = ptid_get_pid (inferior_ptid);
#endif

  /* TODO: For i386 this will always return 4 ? (even though in stackframe_s)
   * there are 16 bit registers? */
  size = register_size (gdbarch, regnum);

  gdb_assert ((size % sizeof (PTRACE_TYPE_RET)) == 0);
  buf = alloca (size / sizeof (PTRACE_TYPE_RET));

  /* Read the register contents from the inferior a chunk at a time. */
  for (i = 0; i < size / sizeof (PTRACE_TYPE_RET); i++)
  {
    errno = 0;
    buf[i] = ptrace (PT_READ_U, pid, (PTRACE_TYPE_ARG3)(uintptr_t)addr, 0);
    if (errno != 0)
       error (_("Couldn't read register %s (#%d): %s."),
	     gdbarch_register_name (gdbarch, regnum),
	     regnum, safe_strerror (errno));

    addr += sizeof (PTRACE_TYPE_RET);
  }

  /* Deal with 16 bit registers (unaligned, smaller). */
  if (MINIX_IS_REG16(regnum))
  {
    if (addr == addr_sreg)
      buf[0] >>= 16;
    else
      buf[0] &= 0xFFFF;
  }

  regcache_raw_supply (regcache, regnum, buf);
}

/* Fetch register REGNUM from the inferior.  If REGNUM is -1, do this
   for all registers.  */

static void
i386minix_fetch_registers (struct regcache *regcache, int regnum)
{
  if (regnum == -1)
    for (regnum = 0;
	 regnum < gdbarch_num_regs (get_regcache_arch (regcache));
	 regnum++)
      i386minix_fetch_register (regcache, regnum);
  else
    i386minix_fetch_register (regcache, regnum);
}

/* Store register REGNUM into the inferior.  */

static void
i386minix_store_register (const struct regcache *regcache, int regnum)
{
  struct gdbarch *gdbarch = get_regcache_arch (regcache);
  CORE_ADDR addr;
  size_t size;
  PTRACE_TYPE_RET *buf;
  int pid, i;

  /* This isn't really an address, but ptrace thinks of it as one.  */
  /* Registers are at beginning of user area; bounds are already checked (?) */
  addr = i386minix_reg_offsets[regnum];
  if (addr == (CORE_ADDR)-1 
      || MINIX_IS_REG16(regnum) /* setting segment register is forbidden. */
      || gdbarch_cannot_store_register (gdbarch, regnum))
    return;

#if 0
  /* Cater for systems like GNU/Linux, that implement threads as
     separate processes.  */
  pid = ptid_get_lwp (inferior_ptid);
  if (pid == 0)
    pid = ptid_get_pid (inferior_ptid);
#else
  pid = ptid_get_pid (inferior_ptid);
#endif

  size = register_size (gdbarch, regnum);
  gdb_assert ((size % sizeof (PTRACE_TYPE_RET)) == 0);
  buf = alloca (size);

  /* Write the register contents into the inferior a chunk at a time.  */
  regcache_raw_collect (regcache, regnum, buf);
  for (i = 0; i < size / sizeof (PTRACE_TYPE_RET); i++)
    {
      errno = 0;
      ptrace (PT_WRITE_U, pid, (PTRACE_TYPE_ARG3)(uintptr_t)addr, buf[i]);
      if (errno != 0)
	error (_("Couldn't write register %s (#%d): %s."),
	       gdbarch_register_name (gdbarch, regnum),
	       regnum, safe_strerror (errno));

      addr += sizeof (PTRACE_TYPE_RET);
    }
}

/* Store register REGNUM back into the inferior.  If REGNUM is -1, do
   this for all registers.  */

void
i386minix_store_registers (struct regcache *regcache, int regnum)
{
  if (regnum == -1)
    for (regnum = 0;
	 regnum < gdbarch_num_regs (get_regcache_arch (regcache));
	 regnum++)
      i386minix_store_register (regcache, regnum);
  else
    i386minix_store_register (regcache, regnum);
}

void
_initialize_i386minix_nat (void)
{
  struct target_ops *t = inf_ptrace_target();
  t->to_fetch_registers = i386minix_fetch_registers;
  t->to_store_registers = i386minix_store_registers;
  t->to_pid_to_exec_file = minix_pid_to_exec_file;
  t->to_find_memory_regions = minix_find_memory_regions;
  t->to_make_corefile_notes = minix_make_corefile_notes;

  add_target (t);
}
