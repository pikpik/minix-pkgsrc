$NetBSD$

Add missing header.

--- src/UnitTests/MergeTest.cpp.orig	2006-10-17 19:35:33.000000000 +0000
+++ src/UnitTests/MergeTest.cpp
@@ -29,6 +29,7 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 #include "MergeTest.h"
+#include <stdlib.h>
 
 MergeTest::MergeTest() {}
 
