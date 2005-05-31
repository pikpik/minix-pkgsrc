# $NetBSD: options.mk,v 1.1 2004/12/21 04:22:03 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ezmlm
PKG_SUPPORTED_OPTIONS=	althash

.if ${OPSYS} == "Darwin"
PKG_SUGGESTED_OPTIONS=	althash
.endif

.include "../../mk/bsd.options.mk"

###
### alternate subscriber hashing scheme for case-insensitive filesystems
###
.if !empty(PKG_OPTIONS:Malthash)
post-patch:
	@cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-althash
.endif
