# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:27 joerg Exp $

BUILDLINK_TREE+=	xfce4-genmon-plugin

.if !defined(XFCE4_GENMON_PLUGIN_BUILDLINK3_MK)
XFCE4_GENMON_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-genmon-plugin+=	xfce4-genmon-plugin>=3.1
BUILDLINK_ABI_DEPENDS.xfce4-genmon-plugin?=	xfce4-genmon-plugin>=3.1nb1
BUILDLINK_PKGSRCDIR.xfce4-genmon-plugin?=	../../sysutils/xfce4-genmon-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_GENMON_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-genmon-plugin
