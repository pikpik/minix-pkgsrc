# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:07 jlam Exp $

BUILDLINK_TREE+=	libksba

.if !defined(LIBKSBA_BUILDLINK3_MK)
LIBKSBA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libksba+=	libksba>=0.4.7nb1
BUILDLINK_ABI_DEPENDS.libksba+=	libksba>=0.4.7nb2
BUILDLINK_PKGSRCDIR.libksba?=	../../security/libksba04
.endif # LIBKSBA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libksba
