$NetBSD$

--- lib/python/mechanize/_firefox3cookiejar.py.orig	2011-02-04 21:45:35.000000000 +0000
+++ lib/python/mechanize/_firefox3cookiejar.py
@@ -89,8 +89,9 @@ class Firefox3CookieJar(CookieJar):
             cur.execute(query, params)
             for row in cur.fetchall():
                 yield row
-        finally:
+        except:
             cur.close()
+            raise
 
     def _create_table_if_necessary(self):
         self._execute("""\
