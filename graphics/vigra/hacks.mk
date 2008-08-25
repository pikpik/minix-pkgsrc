# $NetBSD$
#
.if !defined(VIGRA_HACKS_MK)
VIGRA_HACKS_MK=	# empty
.  include "../../mk/compiler.mk"
#
.  if !empty(CC_VERSION:Mgcc-[34]*)
PKG_HACKS+=	no-strict-aliasing
CFLAGS+=	-fno-strict-aliasing
.  endif
.endif
