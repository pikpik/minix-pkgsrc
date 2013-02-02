$NetBSD$

--- toolkit/source/awt/vclxscroller.cxx.orig	2012-06-23 18:22:34.000000000 +0000
+++ toolkit/source/awt/vclxscroller.cxx
@@ -75,7 +75,7 @@ void SAL_CALL VCLXScroller::dispose() th
         ::vos::OGuard aGuard( GetMutex() );
 
         EventObject aDisposeEvent;
-        aDisposeEvent.Source = W3K_EXPLICIT_CAST (*this);
+        aDisposeEvent.Source = W3K_EXPLICIT_CAST (*(VCLXDevice *)this);
 //            maTabListeners.disposeAndClear( aDisposeEvent );
     }
 
