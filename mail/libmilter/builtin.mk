# $NetBSD$

.if !defined(IS_BUILTIN.libmilter)
IS_BUILTIN.libmilter=	no
.  if exists(/usr/include/libmilter) && exists (/usr/lib/libmilter.a)
IS_BUILTIN.libmilter=	yes
.  endif
.endif	# IS_BUILTIN.libmilter

USE_BUILTIN.libmilter?=	${IS_BUILTIN.libmilter}
