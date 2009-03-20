# $NetBSD: buildlink3.mk,v 1.11 2008/11/08 21:06:46 bjs Exp $

BUILDLINK_TREE+=	speex

.if !defined(SPEEX_BUILDLINK3_MK)
SPEEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.speex+=	speex>=1.2rc1
BUILDLINK_PKGSRCDIR.speex?=	../../audio/speex

.include "../../multimedia/libogg/buildlink3.mk"
.endif # SPEEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-speex
