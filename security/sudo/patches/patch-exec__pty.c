$NetBSD$

--- exec_pty.c.orig	Fri Jul 15 23:28:23 2011
+++ exec_pty.c
@@ -797,7 +797,9 @@ exec_monitor(path, argv, envp, backchannel, rbac)
      * in the foreground, assign its pgrp to the tty.
      */
     child_pgrp = child;
+#ifndef __minix
     setpgid(child, child_pgrp);
+#endif
     if (foreground) {
 	do {
 	    status = tcsetpgrp(io_fds[SFD_SLAVE], child_pgrp);
@@ -981,7 +983,9 @@ exec_pty(path, argv, envp, rbac_enabled)
     pid_t self = getpid();
 
     /* Set child process group here too to avoid a race. */
+#ifndef __minix
     setpgid(0, self);
+#endif
 
     /* Wire up standard fds, note that stdout/stderr may be pipes. */
     if (dup2(io_fds[SFD_STDIN], STDIN_FILENO) == -1 ||
