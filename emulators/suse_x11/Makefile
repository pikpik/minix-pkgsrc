# $NetBSD: Makefile,v 1.15 2002/02/21 17:27:39 martti Exp $

DISTNAME=		suse_x11-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=x1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for X11 binaries

DEPENDS+=		suse_base>=${SUSE_VERSION}:../suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		xshared.rpm

.include "../suse_linux/Makefile.common"
