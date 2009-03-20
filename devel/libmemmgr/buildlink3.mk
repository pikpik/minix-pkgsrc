# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:45 jlam Exp $

BUILDLINK_TREE+=	libmemmgr

.if !defined(LIBMEMMGR_BUILDLINK3_MK)
LIBMEMMGR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmemmgr+=	libmemmgr>=1.04
BUILDLINK_PKGSRCDIR.libmemmgr?=	../../devel/libmemmgr
BUILDLINK_DEPMETHOD.libmemmgr?=	build

.include "../../devel/libetm/buildlink3.mk"
.endif # LIBMEMMGR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmemmgr
