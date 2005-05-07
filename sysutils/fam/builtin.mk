# $NetBSD: builtin.mk,v 1.2 2004/04/20 08:43:33 xtraeme Exp $

.if !defined(IS_BUILTIN.fam)
IS_BUILTIN.fam=	no
.  if exists(/usr/include/fam.h)
IS_BUILTIN.fam=	yes
.  endif
.endif	# IS_BUILTIN.fam

USE_BUILTIN.fam?=	${IS_BUILTIN.fam}
