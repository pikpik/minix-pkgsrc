# $NetBSD: Makefile,v 1.2 1999/02/02 09:50:44 tron Exp $

DISTNAME=	libPropList-0.8.3
PKGNAME=	libproplist-0.8.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.windowmaker.org/pub/libs/ \
		ftp://ftp.gnome.org/pub/libPropList/

MAINTAINER=	jlam@netbsd.org

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libPropList
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libPropList

.include "../../mk/bsd.pkg.mk"
