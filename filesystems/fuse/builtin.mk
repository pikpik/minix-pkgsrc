# $NetBSD$

BUILTIN_PKG:=	fuse
PKGCONFIG_BASE.fuse=	/usr
PKGCONFIG_FILE.fuse=	/usr/lib/pkgconfig/fuse.pc
.include "../../mk/buildlink3/pkgconfig-builtin.mk"

.if !empty(USE_BUILTIN.fuse:M[yY][eE][sS])
BUILDLINK_FILES.fuse+=	lib/pkgconfig/fuse.pc
.endif

