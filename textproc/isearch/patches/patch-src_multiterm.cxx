$NetBSD$

Chase after the C++ standard:
   - use "std" qualification

--- src/multiterm.cxx~	1999-03-26 00:27:22.000000000 +0000
+++ src/multiterm.cxx
@@ -394,8 +394,8 @@ PIRSET INDEX::MultiTermSearch(const STRI
 	  Disk=0;
 	} else {
 	  // field file not found - return an empty irset
-	  cerr << "Field " << FieldName << " not present in this index." 
-	       << endl;
+	  std::cerr << "Field " << FieldName << " not present in this index." 
+	       << std::endl;
 	  return pirset;
 	}
       }
