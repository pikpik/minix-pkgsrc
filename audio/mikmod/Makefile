# $NetBSD: Makefile,v 1.19 2000/01/15 18:46:23 jlam Exp $
#

DISTNAME=	mikmod-3.1.6-a
PKGNAME=	mikmod-3.1.6a
CATEGORIES=	audio
MASTER_SITES=	http://mikmod.darkorb.net/libmikmod/

MAINTAINER=	mycroft@NetBSD.ORG
HOMEPAGE=	http://mikmod.darkorb.net/

DEPENDS+=	ncurses>=4.2:../../devel/ncurses
DEPENDS+=	libmikmod>=3.1.9:../../audio/libmikmod

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
