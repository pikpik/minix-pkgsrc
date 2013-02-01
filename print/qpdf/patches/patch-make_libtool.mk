$NetBSD$

Sent upstream, will be fixed in 4.1.0.

--- make/libtool.mk.orig	2013-01-17 14:51:04.000000000 +0000
+++ make/libtool.mk
@@ -116,7 +116,6 @@ install: all
 		libqpdf/$(OUTPUT_DIR)/libqpdf.la \
 		$(DESTDIR)$(libdir)/libqpdf.la
 	$(LIBTOOL) --finish $(DESTDIR)$(libdir)
-	$(RM) $(DESTDIR)$(libdir)/libqpdf.la
 	$(LIBTOOL) --mode=install install -c \
 		qpdf/$(OUTPUT_DIR)/qpdf \
 		$(DESTDIR)$(bindir)/qpdf
