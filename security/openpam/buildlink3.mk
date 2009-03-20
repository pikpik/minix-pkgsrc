# $NetBSD: buildlink3.mk,v 1.4 2006/07/08 23:11:08 jlam Exp $

BUILDLINK_TREE+=	openpam

.if !defined(OPENPAM_BUILDLINK3_MK)
OPENPAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openpam+=	openpam>=20040210
BUILDLINK_PKGSRCDIR.openpam?=	../../security/openpam

.include "../../mk/dlopen.buildlink3.mk"
.endif # OPENPAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-openpam
