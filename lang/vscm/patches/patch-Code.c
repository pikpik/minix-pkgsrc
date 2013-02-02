$NetBSD$

--- Code.c.orig	2012-11-19 01:59:02.000000000 +0000
+++ Code.c
@@ -659,7 +659,7 @@ long ScmTimer (long units)
  * The VSCM virtual machine:
  */
 
-void ScmVM (void)
+void NORETURN ScmVM (void) NRUTERON
 {
   register const unsigned short *cp;
   unsigned int cp_save;
