# $NetBSD: buildlink3.mk,v 1.18 2006/12/12 21:52:38 joerg Exp $

X11_BUILDLINK3_MK:=	${X11_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(X11_BUILDLINK3_MK:M+)

BUILDLINK_API_DEPENDS.x11+=		x11>=6.8.2
BUILDLINK_ABI_DEPENDS.x11?=	x11>=6.8.2
BUILDLINK_PKGSRCDIR.x11?=		../../minix/x11
BUILDLINK_LIBDIRS.x11?=		${X11ROOT_PREFIX}/lib
BUILDLINK_FNAME_TRANSFORM.x11+=		-e "s|/${X11ROOT_PREFIX}/|/|"

.endif  # X11_BUILDLINK3_MK

.include "../../pkgtools/x11-links/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"


