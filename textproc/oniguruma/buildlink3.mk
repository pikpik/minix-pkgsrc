# $NetBSD: buildlink3.mk,v 1.2 2008/08/09 17:52:57 ahoka Exp $

BUILDLINK_TREE+=	oniguruma

.if !defined(ONIGURUMA_BUILDLINK3_MK)
ONIGURUMA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.oniguruma+=	oniguruma>=5.9.1
BUILDLINK_PKGSRCDIR.oniguruma?=	../../textproc/oniguruma
.endif # ONIGURUMA_BUILDLINK3_MK

BUILDLINK_TREE+=	-oniguruma
