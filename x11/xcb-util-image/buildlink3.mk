# $NetBSD$

BUILDLINK_TREE+=	xcb-util-image

.if !defined(XCB_UTIL_IMAGE_BUILDLINK3_MK)
XCB_UTIL_IMAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcb-util-image+=	xcb-util-image>=0.3.9
BUILDLINK_PKGSRCDIR.xcb-util-image?=	../../x11/xcb-util-image

#.include "../../x11/libxcb/buildlink3.mk"
#.include "../../x11/xcb-util/buildlink3.mk"
.endif	# XCB_UTIL_IMAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcb-util-image
