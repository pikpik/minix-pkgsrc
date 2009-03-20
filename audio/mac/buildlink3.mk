# $NetBSD: buildlink3.mk,v 1.1 2007/02/09 21:20:01 drochner Exp $

BUILDLINK_TREE+=	mac

.if !defined(MAC_BUILDLINK3_MK)
MAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mac+=	mac>=3.99u4b5
BUILDLINK_PKGSRCDIR.mac?=	../../audio/mac
.endif # MAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-mac
