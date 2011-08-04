$NetBSD$

--- awk/proto.h.orig	2011-08-03 11:53:03.000000000 +0000
+++ awk/proto.h
@@ -131,7 +131,7 @@ extern	Cell	*call(Node **, int);
 extern	Cell	*copycell(Cell *);
 extern	Cell	*arg(Node **, int);
 extern	Cell	*jump(Node **, int);
-extern	Cell	*getline(Node **, int);
+extern	Cell	*my_getline(Node **, int);
 extern	Cell	*getnf(Node **, int);
 extern	Cell	*array(Node **, int);
 extern	Cell	*awkdelete(Node **, int);
