# $NetBSD: buildlink3.mk,v 1.26 2009/03/20 19:25:54 joerg Exp $

BUILDLINK_TREE+=	xfce4-utils

.if !defined(XFCE4_UTILS_BUILDLINK3_MK)
XFCE4_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-utils+=	xfce4-utils>=4.6.0
BUILDLINK_PKGSRCDIR.xfce4-utils?=	../../x11/xfce4-utils

.endif # XFCE4_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-utils
