# $NetBSD$
#

.if !defined(CELT_HACKS_MK)
CELT_HACKS_MK=	# empty
.  include "../../mk/compiler.mk"
###
### XXX Remove this if unneeded in the future.
###
.  if !empty(CC_VERSION:Mgcc-[34]*)
CFLAGS+=	-fno-strict-aliasing
PKG_HACKS+=	no-strict-aliasing
.  endif
.endif
