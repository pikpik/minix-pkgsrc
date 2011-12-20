$NetBSD$

Add missing header.

--- src/Operators/SColumnExtracter.cpp.orig	2006-08-22 22:31:39.000000000 +0000
+++ src/Operators/SColumnExtracter.cpp
@@ -29,6 +29,7 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 #include "SColumnExtracter.h"
+#include <stdlib.h>
 
 SColumnExtracter::SColumnExtracter(string fileName, int c_index, int stringSize_, bool FORCE_REBUILD)
 {
