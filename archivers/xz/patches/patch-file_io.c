--- src/xz/file_io.c.orig	Mon Feb  4 22:28:43 2013
+++ src/xz/file_io.c	Mon Feb  4 22:29:01 2013
@@ -880,7 +880,7 @@
 	while (size > 0) {
 		const ssize_t amount = write(pair->dest_fd, buf, size);
 		if (amount == -1) {
-			if (errno == EINTR) {
+			if (errno == EINTR || errno == EAGAIN) {
 				if (user_abort)
 					return -1;
 
