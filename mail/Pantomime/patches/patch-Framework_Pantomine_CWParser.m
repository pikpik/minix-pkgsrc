$NetBSD$

--- Framework/Pantomime/CWParser.m.orig	2007-01-28 19:46:23.000000000 +0000
+++ Framework/Pantomime/CWParser.m
@@ -40,7 +40,7 @@
 //
 static char *month_name[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
 
-static struct timezone {
+static struct timezonePantomine {
   char *name;          /* time zone name */
   int offset;         /* offset, in minutes, EAST of GMT */
 } timezone_info[] = {
