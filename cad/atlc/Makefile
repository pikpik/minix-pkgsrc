# $NetBSD$
#

DISTNAME=	atlc-2.32
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atlc/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://atlc.sourceforge.net
COMMENT=	Calculates the impedance of arbitrary cross section transmission lines

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/atlc
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/atlc

.include "../../mk/bsd.pkg.mk"
