$NetBSD$

--- src/racket/sconfig.h.orig	2012-01-20 20:41:55.000000000 +0000
+++ src/racket/sconfig.h
@@ -263,6 +263,8 @@
 # define USE_IEEE_FP_PREDS
 # define POW_HANDLES_INF_CORRECTLY
 
+# define USE_DYNAMIC_FDSET_SIZE
+
 # define SIGSET_IS_SIGNAL
 
 # define USE_TM_GMTOFF_FIELD
