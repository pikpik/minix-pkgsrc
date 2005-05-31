# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.libmikmod
PKG_SUPPORTED_OPTIONS=	esound oss

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mesound)
.include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if !empty(PKG_OPTIONS:Moss)
.  include "../../mk/ossaudio.buildlink3.mk"
.endif
