# $NetBSD: Makefile,v 1.20 2008/05/25 21:42:20 joerg Exp $
#

DISTNAME=	FunTimeDancer-0.1
PKGNAME=	xmms-funtimedancer-0.1
PKGREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ftd/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} FunTimeDancer-packs-1.0.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/ftd/
COMMENT=	XMMS plugin displaying an animation

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pax

INSTALLATION_DIRS=	lib/xmms/Visualization

post-install:
	cd ${WRKDIR} && \
		pax -rw -pp FunTimeDancer ${DESTDIR}${PREFIX}/lib/xmms/Visualization

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
