# $NetBSD: buildlink3.mk,v 1.22 2008/03/24 23:40:37 tnn Exp $

BUILDLINK_TREE+=	binutils

.if !defined(BINUTILS_BUILDLINK3_MK)
BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.binutils+=	binutils>=2.21
BUILDLINK_PKGSRCDIR.binutils?=	../../wip/binutils
BUILDLINK_DEPMETHOD.binutils?=	build
.endif # BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-binutils
