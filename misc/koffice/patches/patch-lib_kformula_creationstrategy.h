$NetBSD$

--- lib/kformula/creationstrategy.h.orig	2013-02-28 15:33:21.000000000 +0000
+++ lib/kformula/creationstrategy.h
@@ -86,7 +86,7 @@ public:
  */
 class OrdinaryCreationStrategy : public ElementCreationStrategy {
 public:
-    virtual BasicElement* createElement( QString type, const QDomElement& element = 0 );
+    virtual BasicElement* createElement( QString type, const QDomElement& element);
 
     virtual TextElement* createTextElement( const QChar& ch, bool symbol=false );
     virtual EmptyElement* createEmptyElement();
