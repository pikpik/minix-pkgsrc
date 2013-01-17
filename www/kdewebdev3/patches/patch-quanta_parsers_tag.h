$NetBSD$

--- quanta/parsers/tag.h.orig	2005-09-10 08:22:52.000000000 +0000
+++ quanta/parsers/tag.h
@@ -88,6 +88,8 @@ public:
   void addAttribute(TagAttr attr) {attrs.append(attr);}
   /** Get the attribute number index */
   TagAttr getAttribute(uint index) const {return attrs[index];}
+  /** Get the attribute number index */
+  TagAttr &getAttributeWriteable(uint index) {return attrs[index];}
   /** Remove the attribute number index */
   void deleteAttribute(uint index) {attrs.remove(attrs.at(index));}
   /** Insert a new Attribute, even if it already exists. Prefer using editAttribute.
