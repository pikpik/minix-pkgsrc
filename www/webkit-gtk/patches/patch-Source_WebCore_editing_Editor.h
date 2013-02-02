$NetBSD$

--- Source/WebCore/editing/Editor.h.orig	2012-10-16 15:22:38.000000000 +0000
+++ Source/WebCore/editing/Editor.h
@@ -398,7 +398,7 @@ public:
     Vector<String> dictationAlternativesForMarker(const DocumentMarker*);
     void applyDictationAlternativelternative(const String& alternativeString);
 private:
-    virtual void willDetachPage() OVERRIDE;
+    virtual void willDetachPage();
 
     OwnPtr<DeleteButtonController> m_deleteButtonController;
     RefPtr<CompositeEditCommand> m_lastEditCommand;
