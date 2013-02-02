$NetBSD$

--- renderers/agg/include/agg_renderer_outline_aa.h.orig	2009-05-01 07:06:05.000000000 +0000
+++ renderers/agg/include/agg_renderer_outline_aa.h
@@ -1365,7 +1365,6 @@ namespace mapserver
         //---------------------------------------------------------------------
         void profile(const line_profile_aa& prof) { m_profile = &prof; }
         const line_profile_aa& profile() const { return *m_profile; }
-        line_profile_aa& profile() { return *m_profile; }
 
         //---------------------------------------------------------------------
         int subpixel_width() const { return m_profile->subpixel_width(); }
