# $NetBSD: Makefile,v 1.7 1998/06/22 12:39:46 agc Exp $
# FreeBSD Id: Makefile,v 1.14 1997/07/17 15:12:43 max Exp
#

DISTNAME=       jpegsrc.v6b
PKGNAME=        jpeg-6b
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/jpeg/

MAINTAINER=	mycroft@netbsd.org

WRKSRC=         ${WRKDIR}/jpeg-6b
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared --enable-static
INSTALL_TARGET= install install-lib

.include "../../mk/bsd.pkg.mk"
