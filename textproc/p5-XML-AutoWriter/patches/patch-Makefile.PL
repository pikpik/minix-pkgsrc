$NetBSD$

Fix build with perl-5.16.

--- Makefile.PL.orig	2009-06-11 18:26:48.000000000 +0000
+++ Makefile.PL
@@ -9,7 +9,6 @@ requires => 'XML::Parser';
 build_requires => 'Test';
 build_requires => 'IO::File';
 
-auto_set_repository;
 auto_manifest;
 auto_install;
 WriteAll;
