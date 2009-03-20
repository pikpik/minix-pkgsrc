# $NetBSD: buildlink3.mk,v 1.12 2007/06/05 05:35:20 wiz Exp $

BUILDLINK_TREE+=	opencdk

.if !defined(OPENCDK_BUILDLINK3_MK)
OPENCDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencdk+=	opencdk>=0.5.4nb1
BUILDLINK_ABI_DEPENDS.opencdk+=	opencdk>=0.6.0
BUILDLINK_PKGSRCDIR.opencdk?=	../../security/opencdk

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.endif # OPENCDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencdk
