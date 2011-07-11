$NetBSD$

--- src/preproc/pic/main.cpp.orig	Mon Jul 11 11:21:10 2011
+++ src/preproc/pic/main.cpp
@@ -18,6 +18,8 @@ for more details.
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>. */
 
+#include <locale.h>
+
 #include "pic.h"
 
 extern int yyparse();
