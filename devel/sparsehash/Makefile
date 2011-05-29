# $NetBSD: Makefile,v 1.7 2009/03/17 21:40:45 darcy Exp $
#

DISTNAME=		sparsehash-1.10
CATEGORIES=		devel
MASTER_SITES=		http://google-sparsehash.googlecode.com/files/

MAINTAINER=		vle@gmx.net
HOMEPAGE=		http://goog-sparsehash.sourceforge.net/
COMMENT=		Several hash-map implementations in use at Google
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALL_MAKE_FLAGS=	docdir=${PREFIX}/share/doc/sparsehash

.include "../../mk/bsd.pkg.mk"
