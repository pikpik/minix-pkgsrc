# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/03/17 22:44:11 wiz Exp $

BUILDLINK_TREE+=	gtksourceview-sharp2

.if !defined(GTKSOURCEVIEW_SHARP2_BUILDLINK3_MK)
GTKSOURCEVIEW_SHARP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtksourceview-sharp2+=	gtksourceview-sharp2>=0.10
BUILDLINK_PKGSRCDIR.gtksourceview-sharp2?=	../../x11/gtksourceview-sharp2
.endif # GTKSOURCEVIEW_SHARP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtksourceview-sharp2
