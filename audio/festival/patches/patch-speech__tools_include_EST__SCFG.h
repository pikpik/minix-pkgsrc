$NetBSD$

--- speech_tools/include/EST_SCFG.h.orig	2012-04-27 12:52:20.000000000 +0000
+++ speech_tools/include/EST_SCFG.h
@@ -85,6 +85,8 @@ class EST_bracketed_string {
     int valid(int i,int k) const { return valid_spans[i][k]; }
 
     ///
+    int operator ==(const EST_bracketed_string &a) const 
+       { return (this == &a); }
     int operator !=(const EST_bracketed_string &a) const 
        { return (!(this == &a)); }
     ///
