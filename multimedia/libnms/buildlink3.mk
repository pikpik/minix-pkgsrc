# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/09/10 16:27:14 xtraeme Exp $

BUILDLINK_TREE+=	libnms

.if !defined(LIBNMS_BUILDLINK3_MK)
LIBNMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnms+=	libnms>=0.6.0
BUILDLINK_PKGSRCDIR.libnms?=	../../multimedia/libnms
.endif # LIBNMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnms
