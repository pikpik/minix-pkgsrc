# $NetBSD$

PKGNAME=		${DISTNAME:S/-/-client-/}
COMMENT+=		client

CONFLICTS=		bacula-[0-9]*

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches
FILESDIR=		${.CURDIR}/../../sysutils/bacula/files

CONFIGURE_ARGS+=	--enable-client-only

RCD_SCRIPTS=		bacula-fd

.include "../../sysutils/bacula/Makefile.common"
.include "../../mk/bsd.pkg.mk"
