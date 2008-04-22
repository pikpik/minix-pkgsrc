# $NetBSD: Makefile,v 1.6 2007/01/30 22:38:10 joerg Exp $

PKGNAME=	${PKGNAME_BASE:S/-/-x11-/}
COMMENT=	SQL shell for Sybase and MS-SQL servers (Athena GUI)

FILESDIR=	${.CURDIR}/../../databases/sqsh/files
PATCHDIR=	${.CURDIR}/../../databases/sqsh/patches
PKGDIR=		${.CURDIR}/../../databases/sqsh

PKG_OPTIONS.sqsh+=	-sqsh-motif sqsh-xaw

.include "../../databases/sqsh/Makefile"
