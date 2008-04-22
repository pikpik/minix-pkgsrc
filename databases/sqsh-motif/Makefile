# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:37 joerg Exp $

PKGNAME=	${PKGNAME_BASE:S/-/-motif-/}
COMMENT=	SQL shell for Sybase and MS-SQL servers (Motif GUI)

FILESDIR=	${.CURDIR}/../../databases/sqsh/files
PATCHDIR=	${.CURDIR}/../../databases/sqsh/patches
PKGDIR=		${.CURDIR}/../../databases/sqsh

PKG_OPTIONS.sqsh+=	sqsh-motif -sqsh-xaw

.include "../../databases/sqsh/Makefile"
