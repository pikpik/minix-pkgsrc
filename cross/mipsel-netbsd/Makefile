# $NetBSD$
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

WRKSRC=			${WRKDIR}/${EGCS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	elf32-littlemips
BINUTILS_LDEMULATION=	elf32lmip
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		mipsel-netbsd

.include "../COMMON/cross.mk"
