# $NetBSD$
#

.include "Makefile.common"

PKG_USERS=	messagebus:messagebus::System\\ message\\ bus:${VARBASE}/run/dbus:/sbin/nologin
PKG_GROUPS=	messagebus

MAKE_DIRS=	${PKG_SYSCONFDIR}/event.d
MAKE_DIRS+=	${PKG_SYSCONFDIR}/system.d
OWN_DIRS_PERMS=	${VARBASE}/run/dbus messagebus messagebus 0755

RCD_SCRIPTS=	dbus

EGDIR=		${PREFIX}/share/examples/dbus
CONF_FILES=	${EGDIR}/session.conf ${PKG_SYSCONFDIR}/session.conf
CONF_FILES+=	${EGDIR}/system.conf ${PKG_SYSCONFDIR}/system.conf

.include "../../mk/bsd.pkg.mk"
