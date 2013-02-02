$NetBSD$

Chase after the C++ standard:
   - string constants are const char *

--- doctype/colondoc.hxx~	1996-07-10 18:54:08.000000000 +0000
+++ doctype/colondoc.hxx
@@ -24,7 +24,7 @@ public:
 		PSTRING StringBuffer);
 	~COLONDOC();
 // hooks into the guts of the field parser
-	virtual PCHR UnifiedName (PCHR tag) const; // for children to play with
+	virtual PKCHR UnifiedName (PKCHR tag) const; // for children to play with
 };
 typedef COLONDOC* PCOLONDOC;
 
