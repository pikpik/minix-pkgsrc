$NetBSD$

--- gas/app.c.orig	Thu Mar 25 21:12:28 2010
+++ gas/app.c
@@ -581,7 +581,8 @@ do_scrub_chars (int (*get) (char *, int), char *tostar
 	      state = old_state;
 	      from = fromend = one_char_buf + 1;
 	      fromlen = 1;
-	      UNGET ('\n');
+          if (from > input_buffer)
+	        UNGET ('\n');
 	      PUT (quotechar);
 	    }
 	  else if (ch == quotechar)
