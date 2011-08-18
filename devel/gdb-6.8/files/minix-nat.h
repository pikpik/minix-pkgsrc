/*
 * Native-dependent code for MINIX.
 */

#ifndef MINIX_NAT_H
#define MINIX_NAT_H

/* Return a the name of file that can be opened to get the symbols for
   the child process identified by PID.  */

extern char *minix_pid_to_exec_file (int pid);

/* Iterate over all the memory regions in the current inferior,
   calling FUNC for each memory region.  OBFD is passed as the last
   argument to FUNC.  */

extern int minix_find_memory_regions (int (*func) (CORE_ADDR, unsigned long,
						  int, int, int, void *),
				     void *obfd);

/* Create appropriate note sections for a corefile, returning them in
   allocated memory.  */

extern char *minix_make_corefile_notes (bfd *obfd, int *note_size);

#endif /* minix-nat.h */
