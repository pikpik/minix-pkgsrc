/* 
 * Native-dependent code for MINIX.
 */

#include "defs.h"
#include "gdbcore.h"        /* for get_exec_file */
#include "inferior.h"
#include "regcache.h"
#include "regset.h"
#include "gdbthread.h"

#include "gdb_assert.h"
#include "gdb_string.h"
#include <sys/types.h>
#include <sys/procfs.h>
#include <sys/sysctl.h>
#include <sys/param.h>      /* for MAXPATHLEN, etc. */
#include <sys/elf_core.h>   /* for gregset_t and other stuff */

#include "elf-bfd.h"
#include "minix-nat.h"

/* Return the name of file that can be opened to get the symbols for
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
minix_find_memory_regions (find_memory_region_ftype func, void *obfd)
{
  pid_t pid = ptid_get_pid (inferior_ptid);
  char *mapfilename;
  FILE *mapfile;
  unsigned long start, end, size;
  char permissions[4];
  int read, write, exec;
  struct cleanup *cleanup;

  mapfilename = xstrprintf ("/proc/%ld/map", (long) pid);
  cleanup = make_cleanup (xfree, mapfilename);
  mapfile = fopen (mapfilename, "r");
  if (mapfile == NULL)
    error (_("Couldn't open %s."), mapfilename);
  make_cleanup_fclose (mapfile);

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
			    "Save segment, %ld bytes at %s (%c%c%c)\n",
			    size, paddress (target_gdbarch, start),
			    read ? 'r' : '-',
			    write ? 'w' : '-',
			    exec ? 'x' : '-');
	}

      /* Invoke the callback function to create the corefile segment. */
      func (start, size, read, write, exec, obfd);
    }

  fclose (mapfile);
  do_cleanups (cleanup);
  return 0;
}

static int
find_signalled_thread (struct thread_info *info, void *data)
{
  if (info->suspend.stop_signal != TARGET_SIGNAL_0
      && ptid_get_pid (info->ptid) == ptid_get_pid (inferior_ptid))
    return 1;

  return 0;
}

static enum target_signal
find_stop_signal (void)
{
  struct thread_info *info =
    iterate_over_threads (find_signalled_thread, NULL);

  if (info)
    return info->suspend.stop_signal;
  else
    return TARGET_SIGNAL_0;
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

  mei.mei_signo = find_stop_signal();
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
