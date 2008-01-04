# $NetBSD: Makefile,v 1.15 2007/02/22 19:26:48 wiz Exp $

DISTNAME=	buffer-1.17
CATEGORIES=	misc
MASTER_SITES=	#

MAINTAINER=	tron@NetBSD.org
COMMENT=	Buffer sporadic binary I/O for faster tape use

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-DSYS5
MAKE_ENV+=	CC=${CC:Q}
.endif

.include "../../mk/bsd.pkg.mk"
