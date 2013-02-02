$NetBSD$

--- rib/rt_tab_merged.cc.orig	2009-01-05 18:31:07.000000000 +0000
+++ rib/rt_tab_merged.cc
@@ -194,7 +194,7 @@ MergedTable<A>::replumb(RouteTable<A>* o
     } else {
 	XLOG_UNREACHABLE();
     }
-    set_tablename(make_merged_name(_table_a, _table_b));
+    this->set_tablename(make_merged_name(_table_a, _table_b));
     debug_msg("MergedTable: now called \"%s\"\n", this->tablename().c_str());
 }
 
