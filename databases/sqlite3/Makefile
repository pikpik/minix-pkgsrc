# $NetBSD: Makefile,v 1.28 2004/10/03 00:13:23 tv Exp $

DISTNAME=		sqlite-3.0.8
PKGNAME=		${DISTNAME:S/-/3-/}
CATEGORIES=		databases
MASTER_SITES=		http://www.hwaci.com/sw/sqlite/ \
			http://www.sqlite.org/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.hwaci.com/sw/sqlite/
COMMENT=		SQL Database Engine in a C Library

WRKSRC=			${WRKDIR}/sqlite
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-tcl

PKGCONFIG_OVERRIDE=	${WRKDIR}/sqlite/sqlite3.pc.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/sqlite.1 ${PREFIX}/man/man1/sqlite3.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
