$NetBSD$

--- tstfind.c.orig	2013-01-11 01:31:35.000000000 +0000
+++ tstfind.c
@@ -57,7 +57,7 @@ void PrintSerialNum(int);
 //----------------------------------------------------------------------
 //  Main for tstfind
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    int rslt,cnt;
    char return_msg[128];
