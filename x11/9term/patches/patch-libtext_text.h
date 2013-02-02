$NetBSD$

--- libtext/text.h.orig	2012-04-28 21:27:52.000000000 +0000
+++ libtext/text.h
@@ -87,5 +87,6 @@ ulong			_backnl(Text *, long, ulong);
 
 ulong			texttoutf(char *, Rune *, Rune *);
 ulong			utftotext(Rune *, char *, char *);
+int			alnum(int);
 
 #endif
