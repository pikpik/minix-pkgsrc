# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:36 jlam Exp $

BUILDLINK_TREE+=	libmodplug

.if !defined(LIBMODPLUG_BUILDLINK3_MK)
LIBMODPLUG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmodplug+=		libmodplug>=0.7
BUILDLINK_ABI_DEPENDS.libmodplug+=	libmodplug>=0.7nb1
BUILDLINK_PKGSRCDIR.libmodplug?=	../../audio/libmodplug
.endif # LIBMODPLUG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmodplug
