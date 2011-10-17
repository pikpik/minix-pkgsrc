$NetBSD$

Fix build with gcc-4.5.

--- src/tinygettext/po_file_reader.hpp.orig	2007-08-17 15:39:18.000000000 +0000
+++ src/tinygettext/po_file_reader.hpp
@@ -52,7 +52,7 @@ public:
   void add_token(const Token& token);  
   void tokenize_po(std::istream& in);
 
-  inline int getchar(std::istream& in) 
+  inline int pgetchar(std::istream& in) 
   {
     int c = in.get();
     if (c == '\n')
