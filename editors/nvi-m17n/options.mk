# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.nvi-m17n
PKG_SUPPORTED_OPTIONS=	canna
PKG_SUGGESTED_OPTIONS=	canna

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcanna)
.include "../../inputmethod/canna-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-canna=${BUILDLINK_PREFIX.canna-lib}
CANNA_OPT.euc-jp=canna cannactrl cannakey=
CANNA_OPT.sjis=${CANNA_OPT.euc-jp}
CANNA_OPT.iso-2022-jp=${CANNA_OPT.euc-jp}
.endif
