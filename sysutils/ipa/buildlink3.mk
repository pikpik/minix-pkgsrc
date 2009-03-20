# $NetBSD: buildlink3.mk,v 1.1 2007/01/03 15:01:25 obache Exp $

BUILDLINK_TREE+=	ipa

.if !defined(IPA_BUILDLINK3_MK)
IPA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ipa+=	ipa>=2.0
BUILDLINK_PKGSRCDIR.ipa?=	../../sysutils/ipa
BUILDLINK_DEPMETHOD.ipa?=	build
.endif # IPA_BUILDLINK3_MK

BUILDLINK_TREE+=	-ipa
