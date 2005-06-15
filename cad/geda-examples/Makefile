# $NetBSD: Makefile,v 1.9 2005/05/22 20:07:41 jlam Exp $
#

DISTNAME=	geda-examples-${PKGVERSION}
PKGREVISION=	1
CATEGORIES=	cad

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Examples for gEDA

CONFLICTS+=	gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

pre-install:
	${RM} -f ${WRKSRC}/config.status.overridden
	${RM} -f ${WRKSRC}/configure.lineno

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/geda
	cd ${WRKSRC} && ${PAX} -s '/.*Makefile.*//' -s '/.config.log//' \
		-s '/.*config.status//' \
		-rw . ${PREFIX}/share/examples/geda
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/examples/geda
	${CHGRP} -R ${SHAREGRP} ${PREFIX}/share/examples/geda

.include "../../mk/bsd.pkg.mk"
