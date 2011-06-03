$NetBSD$

--- lib/Ocsinventory/Agent/Backend/OS/Generic/Packaging/BSDpkg.pm.orig	2010-10-12 18:02:53.000000000 +0000
+++ lib/Ocsinventory/Agent/Backend/OS/Generic/Packaging/BSDpkg.pm
@@ -6,6 +6,11 @@ sub run {
   my $params = shift;
   my $inventory = $params->{inventory};
 
+  my $from = 'BSDpkg';
+  if (can_run("pkg_admin") && `pkg_admin config-var PKG_REFCOUNT_DBDIR` =~ m{^/}) {
+    $from = 'pkgsrc';
+  }
+
   foreach(`pkg_info`){
       /^(\S+)-(\d+\S*)\s+(.*)/;
       my $name = $1;
@@ -15,7 +20,8 @@ sub run {
       $inventory->addSoftware({
 	  'COMMENTS' => $comments,
 	  'NAME' => $name,
-	  'VERSION' => $version
+	  'VERSION' => $version,
+	  'FROM' => $from
       });
   }
 }
