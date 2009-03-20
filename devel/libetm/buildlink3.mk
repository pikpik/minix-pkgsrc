# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:44 jlam Exp $

BUILDLINK_TREE+=	libetm

.if !defined(LIBETM_BUILDLINK3_MK)
LIBETM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libetm+=	libetm>=1.09
BUILDLINK_PKGSRCDIR.libetm?=	../../devel/libetm
BUILDLINK_DEPMETHOD.libetm?=	build
.endif # LIBETM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libetm
