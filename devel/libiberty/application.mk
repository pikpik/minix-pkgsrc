# $NetBSD$
# Convenience header to help pull libiberty into an application's build.

.include "../../mk/bsd.prefs.mk"

# currently requires GCC for "-include"
.if empty(PKGSRC_COMPILER:Mgcc)
PKG_FAIL_REASON+=	"libiberty compatibility build requires gcc compiler"
.endif

.include "../../devel/libiberty/buildlink3.mk"

CPPFLAGS+=		-include libiberty.h
LIBS+=			-liberty
