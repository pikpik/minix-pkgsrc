# $NetBSD: buildlink3.mk,v 1.3 2006/07/08 23:10:37 jlam Exp $

BUILDLINK_TREE+=	libvisual0.2

.if !defined(LIBVISUAL0.2_BUILDLINK3_MK)
LIBVISUAL0.2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvisual0.2+=	libvisual0.2>=0.2.0
BUILDLINK_PKGSRCDIR.libvisual0.2?=	../../audio/libvisual0.2
.endif # LIBVISUAL0.2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvisual0.2
