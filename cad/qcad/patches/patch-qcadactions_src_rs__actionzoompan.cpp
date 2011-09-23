$NetBSD$

--- qcadactions/src/rs_actionzoompan.cpp.orig	2005-11-22 11:51:46.000000000 +0000
+++ qcadactions/src/rs_actionzoompan.cpp
@@ -28,6 +28,7 @@
 #include "rs_snapper.h"
 #include "rs_point.h"
 
+#include <cstdlib>
 
 RS_ActionZoomPan::RS_ActionZoomPan(RS_EntityContainer& container,
                                    RS_GraphicView& graphicView)
