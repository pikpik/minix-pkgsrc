# $NetBSD$

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTK_BUILDLINK3_MK:=	${GTK_BUILDLINK3_MK}+

.if !empty(GTK_BUILDLINK3_MK:M\+)
BUILDLINK_DEPENDS.gtk?=		gtk+>=1.2.10nb5
BUILDLINK_PKGSRCDIR.gtk?=	../../x11/gtk
.endif	# GTK_BUILDLINK3_MK

.if !empty(BUILDLINK_DEPTH:M\+)
BUILDLINK_DEPENDS+=	gtk
.endif

.if !empty(GTK_BUILDLINK3_MK:M\+)
BUILDLINK_PACKAGES+=	gtk

USE_X11=		YES

.  include "../../devel/gettext-lib/buildlink3.mk"
.  include "../../devel/glib/buildlink3.mk"
.endif	# GTK_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
