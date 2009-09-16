# $NetBSD: buildlink3.mk,v 1.22 2009/03/20 19:25:35 joerg Exp $

BUILDLINK_TREE+=	xfce4-wm-themes

.if !defined(XFCE4_WM_THEMES_BUILDLINK3_MK)
XFCE4_WM_THEMES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-wm-themes+=	xfce4-wm-themes>=4.6.0
BUILDLINK_PKGSRCDIR.xfce4-wm-themes?=	../../wm/xfce4-wm-themes

.endif # XFCE4_WM_THEMES_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-wm-themes
