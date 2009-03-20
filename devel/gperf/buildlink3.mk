# $NetBSD: buildlink3.mk,v 1.8 2007/10/13 18:35:35 adam Exp $

BUILDLINK_TREE+=	gperf

.if !defined(GPERF_BUILDLINK3_MK)
GPERF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gperf+=	gperf>=3.0.1
BUILDLINK_PKGSRCDIR.gperf?=	../../devel/gperf
BUILDLINK_DEPMETHOD.gperf?=	build
.endif # GPERF_BUILDLINK3_MK

BUILDLINK_TREE+=	-gperf
