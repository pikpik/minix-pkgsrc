# $NetBSD: Makefile,v 1.26 2004/06/15 14:26:34 grant Exp $
#

PKGNAME=	python24-pth-2.4

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p4

.include "../../lang/python24/Makefile.common"
