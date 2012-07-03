$NetBSD$

--- src/include/fst/difference.h.orig	2012-07-03 09:58:16.000000000 +0000
+++ src/include/fst/difference.h
@@ -95,7 +95,7 @@ class DifferenceFst : public ComposeFst<
     copts.matcher2 = new R(cfst, MATCH_INPUT, ComplementFst<A>::kRhoLabel,
                            opts.matcher2);
 
-    SetImpl(Init(fst1, cfst, copts));
+    this->SetImpl(this->Init(fst1, cfst, copts));
 
     uint64 props1 = fst1.Properties(kFstProperties, false);
     uint64 props2 = fst2.Properties(kFstProperties, false);
