# $NetBSD$
#
# This file holds make(1) logic to allow obsolete or deprecated variables
# still to be used.  These may eventually disappear over time as the contents
# are, by definition, obsolete and deprecated.

.if defined(APACHE_SYSCONFDIR)
PKG_SYSCONFDIR.ap-ssl?=		${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.apache?=		${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.apache6?=	${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.imp?=		${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.horde?=		${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.squirrelmail?=	${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.stripes?=	${APACHE_SYSCONFDIR}
.endif

.if defined(PHP_CONFDIR)
PKG_SYSCONFDIR.php?=		${PHP_CONFDIR}
.endif

.if defined(VTUN_SYSCONFDIR)
PKG_SYSCONFDIR.vtun?=		${VTUN_SYSCONFDIR}
.endif
