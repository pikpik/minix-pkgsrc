# $NetBSD$

BUILDLINK_TREE+=	yamcha

.if !defined(YAMCHA_BUILDLINK3_MK)
YAMCHA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yamcha+=	yamcha>=0.33
BUILDLINK_PKGSRCDIR.yamcha?=	../../textproc/yamcha

.include "../../math/TinySVM/buildlink3.mk"
.endif # YAMCHA_BUILDLINK3_MK

BUILDLINK_TREE+=	-yamcha
