# $NetBSD: Makefile,v 1.2 2000/05/20 19:36:24 jlam Exp $

PKGNAME=		tk-${DISTNAME}

DEPENDS+=		tcl-postgresql-${PG_VERS}:../../databases/tcl-postgresql
DEPENDS+=		tk-8.3.2:../../x11/tk

TCLSH=			${LOCALBASE}/bin/tclsh
TCL_INCDIR=		${LOCALBASE}/include
TCL_CONFIGDIR=		${LOCALBASE}/lib

TK_INCDIR=		${LOCALBASE}/include
TK_CONFIGDIR=		${LOCALBASE}/lib

USE_X11=		# defined

MAKE_ENV+=		INSTALLED_LIBPQ=1 INSTALLED_LIBPGTCL=1

CONFIGURE_ARGS+=	--without-perl --without-odbc
CONFIGURE_ARGS+=	--with-tcl \
			--with-tclconfig="${TCL_CONFIGDIR}" \
			--with-tkconfig="${TK_CONFIGDIR}" \
			--with-includes="${TCL_INCDIR} ${TK_INCDIR}" \
			--with-libraries="${LOCALBASE}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"

do-build:
	cd ${WRKSRC}/bin/pgtclsh && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} pgtksh

do-install:
	cd ${WRKSRC}/bin/pgtclsh && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} install_tk
	strip ${PREFIX}/bin/pgtksh
	${GTAR} zxCf ${PREFIX}/man \
		${WRKDIR}/${DISTNAME}/doc/man.tar.gz \
		`${SED} -e "s/#.*//" ${FILESDIR}/man.tk`

.include "../../databases/postgresql/Makefile.common"
