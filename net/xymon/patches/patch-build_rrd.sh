$NetBSD$

make it possible to deal with nonstandard locations of libpng* and libz*

--- build/rrd.sh.orig	2012-07-31 13:51:12.000000000 +0000
+++ build/rrd.sh
@@ -70,6 +70,12 @@
 	if test "$USERRRDLIB" != ""; then
 		RRDLIB="$USERRRDLIB"
 	fi
+	if test "$USERPNGCONFIG" != ""; then
+		PNGLIB=`$USERPNGCONFIG --ldflags`
+	fi
+	if test "$USERZLIB" != ""; then
+		ZLIB="$USERZLIB"
+	fi
 
 	# See if it builds
 	RRDOK="YES"
