# $NetBSD: Makefile,v 1.4 2002/11/05 07:33:17 martti Exp $

MODNAME=		ftp
CATEGORIES+=		net
PKGREVISION=		1
COMMENT=		PHP4 extension for FTP access

USE_BUILDLINK2=		YES
DISTINFO_FILE=		${.CURDIR}/distinfo

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
