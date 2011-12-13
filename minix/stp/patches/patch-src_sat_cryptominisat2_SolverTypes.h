$NetBSD$

--- src/sat/cryptominisat2/SolverTypes.h.orig	Tue Dec 13 02:40:22 2011
+++ src/sat/cryptominisat2/SolverTypes.h
@@ -32,6 +32,10 @@ OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OT
 #include "Alg.h"
 #include <stdio.h>
 
+#ifdef getchar
+#undef getchar
+#endif
+
 namespace MINISAT
 {
 using namespace MINISAT;
