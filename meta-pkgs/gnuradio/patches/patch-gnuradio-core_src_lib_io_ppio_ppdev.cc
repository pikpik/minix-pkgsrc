$NetBSD$

include <unistd.h> for close() and gcc4.7

--- gnuradio-core/src/lib/io/ppio_ppdev.cc.orig	2010-06-02 00:57:52.000000000 +0000
+++ gnuradio-core/src/lib/io/ppio_ppdev.cc
@@ -28,6 +28,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <iostream>
 #include <errno.h>
 #include <stdio.h>
