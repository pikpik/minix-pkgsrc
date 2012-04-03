$NetBSD$

Avoid conflict with C++ list<>.

--- cli/cmd_list.cc.orig	2005-05-11 13:29:01.000000000 +0000
+++ cli/cmd_list.cc
@@ -76,7 +76,7 @@ void cmd_list::list(void)
   if(!have_cpu(1))
     return;
 
-  GetActiveCPU()->list(file_id,GetActiveCPU()->pc->value,starting_line,ending_line);
+  GetActiveCPU()->plist(file_id,GetActiveCPU()->pc->value,starting_line,ending_line);
 
 }
 void cmd_list::list(cmd_options *opt)
