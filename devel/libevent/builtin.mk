# $NetBSD$

.if !defined(IS_BUILTIN.libevent)
IS_BUILTIN.libevent=	no
.  if exists(/usr/include/event.h)
IS_BUILTIN.libevent=	yes
.  endif
.endif	# IS_BUILTIN.libevent

USE_BUILTIN.libevent?=	${IS_BUILTIN.libevent}
