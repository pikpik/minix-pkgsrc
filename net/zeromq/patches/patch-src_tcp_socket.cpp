$NetBSD$

--- src/tcp_socket.cpp.orig	2011-11-30 20:00:24.000000000 +0000
+++ src/tcp_socket.cpp
@@ -162,7 +162,8 @@ int zmq::tcp_socket_t::open (fd_t fd_, u
         errno_assert (rc == 0);
     }
 
-#if defined ZMQ_HAVE_OSX || defined ZMQ_HAVE_FREEBSD
+#if defined(ZMQ_HAVE_OSX) || \
+   (defined(ZMQ_HAVE_FREEBSD) && !defined(ZMQ_DRAGONFLY))
     int set = 1;
     int rc = setsockopt (s, SOL_SOCKET, SO_NOSIGPIPE, &set, sizeof (int));
     errno_assert (rc == 0);
