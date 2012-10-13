$NetBSD$

r511 | vouillon | 2012-09-17 16:09:03 +0200 (Mon, 17 Sep 2012) | 3 lines

* Use hash function from OCaml 3.x for comparing archives, even when
  compiled with OCaml 4.x

--- fspath.ml.orig	2010-04-15 17:29:31.000000000 +0000
+++ fspath.ml
@@ -335,4 +335,3 @@ let findWorkingDir fspath path =
 
 let quotes (Fspath f) = Uutil.quotes f
 let compare (Fspath f1) (Fspath f2) = compare f1 f2
-let hash (Fspath f) = Hashtbl.hash f
