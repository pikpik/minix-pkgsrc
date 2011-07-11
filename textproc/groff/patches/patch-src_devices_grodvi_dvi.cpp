$NetBSD$

--- src/devices/grodvi/dvi.cpp.orig	Mon Jul 11 11:36:43 2011
+++ src/devices/grodvi/dvi.cpp
@@ -19,6 +19,8 @@ for more details.
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>. */
 
+#include <locale.h>
+
 #include "driver.h"
 #include "nonposix.h"
 #include "paper.h"
