# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/01/10 01:02:47 markd Exp $

BUILDLINK_TREE+=	eigen

.if !defined(EIGEN_BUILDLINK3_MK)
EIGEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eigen+=	eigen>=2.0beta3
BUILDLINK_PKGSRCDIR.eigen?=	../../math/eigen2
BUILDLINK_DEPMETHOD.eigen?=	build
.endif # EIGEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-eigen
