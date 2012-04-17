$NetBSD$

--- src/uipp/tutor/Main.C.orig	2000-05-16 18:53:15.000000000 +0000
+++ src/uipp/tutor/Main.C
@@ -31,8 +31,7 @@ extern "C" void HCLXmInit();
 //
 const char *AssertMsgString = "Internal error detected at \"%s\":%d.\n";
  
-int main(unsigned int argc,
-	  char**       argv)
+int main(int argc, char **argv)
 {
 #if defined(HAVE_HCLXMINIT)
     HCLXmInit();
