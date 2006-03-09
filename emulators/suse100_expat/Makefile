# $NetBSD: Makefile,v 1.6 2006/02/05 23:09:03 joerg Exp $

DISTNAME=		suse_expat-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE100}
DISTFILES=		${RPMFILES}

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for expat binaries

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse100_base

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
LIBTOOLIZE_PLIST=	NO
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
DISTINFO_FILE=		${.CURDIR}/distinfo.${MACHINE_ARCH}
.endif

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
