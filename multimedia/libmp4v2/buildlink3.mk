# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/02/09 19:57:48 drochner Exp $

BUILDLINK_TREE+=	libmp4v2

.if !defined(LIBMP4V2_BUILDLINK3_MK)
LIBMP4V2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmp4v2+=	libmp4v2>=1.5.0.1
BUILDLINK_PKGSRCDIR.libmp4v2?=	../../multimedia/libmp4v2
.endif # LIBMP4V2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmp4v2
