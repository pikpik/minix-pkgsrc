$NetBSD$

--- Encoder/melcode.c.orig	2012-12-20 14:15:16.000000000 +0000
+++ Encoder/melcode.c
@@ -88,7 +88,7 @@ void init_process_run(int maxrun)    /* 
 
 
 
-process_run(int runlen, int eoline, int color)
+void process_run(int runlen, int eoline, int color)
 {
 	int hits = 0;
 
