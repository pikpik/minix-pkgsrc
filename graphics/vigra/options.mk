# $NetBSD$
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.vigra
PKG_SUPPORTED_OPTIONS=	fftw
PKG_SUGGESTED_OPTIONS=	fftw

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfftw)
CONFIGURE_ARGS+=	--with-fftw
.  include "../../math/fftw/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-fftw
.endif
