$NetBSD$

--- speech_tools/config/rules/compile_options.mak.orig	2001-04-04 13:11:27.000000000 +0000
+++ speech_tools/config/rules/compile_options.mak
@@ -172,3 +172,6 @@ ifneq ($(STATIC),0)
     LINKFLAGS += $(STATIC_LINKFLAGS)
 endif
 
+CFLAGS		+= $(BUILDLINK_CPPFLAGS)
+CXXFLAGS	+= $(BUILDLINK_CPPFLAGS)
+LINKFLAGS	+= $(BUILDLINK_LDFLAGS)
