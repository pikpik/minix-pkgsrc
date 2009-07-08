# $NetBSD: Makefile,v 1.13 2008/01/22 13:36:30 obache Exp $
#

DISTNAME=	oto-0.4
PKGREVISION=	4
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=oto/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/oto/
COMMENT=	List and modify OpenType font files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	share/doc/oto

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/oto

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
