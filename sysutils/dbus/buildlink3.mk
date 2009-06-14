# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:25:23 joerg Exp $

BUILDLINK_TREE+=	dbus

.if !defined(DBUS_BUILDLINK3_MK)
DBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dbus+=	dbus>=0.91
BUILDLINK_PKGSRCDIR.dbus?=	../../sysutils/dbus

.include "../../textproc/expat/buildlink3.mk"
.endif # DBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-dbus
