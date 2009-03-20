# $NetBSD: buildlink3.mk,v 1.8 2008/09/08 08:38:10 obache Exp $

BUILDLINK_TREE+=	libdca

.if !defined(LIBDCA_BUILDLINK3_MK)
LIBDCA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdca+=	libdca>=0.0.5
BUILDLINK_PKGSRCDIR.libdca?=	../../audio/libdca
.endif # LIBDCA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdca
