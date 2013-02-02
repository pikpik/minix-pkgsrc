$NetBSD$

--- collects/racket/draw/unsafe/png.rkt.orig	2012-06-02 05:21:31.000000000 +0000
+++ collects/racket/draw/unsafe/png.rkt
@@ -10,7 +10,7 @@
   [(unix)
    ;; Most Linux distros supply "libpng12", while other Unix
    ;; variants often have just "libpng", etc.
-   (ffi-lib "libpng15" '("15" "")
+   (ffi-lib "libpng15" '("15" "0" "")
 	    #:fail (lambda ()
 		     (ffi-lib "libpng12" '("0" "")
 			      #:fail (lambda ()
