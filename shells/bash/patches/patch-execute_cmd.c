--- execute_cmd.c.orig	Wed Feb  9 22:32:25 2011
+++ execute_cmd.c	Wed Feb 20 23:45:49 2013
@@ -2196,6 +2196,7 @@
   if (ignore_return && cmd)
     cmd->flags |= CMD_IGNORE_RETURN;
 
+#if defined (JOB_CONTROL)
   lastpipe_flag = 0;
   begin_unwind_frame ("lastpipe-exec");
   lstdin = -1;
@@ -2219,11 +2220,14 @@
     }	  
   if (prev >= 0)
     add_unwind_protect (close, prev);
+#endif
 
   exec_result = execute_command_internal (cmd, asynchronous, prev, pipe_out, fds_to_close);
 
+#if defined (JOB_CONTROL)
   if (lstdin > 0)
     restore_stdin (lstdin);
+#endif
 
   if (prev >= 0)
     close (prev);
@@ -2246,7 +2250,9 @@
       unfreeze_jobs_list ();
     }
 
+#if defined (JOB_CONTROL)
   discard_unwind_frame ("lastpipe-exec");
+#endif
 
   return (exec_result);
 }
