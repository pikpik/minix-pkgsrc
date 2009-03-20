# $NetBSD: buildlink3.mk,v 1.2 2008/12/22 02:48:56 jmcneill Exp $

BUILDLINK_TREE+=	libatomic_ops

.if !defined(LIBATOMIC_OPS_BUILDLINK3_MK)
LIBATOMIC_OPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libatomic_ops+=	libatomic_ops>=20081024nb1
BUILDLINK_PKGSRCDIR.libatomic_ops?=	../../devel/libatomic_ops
.endif # LIBATOMIC_OPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libatomic_ops
