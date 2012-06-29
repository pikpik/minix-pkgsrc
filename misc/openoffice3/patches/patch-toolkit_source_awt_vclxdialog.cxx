$NetBSD$

--- toolkit/source/awt/vclxdialog.cxx.orig	2012-06-23 18:17:00.000000000 +0000
+++ toolkit/source/awt/vclxdialog.cxx
@@ -109,7 +109,7 @@ void SAL_CALL VCLXDialog::dispose() thro
         ::vos::OGuard aGuard( GetMutex() );
 
         ::com::sun::star::lang::EventObject aDisposeEvent;
-        aDisposeEvent.Source = W3K_EXPLICIT_CAST (*this);
+        aDisposeEvent.Source = W3K_EXPLICIT_CAST (*(VCLXDevice *)this);
 //            maTabListeners.disposeAndClear( aDisposeEvent );
     }
 
