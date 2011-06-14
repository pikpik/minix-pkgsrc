$NetBSD$

--- extern.h.orig	1994-09-24 02:55:52.000000000 +0000
+++ extern.h
@@ -49,3 +49,6 @@ void	 printcol __P((DISPLAY *));
 void	 printlong __P((DISPLAY *));
 void	 printscol __P((DISPLAY *));
 void	 usage __P((void));
+
+void	 parsecolors(char *);
+int	 colortype(mode_t);
