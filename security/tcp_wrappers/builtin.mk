# $NetBSD: builtin.mk,v 1.1 2004/03/10 17:57:15 jlam Exp $

.if !defined(IS_BUILTIN.tcp_wrappers)
IS_BUILTIN.tcp_wrappers=	no
.  if exists(/usr/include/tcpd.h)
IS_BUILTIN.tcp_wrappers=	yes
.  endif
.endif	# IS_BUILTIN.tcp_wrappers

USE_BUILTIN.tcp_wrappers?=	${IS_BUILTIN.tcp_wrappers}
