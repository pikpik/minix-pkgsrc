$NetBSD$

--- src/core/raster/qgsrasterlayer.h.orig	2012-12-25 15:27:06.000000000 +0000
+++ src/core/raster/qgsrasterlayer.h
@@ -693,7 +693,7 @@ class CORE_EXPORT QgsRasterLayer : publi
     bool writeSymbology( QDomNode&, QDomDocument& doc, QString& errorMessage ) const;
 
     /** \brief Write layer specific state to project file Dom node */
-    bool writeXml( QDomNode & layer_node, QDomDocument & doc );
+    bool writeXml( QDomNode & layer_node, QDomDocument & doc ) const;
 
   private:
     //
