# $NetBSD: options.mk,v 1.7 2012/02/27 13:58:05 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.scummvm
PKG_SUPPORTED_OPTIONS=	fluidsynth

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfluidsynth)
.include "../../audio/fluidsynth/buildlink3.mk"
.endif
