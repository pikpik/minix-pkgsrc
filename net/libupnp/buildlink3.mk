# $NetBSD: buildlink3.mk,v 1.2 2007/08/19 01:36:22 obache Exp $

BUILDLINK_TREE+=	libupnp

.if !defined(LIBUPNP_BUILDLINK3_MK)
LIBUPNP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libupnp+=	libupnp>=1.4.6
BUILDLINK_PKGSRCDIR.libupnp?=	../../net/libupnp
.endif # LIBUPNP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libupnp
