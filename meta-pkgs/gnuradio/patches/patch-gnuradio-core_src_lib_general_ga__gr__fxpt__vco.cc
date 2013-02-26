$NetBSD$

Avoid 'error: call of overloaded <x> is ambiguous' failures.

--- gnuradio-core/src/lib/general/qa_gr_fxpt_vco.cc.orig	2010-06-02 00:57:52.000000000 +0000
+++ gnuradio-core/src/lib/general/qa_gr_fxpt_vco.cc
@@ -53,7 +53,7 @@ qa_gr_fxpt_vco::t0 ()
   float			input[SIN_COS_BLOCK_SIZE];
 
   for (int i = 0; i < SIN_COS_BLOCK_SIZE; i++){
-	  input[i] = sin(i);
+	  input[i] = sin((float)i);
   }
 
   for (int i = 0; i < SIN_COS_BLOCK_SIZE; i++){
@@ -85,7 +85,7 @@ qa_gr_fxpt_vco::t1 ()
   double max_error = 0;
 
   for (int i = 0; i < SIN_COS_BLOCK_SIZE; i++){
-	  input[i] = sin(i);
+	  input[i] = sin((float)i);
   }
 
   ref_vco.cos (ref_block, input, SIN_COS_BLOCK_SIZE, SIN_COS_K, SIN_COS_AMPL);
