$NetBSD$

--- collects/racket/draw/unsafe/png.rkt.orig	2011-04-30 03:47:34.000000000 +0000
+++ collects/racket/draw/unsafe/png.rkt
@@ -14,7 +14,7 @@
    ;; variants often have just "libpng":
    (with-handlers ([exn:fail:filesystem?
                     (lambda (exn) (ffi-lib "libpng"))])
-     (ffi-lib "libpng12" '("0" "")))]
+     (ffi-lib "libpng15" '("0" "")))]
   [(macosx) (ffi-lib "libpng14.14.dylib")]
   [(windows) 
    (ffi-lib "zlib1.dll")
