# $NetBSD: Makefile,v 1.8 2005/02/05 00:45:49 wiz Exp $
#

DISTNAME=	cksfv-1.3.4
CATEGORIES=	misc
MASTER_SITES=	http://www.modeemi.fi/~shd/foss/cksfv/files/ \
		http://www.modeemi.fi/~shd/foss/cksfv/files/devel/
#EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.modeemi.fi/~shd/foss/cksfv/
COMMENT=	Check and create simple file verification (SFV) listings

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--mandir=${PREFIX:Q}/man
CONFIGURE_ARGS+=	--compiler=${CC:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cksfv
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cksfv

.include "../../mk/bsd.pkg.mk"
