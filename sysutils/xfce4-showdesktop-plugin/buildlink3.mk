# $NetBSD$

BUILDLINK_DEPTH:=				${BUILDLINK_DEPTH}+
XFCE4_SHOWDESKTOP_PLUGIN_BUILDLINK3_MK:=	${XFCE4_SHOWDESKTOP_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-showdesktop-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-showdesktop-plugin}
BUILDLINK_PACKAGES+=	xfce4-showdesktop-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-showdesktop-plugin

.if ${XFCE4_SHOWDESKTOP_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-showdesktop-plugin+=	xfce4-showdesktop-plugin>=0.4.0nb3
BUILDLINK_PKGSRCDIR.xfce4-showdesktop-plugin?=	../../sysutils/xfce4-showdesktop-plugin
.endif	# XFCE4_SHOWDESKTOP_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=				${BUILDLINK_DEPTH:S/+$//}
