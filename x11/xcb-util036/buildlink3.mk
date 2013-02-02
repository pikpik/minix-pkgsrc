# $NetBSD: buildlink3.mk,v 1.1 2012/07/13 14:19:47 wiz Exp $

BUILDLINK_TREE+=	xcb-util036

.if !defined(XCB_UTIL036_BUILDLINK3_MK)
XCB_UTIL036_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcb-util036+=	xcb-util036>=0.3.6
BUILDLINK_PKGSRCDIR.xcb-util036?=	../../x11/xcb-util036

BUILDLINK_INCDIRS.xcb-util036+=		xcb-util036/include
BUILDLINK_LIBDIRS.xcb-util036+=		xcb-util036/lib
BUILDLINK_FNAME_TRANSFORM.xcb-util036+=	-e 's|xcb-util036/lib/pkgconfig/|lib/pkgconfig/|'

.include "../../x11/libxcb/buildlink3.mk"
.endif	# XCB_UTIL036_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcb-util036
