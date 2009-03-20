# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/10/12 17:30:04 drochner Exp $

BUILDLINK_TREE+=	mxml

.if !defined(MXML_BUILDLINK3_MK)
MXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mxml+=	mxml>=2.3
BUILDLINK_PKGSRCDIR.mxml?=	../../textproc/mxml
.endif # MXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-mxml
