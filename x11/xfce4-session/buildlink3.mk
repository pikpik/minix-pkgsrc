# $NetBSD: buildlink3.mk,v 1.18 2008/12/19 23:58:18 hira Exp $

BUILDLINK_TREE+=	xfce4-session

.if !defined(XFCE4_SESSION_BUILDLINK3_MK)
XFCE4_SESSION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-session+=	xfce4-session>=4.4.3nb2
BUILDLINK_PKGSRCDIR.xfce4-session?=	../../x11/xfce4-session

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_SESSION_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-session
