# $NetBSD: Makefile,v 1.19 2007/01/07 09:14:01 rillig Exp $

DISTNAME=		jive-1.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE:=games/amusements/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Filter that converts English text to Jive

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/jive
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

USE_TOOLS+=		flex

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jive ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jive.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
