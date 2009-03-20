# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:45 jlam Exp $

BUILDLINK_TREE+=	libscsi

.if !defined(LIBSCSI_BUILDLINK3_MK)
LIBSCSI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libscsi+=	libscsi>=1.6
BUILDLINK_PKGSRCDIR.libscsi?=	../../devel/libscsi
BUILDLINK_DEPMETHOD.libscsi?=	build
.endif # LIBSCSI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libscsi
