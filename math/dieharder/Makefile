# $NetBSD: Makefile,v 1.8 2007/02/09 20:27:16 drochner Exp $
#

DISTNAME=	dieharder-2.24.4
CATEGORIES=	math
MASTER_SITES=	http://www.phy.duke.edu/~rgb/General/dieharder/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.phy.duke.edu/~rgb/General/dieharder.php
COMMENT=	Random number generator test suite

AUTOMAKE_REQD=	1.9.6
USE_TOOLS+=	automake gmake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
MANCOMPRESSED=	yes

pre-configure:
	cd ${WRKSRC}; ${SH} ./autogen.sh

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
