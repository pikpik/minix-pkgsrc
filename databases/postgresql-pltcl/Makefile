# $NetBSD: Makefile,v 1.5 2002/04/04 07:41:04 jlam Exp $

PKGNAME=		postgresql-pltcl-${BASE_VERS}
COMMENT=		PL/Tcl procedural language for the PostgreSQL backend

DEPENDS+=		postgresql-server>=${BASE_VERS}:../../databases/postgresql-server

USE_BUILDLINK2=		# defined

.include "../../databases/postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${LOCALBASE}/bin/tclsh

BUILD_DIRS=		${WRKSRC}/src/pl/tcl

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
