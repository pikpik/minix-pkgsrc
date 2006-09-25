# $NetBSD: options.mk,v 1.1 2005/12/28 15:47:30 ghen Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.skipstone
PKG_SUPPORTED_OPTIONS=	wget
PKG_SUGGESTED_OPTIONS=	wget

.include "../../www/seamonkey/gecko-options.mk"
.include "../../mk/bsd.options.mk"

# SkipDownload uses wget to download files from the Internet, but since this
# is not strictly needed for SkipStone to run, it's an optional dependency.
.if !empty(PKG_OPTIONS:Mwget)
DEPENDS+=		wget>=1:../../net/wget
.endif

.if !empty(PKG_OPTIONS:Mfirefox)
MOZILLA=	firefox
.elif !empty(PKG_OPTIONS:Mseamonkey)
MOZILLA=	seamonkey
.endif
