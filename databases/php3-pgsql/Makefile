# $NetBSD: Makefile,v 1.10 2001/09/27 23:18:56 jlam Exp $

MODNAME=		pgsql
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP3 extension for PostgreSQL database access

USE_BUILDLINK_ONLY=	yes

.include "../../www/php3/Makefile.module"

CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_DIR}
MOD_CPPFLAGS+=		-I${BUILDLINK_DIR}/include/pgsql
MOD_LIBS+=		-lpq -lcrypt

.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
