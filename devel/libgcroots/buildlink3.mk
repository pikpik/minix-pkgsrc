# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/02/29 13:06:36 obache Exp $

BUILDLINK_TREE+=	libgcroots

.if !defined(LIBGCROOTS_BUILDLINK3_MK)
LIBGCROOTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgcroots+=	libgcroots>=0.2.1
BUILDLINK_PKGSRCDIR.libgcroots?=	../../devel/libgcroots
.endif # LIBGCROOTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgcroots
