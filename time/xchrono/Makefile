# $NetBSD: Makefile,v 1.2 2001/02/17 17:32:14 wiz Exp $
#

DISTNAME=		xchrono
PKGNAME=		xchrono-19900813
CATEGORIES=		time x11
MASTER_SITES=		http://www.mit.edu/afs/athena/contrib/softbone/source/src/xchrono/
EXTRACT_SUFX=		.shar

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://infoshako.sk.tsukuba.ac.jp/jdoc/X-utilities/xchrono
COMMENT=		multi-timezone X11-based clock

USE_IMAKE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xchrono
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xchrono/

.include "../../mk/bsd.pkg.mk"
