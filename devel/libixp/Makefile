# $NetBSD: Makefile,v 1.2 2009/06/15 12:42:27 ghen Exp $

DISTNAME=		libixp-0.5
CATEGORIES=		devel
MASTER_SITES=		http://code.suckless.org/dl/libs/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://libs.suckless.org/libixp
COMMENT=		Stand-alone client/server 9P library
#LICENSE=		mit AND lpl (plan 9 license)

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}

USE_TOOLS+=		gmake

.include "../../mk/bsd.pkg.mk"
