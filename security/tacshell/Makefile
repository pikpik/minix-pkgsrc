# $NetBSD: Makefile,v 1.1.1.1 2004/05/26 12:04:27 sekiya Exp $

DISTNAME=		tacshell-0.91
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.rezrov.net/software/

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://www.rezrov.net/software/tacshell.html
COMMENT=		RSA ACE/Server sdshell workalike, using TACACS+

GNU_CONFIGURE=		YES
CONF_FILES+=		$(PREFIX)/share/examples/tacshell/tacshell.conf \
			${PKG_SYSCONFDIR}/tacshell.conf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tacshell
	${INSTALL_DATA} ${WRKSRC}/tacshell.conf-example \
		${PREFIX}/share/examples/tacshell/tacshell.conf

.include "../../mk/bsd.pkg.mk"
