# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/11/03 14:58:01 rillig Exp $

BUILDLINK_TREE+=	libconfig

.if !defined(LIBCONFIG_BUILDLINK3_MK)
LIBCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libconfig+=	libconfig>=1.1.3
BUILDLINK_PKGSRCDIR.libconfig?=		../../devel/libconfig
.endif # LIBCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libconfig
