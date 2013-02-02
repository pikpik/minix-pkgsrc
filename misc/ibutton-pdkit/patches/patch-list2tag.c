$NetBSD$

--- list2tag.c.orig	2013-01-11 01:31:14.000000000 +0000
+++ list2tag.c
@@ -59,7 +59,7 @@ int ParseData(char *, int, uchar *, int)
 //----------------------------------------------------------------------
 //  This is the Main routine for list2tag.
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    int fllen,buflen,i,j,mcnt,ln;
    FILE *infp,*outfp;
