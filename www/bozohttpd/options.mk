# $NetBSD: options.mk,v 1.1 2008/03/03 15:53:03 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bozohttpd
PKG_SUPPORTED_OPTIONS=	bozohttpd-do-htpasswd

.include "../../mk/bsd.options.mk"

###
### Support Apache's .htpasswd files.
###
.if !empty(PKG_OPTIONS:Mbozohttpd-do-htpasswd)
CPPFLAGS+=	-DDO_HTPASSWD
.endif
