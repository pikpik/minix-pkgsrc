$NetBSD$

--- wml_backend/p3_eperl/eperl_perl5.c.orig	2013-03-01 14:59:14.000000000 +0000
+++ wml_backend/p3_eperl/eperl_perl5.c
@@ -212,7 +212,7 @@ int Perl5_Run(int myargc, char **myargv,
             IO_restore_stdout();
             IO_restore_stderr();
             if ((cpBuf = ePerl_ReadErrorFile(perlstderr, perlscript, source)) != NULL) {
-                fprintf(stderr, cpBuf);
+                fprintf(stderr, "%s", cpBuf);
             }
             CU(EX_FAIL);
         }
