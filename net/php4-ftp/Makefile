# $NetBSD: Makefile,v 1.2 2001/12/03 08:31:03 jlam Exp $

MODNAME=		ftp
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP4 extension for FTP access

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
