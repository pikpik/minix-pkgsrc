# $NetBSD: Makefile,v 1.13 2004/01/20 12:25:54 agc Exp $
#

NO_MTREE=		YES

PKGNAME=		standalone-${DISTNAME}

PKG_SHELL=		/bin/tcsh

WRKSRC=			${WRKDIR}/${DISTNAME}
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches

.include "../../shells/tcsh/Makefile"

COMMENT:=		Standalone version of the Extended C-shell

PKG_INFO:=		${PKG_INFO}
PKG_CREATE:=		${PKG_CREATE}
PREFIX=			/
NLSDIR=			usr/share/nls
CONFIGURE_ARGS=		--prefix=${PREFIX} --bindir=/bin
CONFIGURE_ARGS+=	--mandir=/usr/share/man

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo

.if ${OPSYS} != "SunOS"
LDFLAGS+=		-static
.endif
