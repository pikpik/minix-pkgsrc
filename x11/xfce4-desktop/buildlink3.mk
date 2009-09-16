# $NetBSD: buildlink3.mk,v 1.24 2009/03/20 19:25:53 joerg Exp $

BUILDLINK_TREE+=	xfce4-desktop

.if !defined(XFCE4_DESKTOP_BUILDLINK3_MK)
XFCE4_DESKTOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-desktop+=	xfce4-desktop>=4.6.0
BUILDLINK_PKGSRCDIR.xfce4-desktop?=	../../x11/xfce4-desktop

.endif # XFCE4_DESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-desktop
