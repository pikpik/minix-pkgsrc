$NetBSD$

--- src/preproc/preconv/preconv.cpp.orig	Fri Jan  9 14:25:52 2009
+++ src/preproc/preconv/preconv.cpp
@@ -18,6 +18,8 @@ for more details.
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>. */
 
+#include <locale.h>
+
 #include "lib.h"
 
 #include <assert.h>
@@ -28,8 +30,6 @@ along with this program. If not, see <http://www.gnu.o
 #include "localcharset.h"
 #include "nonposix.h"
 #include "stringclass.h"
-
-#include <locale.h>
 
 #if HAVE_ICONV
 # include <iconv.h>
