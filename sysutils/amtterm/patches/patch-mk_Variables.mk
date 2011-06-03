$NetBSD$

* honor PKGMANDIR

--- mk/Variables.mk.orig	2008-10-30 09:29:19.000000000 +0000
+++ mk/Variables.mk
@@ -9,7 +9,7 @@ bindir	=  $(DESTDIR)$(prefix)/bin
 sbindir	=  $(DESTDIR)$(prefix)/sbin
 libdir  =  $(DESTDIR)$(prefix)/$(LIB)
 shrdir  =  $(DESTDIR)$(prefix)/share
-mandir	=  $(shrdir)/man
+mandir	=  $(DESTDIR)$(prefix)/${PKGMANDIR}
 locdir  =  $(shrdir)/locale
 appdir  =  $(shrdir)/applications
 
