# $NetBSD: buildlink3.mk,v 1.2 2008/07/25 13:59:39 obache Exp $

BUILDLINK_TREE+=	libmpcdec

.if !defined(LIBMPCDEC_BUILDLINK3_MK)
LIBMPCDEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmpcdec+=	libmpcdec>=1.2.4
BUILDLINK_ABI_DEPENDS.libmpcdec+=	libmpcdec>=1.2.6
BUILDLINK_PKGSRCDIR.libmpcdec?=	../../audio/libmpcdec
.endif # LIBMPCDEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmpcdec
