$NetBSD$

Chase after the C++ standard:
   - use "std" qualification

--- doctype/doctype.cxx~	2000-02-04 22:50:08.000000000 +0000
+++ doctype/doctype.cxx
@@ -102,7 +102,7 @@ DOCTYPE::ParseWords(
 	(!(Db->IsStopWord(DataBuffer + Position,
 			  DataLength - Position))) ) {
       if (GpListSize >= GpLength) {
-         cout << "GpListSize >= GpLength" << endl;
+         std::cout << "GpListSize >= GpLength" << std::endl;
          exit(1);
       }
       GpBuffer[GpListSize++] = DataOffset + Position;
