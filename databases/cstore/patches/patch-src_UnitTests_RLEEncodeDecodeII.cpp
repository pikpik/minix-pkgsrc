$NetBSD$

Add missing header.

--- src/UnitTests/RLEEncodeDecodeII.cpp.orig	2006-10-17 19:35:33.000000000 +0000
+++ src/UnitTests/RLEEncodeDecodeII.cpp
@@ -29,6 +29,7 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 #include "RLEEncodeDecodeII.h"
+#include <stdlib.h>
 
 RLEEncodeDecodeII::RLEEncodeDecodeII()
 {}
