# $NetBSD: Makefile,v 1.8 1999/10/22 23:55:49 tron Exp $
#

.include "../lame/Makefile.common"

PKGNAME=	lame-gui-${VERS}

DEPENDS=	gtk+-1.2.*:../../x11/gtk

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hive.me.gu.edu.au/not_lame/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lame ${PREFIX}/bin/lame-gui

.include "../../mk/bsd.pkg.mk"
