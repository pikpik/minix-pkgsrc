$NetBSD$

Fix for starnge rdoc crash.

--- lib/termtter/command.rb.orig	2011-03-31 05:19:12.000000000 +0000
+++ lib/termtter/command.rb
@@ -84,7 +84,7 @@ module Termtter
       /^\s*((#{commands_regex})|(#{commands_regex})\s+(.*?))\s*$/
     end
 
-    # commands :: [Symbol]
+    # commands :: # [Symbol]
     def commands
       [name] + aliases
     end
