# $NetBSD: Makefile,v 1.3 2005/03/07 14:59:06 adam Exp $

.include "Makefile.common"

PKGREVISION=		2

CONFIGURE_ARGS+=	--disable-tcl

post-install:
	${INSTALL_MAN} ${WRKSRC}/sqlite3.1 ${PREFIX}/man/man1/sqlite3.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
