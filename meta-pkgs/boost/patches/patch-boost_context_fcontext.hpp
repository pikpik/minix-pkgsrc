$NetBSD$

# add support for SPARC

--- boost/context/fcontext.hpp.orig	2012-10-31 11:07:06.000000000 +0100
+++ boost/context/fcontext.hpp	2012-10-31 13:31:48.000000000 +0100
@@ -55,6 +55,9 @@
     || defined(__ppc__) || defined(_ARCH_PPC) || defined(__POWERPC__) \
     || defined(__PPCGECKO__) || defined(__PPCBROADWAY) || defined(_XENON)
 # include <boost/context/detail/fcontext_ppc.hpp>
+#elif defined(__sparc__)
+// sparc or sparc64
+# include <boost/context/detail/fcontext_sparc.hpp>
 #else
 # error "platform not supported"
 #endif
