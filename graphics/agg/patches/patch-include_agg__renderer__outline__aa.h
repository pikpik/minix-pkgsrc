$NetBSD$

Fix build with clang-3.1 (avoiding unconst by removing unused function).

--- include/agg_renderer_outline_aa.h.orig	2006-10-09 04:07:08.000000000 +0000
+++ include/agg_renderer_outline_aa.h
@@ -1375,7 +1375,6 @@ namespace agg
         //---------------------------------------------------------------------
         void profile(const line_profile_aa& prof) { m_profile = &prof; }
         const line_profile_aa& profile() const { return *m_profile; }
-        line_profile_aa& profile() { return *m_profile; }
 
         //---------------------------------------------------------------------
         int subpixel_width() const { return m_profile->subpixel_width(); }
