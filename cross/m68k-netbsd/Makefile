# $NetBSD: Makefile,v 1.1.1.1 2000/01/14 14:51:27 tsutsui Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/
COMMENT=		Cross-compile environment for a.out NetBSD/m68k (static binaries only)

WRKSRC=			${WRKDIR}/${BINUTILS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	a.out-m68k-netbsd
BINUTILS_LDEMULATION=	m68knbsd
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		m68k-netbsd

.include "../COMMON/cross.mk"
