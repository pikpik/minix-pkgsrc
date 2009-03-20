# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:11:07 jlam Exp $

BUILDLINK_TREE+=	libgpg-error

.if !defined(LIBGPG_ERROR_BUILDLINK3_MK)
LIBGPG_ERROR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=0.6
BUILDLINK_ABI_DEPENDS.libgpg-error+=	libgpg-error>=1.0nb1
BUILDLINK_PKGSRCDIR.libgpg-error?=	../../security/libgpg-error

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # LIBGPG_ERROR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgpg-error
