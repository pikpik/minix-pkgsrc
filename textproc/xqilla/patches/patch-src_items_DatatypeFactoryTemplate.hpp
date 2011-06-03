$NetBSD$

Fix C++ error.

--- src/items/DatatypeFactoryTemplate.hpp.orig	2011-02-23 07:08:39.000000000 +0000
+++ src/items/DatatypeFactoryTemplate.hpp
@@ -79,7 +79,7 @@ public:
   AnyAtomicType::Ptr createInstance(const XMLCh* value,
                                     const DynamicContext* context) const
   {
-    return createInstanceNoCheck(DatatypeFactoryTemplate<TYPE>::getPrimitiveTypeURI(),
+    return this->createInstanceNoCheck(DatatypeFactoryTemplate<TYPE>::getPrimitiveTypeURI(),
                                  DatatypeFactoryTemplate<TYPE>::getPrimitiveTypeName(), value, context);
   }
 
