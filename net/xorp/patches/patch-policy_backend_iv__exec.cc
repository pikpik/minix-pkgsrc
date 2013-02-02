$NetBSD$

--- policy/backend/iv_exec.cc.orig	2009-01-05 18:31:06.000000000 +0000
+++ policy/backend/iv_exec.cc
@@ -269,7 +269,7 @@ void 
 IvExec::visit(Store& s)
 {
     if (_stackptr < _stack)
-	xorp_throw(RuntimeError, "Stack empty on assign of " + s.var());
+	xorp_throw(RuntimeError, c_format("Stack empty on assign of %d", s.var()));
 
     const Element* arg = *_stackptr;
     _stackptr--;
