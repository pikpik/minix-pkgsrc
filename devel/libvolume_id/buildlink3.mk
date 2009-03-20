# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/22 13:48:23 jmcneill Exp $

BUILDLINK_TREE+=	libvolume_id

.if !defined(LIBVOLUME_ID_BUILDLINK3_MK)
LIBVOLUME_ID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvolume_id+=	libvolume_id>=0.81.0
BUILDLINK_PKGSRCDIR.libvolume_id?=	../../devel/libvolume_id
.endif # LIBVOLUME_ID_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvolume_id
