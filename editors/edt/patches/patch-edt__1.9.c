$NetBSD$

Typo in call to 'less'

--- edt_1.9.c.orig	2012-01-01 12:24:03.000000000 +0000
+++ edt_1.9.c
@@ -4064,7 +4064,7 @@ void help_long()
  fprintf(fz,"\n");
 
  fclose(fz);
- sprintf(tcline,"lrss %s",tname);
+ sprintf(tcline,"less %s",tname);
  system(tcline);
  remove(tname);
 }
