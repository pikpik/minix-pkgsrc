# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/14 22:58:06 wiz Exp $

BUILDLINK_TREE+=	libtelepathy

.if !defined(LIBTELEPATHY_BUILDLINK3_MK)
LIBTELEPATHY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtelepathy+=	libtelepathy>=0.3.3
BUILDLINK_PKGSRCDIR.libtelepathy?=	../../chat/libtelepathy

.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.endif # LIBTELEPATHY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtelepathy
