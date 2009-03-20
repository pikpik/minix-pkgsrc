# $NetBSD: buildlink3.mk,v 1.9 2006/08/10 13:44:21 abs Exp $

BUILDLINK_TREE+=	xerces-c

.if !defined(XERCES_C_BUILDLINK3_MK)
XERCES_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xerces-c+=	xerces-c>=2.7.0
BUILDLINK_ABI_DEPENDS.xerces-c?=	xerces-c>=2.7.0
BUILDLINK_PKGSRCDIR.xerces-c?=	../../textproc/xerces-c

.include "../../converters/libiconv/buildlink3.mk"
.endif # XERCES_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xerces-c
