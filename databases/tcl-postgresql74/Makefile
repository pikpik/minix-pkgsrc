# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:16 tv Exp $

PKGNAME=		tcl-postgresql74-${BASE_VERS}
COMMENT=		Tcl interface to PostgreSQL

.include "../postgresql74/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh
MAKE_ENV+=		INSTALLED_LIBPQ=1

BUILD_DIRS=		${WRKSRC}/src/port
BUILD_DIRS+=		${WRKSRC}/src/interfaces/libpgtcl
BUILD_DIRS+=		${WRKSRC}/src/bin/pgtclsh

post-install:
	${GTAR} zxCf ${PREFIX}/man ${WRKSRC}/doc/man.tar.gz		\
		`${SED} -e "s|#.*||" ${FILESDIR}/man.tcl`

.include "../postgresql74-lib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
