# $NetBSD: Makefile,v 1.5 2004/03/05 13:03:47 dmcmahill Exp $
#

DISTNAME=	geda-examples-${PKGVERSION}
CATEGORIES=	cad

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Examples for gEDA

CONFLICTS+=	gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

pre-install:
	${RM} -f ${WRKSRC}/config.status.overridden

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/geda
	cd ${WRKSRC} && tar -cf - * | \
		(cd ${PREFIX}/share/examples/geda && tar -xf -)
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/examples/geda
	${CHGRP} -R ${SHAREGRP} ${PREFIX}/share/examples/geda

.include "../../mk/bsd.pkg.mk"
