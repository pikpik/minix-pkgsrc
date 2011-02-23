# $NetBSD$

BUILDLINK_TREE+=	xerces-c

.if !defined(XERCES_C_BUILDLINK3_MK)
XERCES_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xerces-c+=	xerces-c>=3.1.1
BUILDLINK_PKGSRCDIR.xerces-c?=		../../textproc/xerces-c3

.include "../../converters/libiconv/buildlink3.mk"
.endif	# XERCES_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xerces-c
