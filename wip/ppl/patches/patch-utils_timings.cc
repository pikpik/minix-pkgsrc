$NetBSD$

--- utils/timings.cc.orig	Sun Feb 27 09:07:47 2011
+++ utils/timings.cc
@@ -32,11 +32,11 @@ site: http://www.cs.unipr.it/ppl/ . */
 #include <cerrno>
 #include <cstdlib>
 
-#ifdef PPL_HAVE_SYS_TIME_H
+#if PPL_HAVE_SYS_TIME_H == 1
 # include <sys/time.h>
 #endif
 
-#ifdef PPL_HAVE_SYS_RESOURCE_H
+#if PPL_HAVE_SYS_RESOURCE_H == 1
 // This should be included after <time.h> and <sys/time.h> so as to make
 // sure we have the definitions for, e.g., `ru_utime'.
 # include <sys/resource.h>
@@ -44,14 +44,14 @@ site: http://www.cs.unipr.it/ppl/ . */
 
 using namespace std;
 
-#ifdef PPL_HAVE_TIMEVAL
+#if PPL_HAVE_TIMEVAL == 1
 // To save the time when start_clock is called.
 static struct timeval saved_ru_utime;
 #endif
 
 void
 start_clock() {
-#if defined(PPL_HAVE_DECL_GETRUSAGE) && defined(PPL_HAVE_TIMEVAL)
+#if PPL_HAVE_DECL_GETRUSAGE == 1 && PPL_HAVE_TIMEVAL == 1
   struct rusage rsg;
   if (getrusage(RUSAGE_SELF, &rsg) != 0) {
     cerr << "getrusage failed: " << strerror(errno) << endl;
@@ -64,7 +64,7 @@ start_clock() {
 
 void
 print_clock(ostream& s) {
-#if defined(PPL_HAVE_DECL_GETRUSAGE) && defined(PPL_HAVE_TIMEVAL)
+#if PPL_HAVE_DECL_GETRUSAGE == 1 && PPL_HAVE_TIMEVAL == 1
   struct rusage rsg;
   if (getrusage(RUSAGE_SELF, &rsg) != 0) {
     cerr << "getrusage failed: " << strerror(errno) << endl;
