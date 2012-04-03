$NetBSD$

Add missing header.

--- src/AM/CatalogInstance.cpp.orig	2006-10-18 06:05:29.000000000 +0000
+++ src/AM/CatalogInstance.cpp
@@ -29,6 +29,7 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 #include <iostream>
+#include <stdlib.h>
 #include "CatalogInstance.h"
 #include "CatalogInstanceBDB.h"
 
