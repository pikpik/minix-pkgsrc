$NetBSD$

--- lib/e2p/ostype.c.orig	Tue May 18 03:04:39 2010
+++ lib/e2p/ostype.c
@@ -19,6 +19,7 @@ static const char *os_tab[] =
 	  "Masix",
 	  "FreeBSD",
 	  "Lites",
+	  "Minix",
 	  0 };
 
 /*
@@ -29,7 +30,7 @@ char *e2p_os2string(int os_type)
         const char	*os;
 	char 		*ret;
 
-	if (os_type <= EXT2_OS_LITES)
+	if (os_type <= EXT2_OS_MINIX)
 		os = os_tab[os_type];
 	else
 		os = "(unknown os)";
