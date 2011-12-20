$NetBSD$

Add missing header.

--- src/UnitTests/BDBPerformanceProfile.cpp.orig	2006-10-18 06:04:35.000000000 +0000
+++ src/UnitTests/BDBPerformanceProfile.cpp
@@ -29,6 +29,7 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 #include "BDBPerformanceProfile.h"
+#include <stdlib.h>
 
 BDBPerformanceProfile::BDBPerformanceProfile()
 {
