$NetBSD$

--- compress/main_tbuild.c.orig	2012-11-19 01:18:30.000000000 +0000
+++ compress/main_tbuild.c
@@ -25,7 +25,7 @@ char	*progname;
 int
 main(argc, argv)
 	int	argc;
-	unsigned char	*argv[];
+	char	*argv[];
 {
 	char	comp_dir[MAX_LINE_LEN];
 	int	threshold, specialwords;
