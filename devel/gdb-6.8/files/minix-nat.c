/* 
 * Native-dependent code for MINIX.
 */

#include "defs.h"
#include "gdbcore.h"        /* for get_exec_file */
#include "inferior.h"
#include "regcache.h"
#include "regset.h"

#include "gdb_assert.h"
#include "gdb_string.h"
#include <sys/types.h>
#include <sys/param.h>      /* for MAXPATHLEN, etc. */
#include <sys/elf_core.h>   /* for gregset_t and other stuff */

#include "elf-bfd.h"
#include "minix-nat.h"

/* Return a the name of file that can be opened to get the symbols for
   the child process identified by PID.  */

char *
minix_pid_to_exec_file (int pid)
{
  size_t len = MAXPATHLEN;
  char *buf = xcalloc (len, sizeof (char));
  char *path;

  if (info_verbose)
    fprintf_filtered (gdb_stdout, 
		      "[minix_pid_to_exec_file]\n");

  /* XXX: Should create another file in /proc ? - cmdline also contains the arguments,
     but are terminated with nulls */	
  path = xstrprintf ("/proc/%d/cmdline", pid);
  if (readlink (path, buf, MAXPATHLEN) == -1)
    {
      xfree (buf);
      buf = NULL;
    }

  xfree (path);
  return buf;
}

static int
minix_read_mapping (FILE *mapfile, unsigned long *start, unsigned long *end,
		   char *permissions)
{
  char buf[256];
  char seg;	
  char r, w, x, shared;	
  int ret = EOF;

  /* We read one mapping from /proc/id/map . The layout of this file
     can be seen in servers/procfs/pid.c */
  if (fgets (buf, sizeof buf, mapfile) != NULL)
    ret = sscanf (buf, "%c %08lx-%08lx %s %c", &seg, start, end,
		  permissions, &shared);

  return (ret != 0 && ret != EOF);
}

/* Iterate over all the memory regions in the current inferior,
   calling FUNC for each memory region.  OBFD is passed as the last
   argument to FUNC.  */

int
minix_find_memory_regions (int (*func) (CORE_ADDR, unsigned long,
				       int, int, int, void *),
			  void *obfd)
{
  pid_t pid = ptid_get_pid (inferior_ptid);
  char *mapfilename;
  FILE *mapfile;
  unsigned long start, end, size;
  char permissions[4];
  int read, write, exec;

  mapfilename = xstrprintf ("/proc/%ld/map", (long) pid);
  mapfile = fopen (mapfilename, "r");
  if (mapfile == NULL)
    error (_("Couldn't open %s."), mapfilename);

  if (info_verbose)
    fprintf_filtered (gdb_stdout, 
		      "Reading memory regions from %s\n", mapfilename);

  /* Now iterate until end-of-file.  */
  while (minix_read_mapping (mapfile, &start, &end, &permissions[0]))
    {
      size = end - start;

      read = (strchr (permissions, 'r') != 0);
      write = (strchr (permissions, 'w') != 0);
      exec = (strchr (permissions, 'x') != 0);

      if (info_verbose)
	{
	  fprintf_filtered (gdb_stdout, 
			    "Save segment, %ld bytes at 0x%s (%c%c%c)\n", 
			    size, paddr_nz (start),
			    read ? 'r' : '-',
			    write ? 'w' : '-',
			    exec ? 'x' : '-');
	}

      /* Invoke the callback function to create the corefile segment. */
      func (start, size, read, write, exec, obfd);
    }

  fclose (mapfile);
  return 0;
}

/* Create appropriate note sections for a corefile, returning them in
   allocated memory.  */

char *
minix_make_corefile_notes (bfd *obfd, int *note_size)
{
  const struct regcache *regcache = get_current_regcache ();
  struct gdbarch *gdbarch = get_regcache_arch (regcache);
  gregset_t gregs;
  char *note_data = NULL;
  Elf_Internal_Ehdr *i_ehdrp;
  const struct regset *regset;
  size_t size;
  minix_elfcore_info_t mei;


  /* Write the first note, containing the minix_elfcore_info_t structure */
  mei.mei_version = MINIX_ELFCORE_VERSION;
  mei.mei_meisize = sizeof(minix_elfcore_info_t);
  mei.mei_signo = stop_signal;
  mei.mei_pid = ptid_get_pid (inferior_ptid);
  memset(mei.mei_command, 0, sizeof(mei.mei_command));

  if (get_exec_file (0))
  {
    char *fname = strrchr (get_exec_file (0), '/') + 1;
    strncpy(mei.mei_command, fname, sizeof(mei.mei_command));
  }

  note_data = elfcore_write_note (obfd, note_data, note_size,
				 "MINIX-CORE", NT_MINIX_ELFCORE_INFO,
				 &mei, sizeof (minix_elfcore_info_t));

  /* Write the second note, containing the gregset_t structure */
  gdb_assert (gdbarch_regset_from_core_section_p (gdbarch));

  size = sizeof gregs;
  regset = gdbarch_regset_from_core_section (gdbarch, ".reg", size);
  gdb_assert (regset && regset->collect_regset);
  regset->collect_regset (regset, regcache, -1, &gregs, size);

  note_data = elfcore_write_note (obfd, note_data, note_size,
				 "MINIX-CORE", NT_MINIX_ELFCORE_GREGS,
				 &gregs, sizeof (gregset_t));

  make_cleanup (xfree, note_data);
  return note_data;
}
