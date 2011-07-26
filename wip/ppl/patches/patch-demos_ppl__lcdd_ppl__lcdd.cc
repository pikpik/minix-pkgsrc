$NetBSD$

--- demos/ppl_lcdd/ppl_lcdd.cc.orig	Tue Jul 26 11:36:08 2011
+++ demos/ppl_lcdd/ppl_lcdd.cc
@@ -106,7 +106,7 @@ typedef Polyhedron* POLYHEDRON_TYPE;
 #include <sstream>
 #include <stdexcept>
 
-#ifdef PPL_HAVE_GETOPT_H
+#if PPL_HAVE_GETOPT_H == 1
 #include <getopt.h>
 
 // Try to accommodate non-GNU implementations of `getopt()'.
@@ -124,30 +124,31 @@ typedef Polyhedron* POLYHEDRON_TYPE;
 
 #endif // defined(PPL_HAVE_GETOPT_H)
 
-#ifdef PPL_HAVE_UNISTD_H
+#if PPL_HAVE_UNISTD_H == 1
 // Include this for `getopt()': especially important if we do not have
 // <getopt.h>.
 # include <unistd.h>
 #endif
 
-#ifdef PPL_HAVE_SYS_TIME_H
+#if PPL_HAVE_SYS_TIME_H == 1
 # include <sys/time.h>
 #endif
 
-#ifdef PPL_HAVE_SYS_RESOURCE_H
+#if PPL_HAVE_SYS_RESOURCE_H == 1
 // This should be included after <time.h> and <sys/time.h> so as to make
 // sure we have the definitions for, e.g., `ru_utime'.
 # include <sys/resource.h>
 #endif
 
-#if defined(PPL_HAVE_SYS_RESOURCE_H) \
+#if PPL_HAVE_SYS_RESOURCE_H == 1 \
+  && HAVE_DECL_SETRLIMIT == 1 \
   && (defined(SA_ONESHOT) || defined(SA_RESETHAND))
 # define PPL_LCDD_SUPPORTS_LIMIT_ON_CPU_TIME
 #endif
 
 namespace {
 
-#ifdef PPL_HAVE_GETOPT_H
+#if PPL_HAVE_GETOPT_H == 1
 struct option long_options[] = {
   {"max-cpu",        required_argument, 0, 'C'},
   {"max-memory",     required_argument, 0, 'R'},
@@ -181,7 +182,7 @@ static const char* usage_string
 "  -V, --version           prints version information to stdout\n"
 "  -cPATH, --check=PATH    checks if the result is equal to what is in PATH\n"
 #endif
-#ifndef PPL_HAVE_GETOPT_H
+#if PPL_HAVE_GETOPT_H == 1
 "\n"
 "NOTE: this version does not support long options.\n"
 #endif
@@ -331,8 +332,8 @@ set_alarm_on_cpu_time(const unsigned seconds, sig_hand
 
 #endif // PPL_LCDD_SUPPORTS_LIMIT_ON_CPU_TIME
 
-#if PPL_HAVE_DECL_RLIMIT_AS
-
+#if PPL_HAVE_DECL_RLIMIT_AS == 1 \
+  && HAVE_DECL_SETRLIMIT == 1
 void
 limit_virtual_memory(const unsigned long bytes) {
   struct rlimit t;
@@ -378,7 +379,7 @@ timeout(int) {
 void
 process_options(int argc, char* argv[]) {
   while (true) {
-#ifdef PPL_HAVE_GETOPT_H
+#if PPL_HAVE_GETOPT_H == 1
     int option_index = 0;
     int c = getopt_long(argc, argv, OPTION_LETTERS, long_options,
 			&option_index);
