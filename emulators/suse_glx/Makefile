# $NetBSD: Makefile,v 1.3 2000/12/16 22:37:31 tron Exp $
#

DISTNAME=		suse_glx-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=x3d1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_base-${SUSE_VERSION}:../../emulators/suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		glx.rpm

.include "../suse_linux/Makefile.common"
