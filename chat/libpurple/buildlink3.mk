# $NetBSD: buildlink3.mk,v 1.30 2012/04/27 12:31:35 obache Exp $

BUILDLINK_TREE+=	libpurple

.if !defined(LIBPURPLE_BUILDLINK3_MK)
LIBPURPLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpurple+=	libpurple>=2.7.9
BUILDLINK_ABI_DEPENDS.libpurple+=	libpurple>=2.10.4nb1
BUILDLINK_PKGSRCDIR.libpurple?=	../../chat/libpurple

pkgbase := libpurple
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libpurple:Mdbus)
.  include "../../sysutils/dbus/buildlink3.mk"
.  include "../../sysutils/dbus-glib/buildlink3.mk"
.  include "../../sysutils/py-dbus/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.libpurple:Mfarsight)
.  include "../../multimedia/farsight2/buildlink3.mk"
.endif
.if empty(PKG_BUILD_OPTIONS.libpurple:Mgnutls)
.  include "../../devel/nss/buildlink3.mk"
.endif
.endif # LIBPURPLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpurple
