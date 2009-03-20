# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:11:05 jlam Exp $

BUILDLINK_TREE+=	pvm

.if !defined(PVM_BUILDLINK3_MK)
PVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pvm+=		pvm>=3.4.3
BUILDLINK_ABI_DEPENDS.pvm+=	pvm>=3.4.5nb1
BUILDLINK_PKGSRCDIR.pvm?=	../../parallel/pvm3

.  include "${BUILDLINK_PKGSRCDIR.pvm}/arch.mk"
BUILDLINK_INCDIRS.pvm?=		pvm3/include
BUILDLINK_LIBDIRS.pvm?=		pvm3/lib/${PVM_ARCH}
.endif # PVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-pvm
