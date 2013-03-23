$NetBSD$

--- krita/plugins/viewplugins/scripting/kritacore/krs_iterator.h.orig	2013-02-28 16:16:06.000000000 +0000
+++ krita/plugins/viewplugins/scripting/kritacore/krs_iterator.h
@@ -136,12 +136,12 @@ class Iterator : public Kross::Api::Clas
             }
             initiales = initiales.upper();
             // set/get general
-            addFunction("set" + initiales, &Iterator::setPixel);
-            addFunction("get" + initiales, &Iterator::getPixel);
+            this->addFunction("set" + initiales, &Iterator::setPixel);
+            this->addFunction("get" + initiales, &Iterator::getPixel);
             kdDebug(41011) << ( "get" + initiales ) << endl;
             // Various colorSpace
-            addFunction("invertColor", &Iterator::invertColor);
-            addFunction("darken", &Iterator::darken);
+            this->addFunction("invertColor", &Iterator::invertColor);
+            this->addFunction("darken", &Iterator::darken);
         }
     
         ~Iterator()
