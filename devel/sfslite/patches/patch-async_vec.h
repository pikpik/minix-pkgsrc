$NetBSD$

--- async/vec.h.orig	2013-03-25 14:13:21.000000000 +0000
+++ async/vec.h
@@ -121,7 +121,7 @@ protected:
   static void destroy (elm_t &e) { e.~elm_t (); }
 
   void init () { lastp = firstp = basep = def_basep (); limp = def_limp (); }
-  void del () { while (firstp < lastp) firstp++->~elm_t (); bfree (basep); }
+  void del () { while (firstp < lastp) firstp++->~elm_t (); this->bfree (basep); }
 
 #define append(v)						\
 do {								\
@@ -164,7 +164,7 @@ public:
       elm_t *obasep = basep;
       move (static_cast<elm_t *> (txmalloc (nalloc * sizeof (elm_t))));
       limp = basep + nalloc;
-      bfree (obasep);
+      this->bfree (obasep);
     }
     else
       move (basep);
