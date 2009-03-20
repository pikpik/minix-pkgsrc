# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:11:07 jlam Exp $

BUILDLINK_TREE+=	libidea

.if !defined(LIBIDEA_BUILDLINK3_MK)
LIBIDEA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libidea+=	libidea>=0.8.2
BUILDLINK_PKGSRCDIR.libidea?=	../../security/libidea
BUILDLINK_DEPMETHOD.libidea?=	build
.endif # LIBIDEA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libidea
