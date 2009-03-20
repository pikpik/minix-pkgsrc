# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:12 jlam Exp $

BUILDLINK_TREE+=	libghttp

.if !defined(LIBGHTTP_BUILDLINK3_MK)
LIBGHTTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libghttp+=	libghttp>=1.0.9
BUILDLINK_ABI_DEPENDS.libghttp+=	libghttp>=1.0.9nb1
BUILDLINK_PKGSRCDIR.libghttp?=	../../www/libghttp
.endif # LIBGHTTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libghttp
