# $NetBSD: buildlink3.mk,v 1.25 2009/03/20 19:25:35 joerg Exp $

BUILDLINK_TREE+=	xfce4-wm

.if !defined(XFCE4_WM_BUILDLINK3_MK)
XFCE4_WM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-wm+=	xfce4-wm>=4.6.0
BUILDLINK_PKGSRCDIR.xfce4-wm?=	../../wm/xfce4-wm

.endif # XFCE4_WM_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-wm
