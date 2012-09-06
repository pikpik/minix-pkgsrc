$NetBSD$

Honor PKGMANDIR.

--- setup.py.orig	2012-07-29 20:13:12.000000000 +0000
+++ setup.py
@@ -340,12 +340,12 @@ setup(
     packages=['virtinst', 'virtconv', 'virtconv.parsers'],
 
     data_files=[
-        ('share/man/man1', [
+        ('@@PKGMANDIR@@/man1', [
             'man/en/virt-install.1',
             'man/en/virt-clone.1',
             'man/en/virt-image.1',
             'man/en/virt-convert.1']),
-        ('share/man/man5', [
+        ('@@PKGMANDIR@@/man5', [
             'man/en/virt-image.5']),
     ] + _build_lang_data(),
 
