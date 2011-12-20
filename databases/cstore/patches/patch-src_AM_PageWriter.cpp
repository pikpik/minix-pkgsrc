$NetBSD$

Add missing header.

--- src/AM/PageWriter.cpp.orig	2006-09-07 23:41:23.000000000 +0000
+++ src/AM/PageWriter.cpp
@@ -29,6 +29,7 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 #include <iostream>
+#include <stdlib.h>
 #include <fstream>
 #include <sstream>
 #include <string>
