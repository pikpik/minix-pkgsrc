# $NetBSD: Makefile,v 1.26 2009/08/24 13:50:03 hasso Exp $
#

.include "../../security/libpreludedb/Makefile.common"
.include "../../mk/bsd.prefs.mk"

COMMENT=		LibPreludeDB libraries

CONFIGURE_ARGS+=	--with-perl=no
CONFIGURE_ARGS+=	--with-python=no
CONFIGURE_ARGS+=	--with-mysql=no
CONFIGURE_ARGS+=	--with-postgresql=no
CONFIGURE_ARGS+=	--with-sqlite3=no

post-install:
	${INSTALL_DATA} ${FILESDIR}/addIndices.sql ${DESTDIR}${PREFIX}/share/libpreludedb/classic

.include "../../security/libprelude/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
