# $NetBSD: Makefile,v 1.9 2010/01/17 12:02:33 wiz Exp $
#

PKGNAME=	nagios-plugin-ldap-${PLUGINSVERSION}
CATEGORIES=	net sysutils databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Nagios ldap plugin
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	nagios-plugins-${PLUGINSVERSION}{,nb[0-9]*}:../../net/nagios-plugins

.include "../../net/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_ldap

.include "../../net/nagios-plugins/Makefile.plugin"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
