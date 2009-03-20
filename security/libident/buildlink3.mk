# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:07 jlam Exp $

BUILDLINK_TREE+=	libident

.if !defined(LIBIDENT_BUILDLINK3_MK)
LIBIDENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libident+=	libident>=0.22
BUILDLINK_ABI_DEPENDS.libident+=	libident>=0.22nb1
BUILDLINK_PKGSRCDIR.libident?=	../../security/libident
.endif # LIBIDENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libident
