# $NetBSD: Makefile,v 1.2 2001/02/17 17:37:26 wiz Exp $

DISTNAME=		Isearch-1.47d
PKGNAME=		isearch-1.47d
CATEGORIES=		textproc databases
MASTER_SITES=		http://www.etymon.com/pub/Isearch/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.etymon.com/Isearch/
COMMENT=		Advanced text indexing and searching system

GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/isearch
	${INSTALL_DATA} ${WRKSRC}/TUTORIAL ${PREFIX}/share/doc/isearch
	${INSTALL_DATA} ${WRKSRC}/doc/DebugFirewall.doc ${PREFIX}/share/doc/isearch
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/isearch
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${PREFIX}/share/doc/html/isearch/

.include "../../mk/bsd.pkg.mk"
