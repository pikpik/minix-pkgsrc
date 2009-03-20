# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:59 jlam Exp $

BUILDLINK_TREE+=	libmatheval

.if !defined(LIBMATHEVAL_BUILDLINK3_MK)
LIBMATHEVAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmatheval+=	libmatheval>=1.1.0
BUILDLINK_ABI_DEPENDS.libmatheval+=	libmatheval>=1.1.1nb3
BUILDLINK_PKGSRCDIR.libmatheval?=	../../math/libmatheval

.include "../../devel/flex/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.endif # LIBMATHEVAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmatheval
