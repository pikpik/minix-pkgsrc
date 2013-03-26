$NetBSD$

--- lib/Support/Unix/Memory.inc.orig	Wed Sep 19 20:46:12 2012
+++ lib/Support/Unix/Memory.inc
@@ -146,8 +146,12 @@ Memory::protectMappedMemory(const MemoryBlock &M, unsi
 
   int Protect = getPosixProtectionFlags(Flags);
 
+#ifndef __minix
   int Result = ::mprotect(M.Address, M.Size, Protect);
   if (Result != 0)
+#else
+  errno = ENOSYS;
+#endif
     return error_code(errno, system_category());
 
   if (Flags & MF_EXEC)
