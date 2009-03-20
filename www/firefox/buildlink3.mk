# $NetBSD: buildlink3.mk,v 1.17 2008/05/31 23:08:33 tnn Exp $

BUILDLINK_TREE+=	firefox

.if !defined(FIREFOX_BUILDLINK3_MK)
FIREFOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.firefox+=	firefox>=2.0
BUILDLINK_API_DEPENDS.firefox+=	firefox<=2.99
BUILDLINK_ABI_DEPENDS.firefox+=	firefox>=2.0.0.3nb1
BUILDLINK_PKGSRCDIR.firefox?=	../../www/firefox
.endif # FIREFOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-firefox
