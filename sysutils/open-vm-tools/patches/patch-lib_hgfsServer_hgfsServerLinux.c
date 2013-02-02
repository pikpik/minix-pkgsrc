$NetBSD$

--- lib/hgfsServer/hgfsServerLinux.c.orig	2012-12-25 19:41:43.000000000 +0000
+++ lib/hgfsServer/hgfsServerLinux.c
@@ -544,7 +544,7 @@ HgfsServerGetOpenFlags(HgfsOpenFlags fla
 
    arraySize = ARRAYSIZE(HgfsServerOpenFlags);
 
-   if (flagsIn < 0 || flagsIn >= arraySize) {
+   if (flagsIn >= arraySize) {
       Log("HgfsServerGetOpenFlags: Invalid HgfsOpenFlags %d\n", flagsIn);
       return FALSE;
    }
