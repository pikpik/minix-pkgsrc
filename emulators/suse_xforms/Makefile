# $NetBSD: Makefile,v 1.11 2002/02/21 17:30:48 martti Exp $

DISTNAME=		xforms
PKGNAME=		suse_${DISTNAME}-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=pay3/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for xforms binaries

DEPENDS+=		suse_x11>=${SUSE_VERSION}:../suse_x11

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

.include "../suse_linux/Makefile.common"
