# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:25:41 joerg Exp $

BUILDLINK_TREE+=	gtk-sharp

.if !defined(GTK_SHARP_BUILDLINK3_MK)
GTK_SHARP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-sharp+=	gtk-sharp>=2.12.1
BUILDLINK_PKGSRCDIR.gtk-sharp?=		../../x11/gtk-sharp
.endif # GTK_SHARP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-sharp
