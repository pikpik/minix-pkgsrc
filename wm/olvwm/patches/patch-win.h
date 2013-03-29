$NetBSD$

--- win.h.orig	2013-03-28 19:19:40.000000000 +0000
+++ win.h
@@ -573,4 +573,9 @@ extern int  ShapeErrorBase;
 
 extern Client *CurrentClient;
 
+void AddSelection(Client *cli, Time timestamp);
+void GFrameEventButtonRelease(Display *dpy, XEvent *event, WinGenericFrame *frameInfo);
+void GFrameEventMotionNotify(Display *dpy, XEvent *event, WinGenericFrame *frameInfo);
+void NoFocusEventBeep(Display *dpy, XEvent *event, WinGeneric *winInfo);
+
 #endif /* _OLWM_WIN_H */
