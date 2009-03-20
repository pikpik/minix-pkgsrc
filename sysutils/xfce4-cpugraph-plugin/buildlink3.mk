# $NetBSD: buildlink3.mk,v 1.13 2007/04/12 09:55:13 martti Exp $

BUILDLINK_TREE+=	xfce4-cpugraph-plugin

.if !defined(XFCE4_CPUGRAPH_PLUGIN_BUILDLINK3_MK)
XFCE4_CPUGRAPH_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-cpugraph-plugin+=	xfce4-cpugraph-plugin>=0.3.0
BUILDLINK_PKGSRCDIR.xfce4-cpugraph-plugin?=	../../sysutils/xfce4-cpugraph-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_CPUGRAPH_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-cpugraph-plugin
