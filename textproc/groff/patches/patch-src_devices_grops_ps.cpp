$NetBSD$

--- src/devices/grops/ps.cpp.orig	Mon Jul 11 11:34:43 2011
+++ src/devices/grops/ps.cpp
@@ -25,6 +25,8 @@ along with this program. If not, see <http://www.gnu.o
  *   http://partners.adobe.com/public/developer/en/ps/5001.DSC_Spec.pdf
  */
 
+#include <locale.h>
+
 #include "driver.h"
 #include "stringclass.h"
 #include "cset.h"
