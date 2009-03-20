# $NetBSD: buildlink3.mk,v 1.15 2008/05/19 10:43:02 tnn Exp $

BUILDLINK_TREE+=	firefox-gtk1

.if !defined(FIREFOX_GTK1_BUILDLINK3_MK)
FIREFOX_GTK1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.firefox-gtk1+=	firefox-gtk1>=2.0
BUILDLINK_ABI_DEPENDS.firefox-gtk1+=	firefox-gtk1>=2.0.0.3nb1
BUILDLINK_PKGSRCDIR.firefox-gtk1?=	../../www/firefox-gtk1
.endif # FIREFOX_GTK1_BUILDLINK3_MK

BUILDLINK_TREE+=	-firefox-gtk1
