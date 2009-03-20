# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:11:03 jlam Exp $

BUILDLINK_TREE+=	libnids

.if !defined(LIBNIDS_BUILDLINK3_MK)
LIBNIDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnids+=	libnids>=1.18
BUILDLINK_PKGSRCDIR.libnids?=	../../net/libnids
BUILDLINK_DEPMETHOD.libnids?=	build
.endif # LIBNIDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnids
