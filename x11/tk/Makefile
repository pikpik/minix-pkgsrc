# $NetBSD: Makefile,v 1.69 2012/11/24 21:38:50 adam Exp $

DISTNAME=	tk${TK_VERSION}-src
PKGNAME=	tk-${TK_VERSION}
PKGREVISION=	1
CATEGORIES=	x11 lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Graphical toolkit for TCL
LICENSE=	2-clause-bsd

.include "../../x11/tk/Makefile.version"

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/tk${TK_VERSION}

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib${LIBABISUFFIX:Q}
CONFIGURE_ENV+=		LIB_RUNTIME_DIR=${PREFIX}/lib
PTHREAD_OPTS+=		require
USE_TOOLS+=			autoconf

TEST_TARGET=		test

.if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.endif

.include "options.mk"

SUBST_CLASSES+=		tk-config
SUBST_STAGE.tk-config=	post-build
SUBST_FILES.tk-config=	unix/tkConfig.sh
SUBST_SED.tk-config+=	-e "s|${WRKSRC}/unix|${PREFIX}/lib|"
SUBST_SED.tk-config+=	-e "s|${WRKSRC}|${PREFIX}/include/tk|"

PLIST_SUBST+=		SONUM=${TK_SONUM}
PLIST_SUBST+=		BASEVER=${TK_BASEVER}

.include "../../mk/bsd.prefs.mk"

pre-configure:
	cd ${WRKSRC}/unix && autoconf

post-install:
	rm -f ${DESTDIRPREFIX:Q}/bin/wish
	ln -s wish8.4 ${DESTDIRPREFIX:Q}/bin/wish
	${INSTALL_DATA} ${WRKSRC}/generic/default.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/ks_names.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tk.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tk3d.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkButton.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkCanvas.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkColor.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkDecls.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkFileFilter.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkFont.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkInitScript.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkInt.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkIntDecls.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkIntPlatDecls.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkIntXlibDecls.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkMenu.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkMenubutton.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkPlatDecls.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkPort.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkScale.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkScrollbar.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkSelect.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkText.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkUndo.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/unix/tkUnixDefault.h ${DESTDIRPREFIX:Q}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/unix/tkUnixInt.h ${DESTDIRPREFIX:Q}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/unix/tkUnixPort.h ${DESTDIRPREFIX:Q}/include/tk/unix

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--enable-aqua
.else
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.endif

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
