# $NetBSD: Makefile,v 1.7 1999/04/15 20:39:49 tron Exp $
#

DISTNAME=	sunclock-1.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	perry@netbsd.org

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CPPFLAGS=-DUSE_PUTENV
.endif

.include "../../mk/bsd.pkg.mk"
