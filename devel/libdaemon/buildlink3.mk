# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/12/20 17:24:48 ahoka Exp $

BUILDLINK_TREE+=	libdaemon

.if !defined(LIBDAEMON_BUILDLINK3_MK)
LIBDAEMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdaemon+=	libdaemon>=0.10
BUILDLINK_PKGSRCDIR.libdaemon?=		../../devel/libdaemon
.endif # LIBDAEMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdaemon
