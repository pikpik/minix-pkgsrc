# $NetBSD: Makefile,v 1.5 2006/07/22 04:46:17 rillig Exp $
#

DISTNAME=		synergy-1.3.1
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synergy2/}

MAINTAINER=		yui@yui.pe.kr
HOMEPAGE=		http://synergy2.sourceforge.net/
COMMENT=		Let an user share a mouse and keyboard among computers

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

DOCDIR=			${PREFIX}/share/doc/html/${PKGBASE}
EXAMPLSEDIR=		${PREFIX}/share/examples/${PKGBASE}
DOCS=			*.html *.css images/*.gif

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/images
	cd ${WRKSRC}/doc; \
	for f in ${DOCS}; do \
		${INSTALL_DATA} $$f ${DOCDIR}/$$f; \
	done
	${INSTALL_DATA_DIR} ${EXAMPLSEDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/synergy.conf ${EXAMPLSEDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
