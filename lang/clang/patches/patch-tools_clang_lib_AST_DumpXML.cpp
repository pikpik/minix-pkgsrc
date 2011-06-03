$NetBSD$

Fix LLVM bug 8765: longjmp issue on NetBSD.

--- tools/clang/lib/AST/DumpXML.cpp.orig	2011-04-22 06:32:06.000000000 +0000
+++ tools/clang/lib/AST/DumpXML.cpp
@@ -487,6 +487,8 @@ struct XMLDumper : public XMLDeclVisitor
       set("storage",
           VarDecl::getStorageClassSpecifierString(D->getStorageClass()));
     setFlag("inline", D->isInlineSpecified());
+    if (const AsmLabelAttr *ALA = D->getAttr<AsmLabelAttr>())
+      set("asmlabel", ALA->getLabel());
     // TODO: instantiation, etc.
   }
   void visitFunctionDeclChildren(FunctionDecl *D) {
