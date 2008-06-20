# $NetBSD: Makefile,v 1.17 2008/05/25 14:45:17 tron Exp $

DISTNAME=	buffer-1.17
CATEGORIES=	misc
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Buffer sporadic binary I/O for faster tape use

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-DSYS5
MAKE_ENV+=	CC=${CC:Q}
.endif

.include "../../mk/bsd.pkg.mk"
