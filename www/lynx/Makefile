# $NetBSD: Makefile,v 1.10 1998/06/21 15:22:20 tv Exp $
#

DISTNAME=       lynx2-8
PKGNAME=        lynx-2.8
WRKSRC=         ${WRKDIR}/lynx2-8
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/release2-8/

MAINTAINER=	packages@netbsd.org

CONFLICTS=	lynx-2.8rel.2

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

CONFIGURE_ARGS+= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc"
GNU_CONFIGURE=  YES
INSTALL_TARGET= install install-help
MAKEFILE=       makefile

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/lynx_help

.include "../../mk/bsd.pkg.mk"
