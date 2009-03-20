# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/01/06 21:47:09 ghen Exp $

BUILDLINK_TREE+=	libixp

.if !defined(LIBIXP_BUILDLINK3_MK)
LIBIXP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libixp+=	libixp>=0.4
BUILDLINK_PKGSRCDIR.libixp?=	../../devel/libixp
.endif # LIBIXP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libixp
