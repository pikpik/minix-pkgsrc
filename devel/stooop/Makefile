# $NetBSD: Makefile,v 1.1.1.1 1999/06/07 22:14:08 tron Exp $

DISTNAME=	stooop-4.1.1
CATEGORIES=	x11 tcl
MASTER_SITES=	http://jfontain.free.fr/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://jfontain.free.fr/

DEPENDS+=	tcl-8.3.2:../../lang/tcl

NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/tcl/stooop
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${PREFIX}/lib/tcl/stooop
	${INSTALL_DATA} ${WRKSRC}/stooop.tcl ${PREFIX}/lib/tcl/stooop
	${INSTALL_DATA} ${WRKSRC}/switched.tcl ${PREFIX}/lib/tcl/stooop
	${MKDIR} ${PREFIX}/share/doc/tcl/stooop
	${INSTALL_DATA} ${WRKSRC}/stooop.htm ${PREFIX}/share/doc/tcl/stooop
	${INSTALL_DATA} ${WRKSRC}/switched.htm ${PREFIX}/share/doc/tcl/stooop

.include "../../mk/bsd.pkg.mk"
