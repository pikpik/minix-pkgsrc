# $NetBSD: Makefile,v 1.2 2000/10/13 13:02:02 fredb Exp $
#

DISTVERSION=		1.0.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

WRKSRC=			${WRKDIR}/${EGCS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	pe-i386
BINUTILS_LDEMULATION=	i386pe
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		i386-cygwin32

BINUTILS_EXTRAS=	dlltool windres

post-configure:
	${CP} ${FILESDIR}/i386_limits.h ${SYS_INCLUDE}/machine/limits.h
	${CP} ${FILESDIR}/syslimits.h ${SYS_INCLUDE}/sys/
	${CP} ${FILESDIR}/featuretest.h ${SYS_INCLUDE}/sys/
	${CP} ${FILESDIR}/limits.h ${SYS_INCLUDE}/

.include "../COMMON/cross.mk"
