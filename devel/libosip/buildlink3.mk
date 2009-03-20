# $NetBSD: buildlink3.mk,v 1.9 2008/11/11 22:02:42 schwarz Exp $

BUILDLINK_TREE+=	libosip2

.if !defined(LIBOSIP2_BUILDLINK3_MK)
LIBOSIP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libosip2+=	libosip2>=2.2.0
BUILDLINK_ABI_DEPENDS.libosip2+=	libosip2>=3.2.0
BUILDLINK_PKGSRCDIR.libosip2?=	../../devel/libosip
.endif # LIBOSIP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libosip2
