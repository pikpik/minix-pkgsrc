# $NetBSD: buildlink3.mk,v 1.2 2008/03/04 15:52:15 shannonjr Exp $

BUILDLINK_TREE+=	ccid

.if !defined(CCID_BUILDLINK3_MK)
CCID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ccid+=	ccid>=1.3.2
BUILDLINK_PKGSRCDIR.ccid?=	../../security/ccid

.include "../../security/pcsc-lite/buildlink3.mk"
.endif # CCID_BUILDLINK3_MK

BUILDLINK_TREE+=	-ccid
