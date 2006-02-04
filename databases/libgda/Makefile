# $NetBSD: Makefile,v 1.16 2006/01/24 07:31:59 wiz Exp $
#

.include "Makefile.common"

PKGCONFIG_OVERRIDE=	libgda-2.0.pc.in

PKG_SYSCONFSUBDIR=	libgda
EGDIR=			${PREFIX}/share/examples/libgda
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

CONFIGURE_ARGS+=	--with-odbc=no --with-bdb=no

post-install:
	${RMDIR} ${PREFIX}/lib/libgda

.include "../../mk/bsd.pkg.mk"
