# $NetBSD: buildlink3.mk,v 1.2 2008/07/16 07:40:14 wiz Exp $

BUILDLINK_TREE+=	xlt

.if !defined(XLT_BUILDLINK3_MK)
XLT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xlt+=	xlt>=13.0.13
BUILDLINK_PKGSRCDIR.xlt?=	../../x11/xlt

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.endif # XLT_BUILDLINK3_MK

BUILDLINK_TREE+=	-xlt
