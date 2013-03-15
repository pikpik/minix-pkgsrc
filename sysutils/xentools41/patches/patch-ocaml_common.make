$NetBSD$

--- ocaml/common.make.orig	2013-03-13 09:31:47.000000000 +0000
+++ ocaml/common.make
@@ -3,7 +3,7 @@ include $(XEN_ROOT)/tools/Rules.mk
 CC ?= gcc
 OCAMLOPT ?= ocamlopt
 OCAMLC ?= ocamlc
-OCAMLMKLIB ?= ocamlmklib
+OCAMLMKLIB ?= ocamlmklib -elfmode
 OCAMLDEP ?= ocamldep
 OCAMLLEX ?= ocamllex
 OCAMLYACC ?= ocamlyacc
