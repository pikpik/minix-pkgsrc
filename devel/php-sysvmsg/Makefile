# $NetBSD$

MODNAME=		sysvmsg
CATEGORIES+=		devel
COMMENT=		PHP extension for SysV IPC Message Queues support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
