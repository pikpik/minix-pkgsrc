$NetBSD$

* Add NetBSD support

--- cmake/platform.cmake.orig	2012-11-16 23:02:42.000000000 +0000
+++ cmake/platform.cmake
@@ -23,6 +23,9 @@ if (UNIX)
     elseif (${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
         set (platform "FreeBSD")
         set (CXXFLAGS "${CXXFLAGS} -DFREEBSD")
+    elseif (${CMAKE_SYSTEM_NAME} STREQUAL "NetBSD")
+        set (platform "NetBSD")
+        set (CXXFLAGS "${CXXFLAGS} -DNETBSD")
     else ()
         string (TOLOWER ${CMAKE_SYSTEM_NAME} platform)
     endif ()
