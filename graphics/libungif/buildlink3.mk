# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 23:10:52 jlam Exp $

BUILDLINK_TREE+=	libungif

.if !defined(LIBUNGIF_BUILDLINK3_MK)
LIBUNGIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libungif+=	libungif>=4.1.0
BUILDLINK_ABI_DEPENDS.libungif+=	libungif>=4.1.3nb1
BUILDLINK_PKGSRCDIR.libungif?=	../../graphics/libungif
.endif # LIBUNGIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libungif
