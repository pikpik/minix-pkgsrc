$NetBSD$

--- src/libvpsc/csolve_VPSC.h.orig	2013-03-27 22:12:45.000000000 +0000
+++ src/libvpsc/csolve_VPSC.h
@@ -11,10 +11,6 @@
 #ifndef _CSOLVE_VPSC_H_
 #define _CSOLVE_VPSC_H_
 #ifdef __cplusplus
-class vpsc::Variable;
-class vpsc::Constraint;
-class vpsc::Solver;
-class vpsc::IncSolver;
 using namespace vpsc;
 extern "C" {
 #else
