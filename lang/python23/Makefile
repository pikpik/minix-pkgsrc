# $NetBSD: Makefile,v 1.23 2005/01/23 20:41:47 recht Exp $
#

PKGNAME=	python23-2.3.4
PKGREVISION=	5

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2.3

.include "../../lang/python23/Makefile.common"
