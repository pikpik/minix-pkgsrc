# $NetBSD: buildlink3.mk,v 1.7 2008/07/17 10:11:19 ahoka Exp $

BUILDLINK_TREE+=	liblive

.if !defined(LIBLIVE_BUILDLINK3_MK)
LIBLIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblive+=	liblive>=20080706
BUILDLINK_ABI_DEPENDS.liblive+=	liblive>=20080706
BUILDLINK_PKGSRCDIR.liblive?=	../../net/liblive
BUILDLINK_INCDIRS.liblive+=     include/BasicUsageEnvironment
BUILDLINK_INCDIRS.liblive+=     include/UsageEnvironment
BUILDLINK_INCDIRS.liblive+=     include/groupsock
BUILDLINK_INCDIRS.liblive+=     include/liveMedia
.endif # LIBLIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblive
