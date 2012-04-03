$NetBSD$

--- yorick/yconfig.sh.orig	2011-12-05 19:15:23.000000000 +0000
+++ yorick/yconfig.sh
@@ -90,9 +90,10 @@ fi
 echo "NO_HYPOT=$NO_HYPOT" >>../Make.cfg
 
 cat >cfg.c <<EOF
+double val = 3.;
 int main(int argc, char *argv[])
 {
-  double x=exp10(3.);
+  double x=exp10(val);
   return (x<999.999)||(x>1000.001);
 }
 EOF
