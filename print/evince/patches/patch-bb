$NetBSD$

--- backend/dvi/mdvi-lib/dviread.c.orig	2010-07-14 07:54:39.000000000 +0000
+++ backend/dvi/mdvi-lib/dviread.c
@@ -1537,6 +1537,10 @@ int	special(DviContext *dvi, int opcode)
 	Int32	arg;
 	
 	arg = dugetn(dvi, opcode - DVI_XXX1 + 1);
+	if (arg <= 0) {
+		dvierr(dvi, _("malformed special length\n"));
+		return -1;
+	}
 	s = mdvi_malloc(arg + 1);
 	dread(dvi, s, arg);
 	s[arg] = 0;
