$NetBSD$

--- winnofoc.c.orig	2013-03-28 19:46:38.000000000 +0000
+++ winnofoc.c
@@ -230,11 +230,8 @@ ScreenInfo *scrInfo;
  * NoFocusEventBeep -- beep on keyboard/mouse events for the no-focus window
  *	Also used by busy windows
  */
-int
-NoFocusEventBeep(dpy, event, winInfo)
-Display	*dpy;
-XEvent	*event;
-WinGeneric *winInfo;
+void
+NoFocusEventBeep(Display *dpy, XEvent *event, WinGeneric *winInfo)
 {
         XEvent dummy;
 
