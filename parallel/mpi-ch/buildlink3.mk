# $NetBSD: buildlink3.mk,v 1.12 2008/05/29 20:27:47 tnn Exp $

BUILDLINK_TREE+=	mpich2

.if !defined(MPICH2_BUILDLINK3_MK)
MPICH2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpich2+=	mpich2>=1.0.7
BUILDLINK_PKGSRCDIR.mpich2?=	../../parallel/mpi-ch
BUILDLINK_DEPMETHOD.mpich2?=	build
.endif # MPICH2_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpich2
