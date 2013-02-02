# $NetBSD$

BUILDLINK_TREE+=	xcb-util-wm

.if !defined(XCB_UTIL_WM_BUILDLINK3_MK)
XCB_UTIL_WM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcb-util-wm+=	xcb-util-wm>=0.3.9
BUILDLINK_PKGSRCDIR.xcb-util-wm?=	../../x11/xcb-util-wm

#.include "../../x11/libxcb/buildlink3.mk"
.endif	# XCB_UTIL_WM_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcb-util-wm
