# $NetBSD: Makefile,v 1.9 2003/07/17 21:45:16 grant Exp $
#

PKGNAME=	python22-pth-2.2.3

PTHREAD_OPTS=	require
.include "../../mk/pthread.buildlink2.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p2

.include "../../lang/python22/Makefile.common"
