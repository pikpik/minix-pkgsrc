/* Native macro definitions for GDB on an Intel i[3456]86.
 */

#ifndef NM_MINIX_H
#define NM_MINIX_H 1

#include "i386/nm-i386.h"

#define KERNEL_U_ADDR 0

#define REGISTER_U_ADDR(addr, blockend, regno) \
	(addr) = register_u_addr (blockend, regno)
	
extern CORE_ADDR register_u_addr (CORE_ADDR blockend, int regnum);

#define U_REGS_OFFSET 0

#endif /* NM_MINIX_H */
