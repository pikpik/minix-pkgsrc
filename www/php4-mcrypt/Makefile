# $NetBSD: Makefile,v 1.3 2001/03/01 18:18:16 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		mcrypt
CATEGORIES+=		security

COMMENT=		PHP4 extension for the mcrypt crypto algorithms library

DEPENDS+=		libmcrypt>=2.2:../../security/libmcrypt

EVAL_PREFIX+=		MCRYPTDIR=libmcrypt
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MCRYPTDIR}

.include "../../mk/bsd.pkg.mk"
