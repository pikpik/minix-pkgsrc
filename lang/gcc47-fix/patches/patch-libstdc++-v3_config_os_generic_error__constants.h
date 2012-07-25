$NetBSD$

--- libstdc++-v3/config/os/generic/error_constants.h.orig	Sun Jan 30 22:39:36 2011
+++ libstdc++-v3/config/os/generic/error_constants.h
@@ -53,12 +53,16 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
 #endif
 
       broken_pipe = 				EPIPE,
+#ifdef _GLIBCXX_HAVE_ECONNABORTED
       connection_aborted = 			ECONNABORTED,
+#endif
       connection_already_in_progress = 		EALREADY,
       connection_refused = 			ECONNREFUSED,
       connection_reset = 			ECONNRESET,
       cross_device_link = 			EXDEV,
+#ifdef _GLIBCXX_HAVE_EDESTADDRREQ
       destination_address_required = 		EDESTADDRREQ,
+#endif
       device_or_resource_busy = 		EBUSY,
       directory_not_empty = 			ENOTEMPTY,
       executable_format_error = 		ENOEXEC,
@@ -81,7 +85,9 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
       is_a_directory = 				EISDIR,
       message_size = 				EMSGSIZE,
       network_down = 				ENETDOWN,
+#ifdef _GLIBCXX_HAVE_ENETRESET
       network_reset = 				ENETRESET,
+#endif
       network_unreachable = 			ENETUNREACH,
       no_buffer_space = 			ENOBUFS,
       no_child_process = 			ECHILD,
@@ -96,7 +102,9 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
       no_message_available = 			ENODATA, 
 #endif
 
+#ifdef _GLIBCXX_HAVE_ENOMSG
       no_message = 				ENOMSG, 
+#endif
       no_protocol_option = 			ENOPROTOOPT,
       no_space_on_device = 			ENOSPC,
 
