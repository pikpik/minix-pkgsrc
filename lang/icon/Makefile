# $NetBSD: Makefile,v 1.21 2002/02/28 13:42:59 agc Exp $

DISTNAME=       	icon.v941src
PKGNAME=		icon-9.4.1
CATEGORIES=		lang
MASTER_SITES=		http://www.cs.arizona.edu/icon/ftp/packages/unix/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.arizona.edu/icon/index.htm
COMMENT=		The Icon programming language

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-i386 NetBSD-*-sparc NetBSD-*-powerpc

CONFIGURE_TARGET?=	X-Configure
ALL_TARGET=		All

pre-build:
	${MKDIR} ${WRKSRC}/lib/icon

do-configure:
	cd ${WRKSRC}/config/unix/netbsd; \
	${SED} -e 's:@X11BASE@:${X11BASE}:g' define.h.in \
		> define.h
	cd ${WRKSRC}; ${MAKE} ${CONFIGURE_TARGET} name=netbsd

do-install:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} dest=${PREFIX} Install

.include "../../mk/bsd.pkg.mk"
