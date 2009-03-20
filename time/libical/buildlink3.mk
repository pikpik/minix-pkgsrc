# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/12/19 21:48:05 markd Exp $

BUILDLINK_TREE+=	libical

.if !defined(LIBICAL_BUILDLINK3_MK)
LIBICAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libical+=	libical>=0.42
BUILDLINK_PKGSRCDIR.libical?=	../../time/libical
.endif # LIBICAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libical
