$NetBSD$

--- klee/runtime/klee-libc/htonl.c.orig	Thu Aug 11 01:14:43 2011
+++ klee/runtime/klee-libc/htonl.c
@@ -41,7 +41,7 @@ uint32_t htonl(uint32_t v) {
 
 #endif
 
-uint16_t ntohs(uint32_t v) {
+uint16_t ntohs(uint16_t v) {
   return htons(v);
 }
 uint32_t ntohl(uint32_t v) {
