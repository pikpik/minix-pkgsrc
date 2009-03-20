# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:03 jlam Exp $

BUILDLINK_TREE+=	freewais-sf

.if !defined(FREEWAIS_SF_BUILDLINK3_MK)
FREEWAIS_SF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freewais-sf+=	freewais-sf>=2.2.12
BUILDLINK_ABI_DEPENDS.freewais-sf+=	freewais-sf>=2.2.12nb2
BUILDLINK_PKGSRCDIR.freewais-sf?=	../../net/freewais-sf
.endif # FREEWAIS_SF_BUILDLINK3_MK

BUILDLINK_TREE+=	-freewais-sf
