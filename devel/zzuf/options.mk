# $NetBSD$
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.zzuf
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
.  if ${MACHINE_ARCH} == "x86_64" # XXX Is this correct?
CFLAGS+=		-fno-omit-frame-pointer
.  endif
BUILDLINK_TRANSFORM+=	rm:-fomit-frame-pointer
.endif
