# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucspi-ssl
PKG_SUPPORTED_OPTIONS+=	tls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtls)
TLS_PATCH=		ucspi-ssl-0.70-ucspitls-0.1.patch
PATCHFILES+=            ${TLS_PATCH}
SITES_${TLS_PATCH}=	http://www.suspectclass.com/~sgifford/ucspi-tls/files/
PATCH_DIST_STRIP.${TLS_PATCH}=	-p1
.endif
