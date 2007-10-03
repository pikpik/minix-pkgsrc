# $NetBSD: options.mk,v 1.3 2007/05/23 12:17:12 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.squirrelmail
PKG_SUPPORTED_OPTIONS=	squirrelmail-japanese squirrelmail-lite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msquirrelmail-japanese)
PATCHFILES+=		squirrelmail-1.4.11-ja-20071002-patch.gz
SITES.squirrelmail-1.4.11-ja-20071002-patch.gz= \
			http://www.yamaai-tech.com/~masato/Download/
PATCH_DIST_STRIP.squirrelmail-1.4.11-ja-20071002-patch.gz=	-p1

.endif

.if !empty(PKG_OPTIONS:Msquirrelmail-lite)
PATCHFILES+=		squirrelmail-1.4.11-lite-20071003-patch.bz2
SITES.squirrelmail-1.4.11-lite-20071003-patch= \
			ftp://ftp.back-street.net/pub/squirrelmail/
.endif
