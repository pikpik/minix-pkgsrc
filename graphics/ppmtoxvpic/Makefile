# $NetBSD: Makefile,v 1.1.1.1 2001/08/05 00:23:14 hubertf Exp $
#

PKGNAME=	ppmtoxvpic-0.99.9
CATEGORIES=	graphics

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Convert PPM image to preview pic readable by xv and gimp

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/utils/xvpicmaker ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/utils/ppmtoxvpic ${PREFIX}/bin

.include "../../x11/dfm/Makefile.common"
