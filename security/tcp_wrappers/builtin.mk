# $NetBSD$

.if !defined(IS_BUILTIN.tcp_wrappers)
IS_BUILTIN.tcp_wrappers=	no
.  if exists(/usr/include/tcpd.h)
IS_BUILTIN.tcp_wrappers=	yes
.  endif
.endif

CHECK_BUILTIN.tcp_wrappers?=	no
.if !empty(CHECK_BUILTIN.tcp_wrappers:M[yY][eE][sS])
USE_BUILTIN.tcp_wrappers=	yes
.endif

USE_BUILTIN.tcp_wrappers?=	${IS_BUILTIN.tcp_wrappers}
