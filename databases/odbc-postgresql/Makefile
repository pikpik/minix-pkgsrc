# $NetBSD: Makefile,v 1.11 2006/02/05 23:08:32 joerg Exp $

.include "Makefile.common"

PKGNAME=		odbc-postgresql-${BASE_VERS}
PKGREVISION=		1
COMMENT=		ODBC interface to PostgreSQL

CONFIGURE_ARGS+=	--with-odbcinst=${PKG_SYSCONFDIR:Q}

post-extract:
	set -e; \
	cd ${WRKSRC}; \
	[ ! -d src/backend/port/dynloader ] || (			\
		cd src/backend/port/dynloader;				\
		cp freebsd.c dragonfly.c;				\
		cp freebsd.h dragonfly.h;				\
	);								\
	[ ! -d src/template ]						\
	|| touch src/template/dragonfly;				\
	[ ! -d src/include/port ]					\
	|| cp src/include/port/freebsd.h src/include/port/dragonfly.h;	\
	[ ! -d src/makefiles ]						\
	|| cp src/makefiles/Makefile.freebsd src/makefiles/Makefile.dragonfly

.include "../../mk/bsd.pkg.mk"
