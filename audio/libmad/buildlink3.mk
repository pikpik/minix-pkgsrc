# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:10:36 jlam Exp $

BUILDLINK_TREE+=	libmad

.if !defined(LIBMAD_BUILDLINK3_MK)
LIBMAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmad+=	libmad>=0.15.0b
BUILDLINK_ABI_DEPENDS.libmad+=	libmad>=0.15.1bnb1
BUILDLINK_PKGSRCDIR.libmad?=	../../audio/libmad
.endif # LIBMAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmad
