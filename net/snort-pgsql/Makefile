# $NetBSD: Makefile,v 1.1.1.1 2002/04/15 08:32:48 rh Exp $
#

.include "../snort/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-pgsql-/}

COMMENT=	Libpcap-based packet sniffer/logger using a PostgreSQL database

CONFLICTS+=	snort-[0-9]*

CONFIGURE_ARGS+=--with-postgresql=${BUILDLINK_DIR}

PATCHDIR=	../snort/patches
DISTINFO_FILE=	../snort/distinfo

.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../net/libpcap/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
