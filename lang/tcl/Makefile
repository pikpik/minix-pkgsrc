# $NetBSD: Makefile,v 1.70 2012/11/07 14:30:48 he Exp $

DISTNAME=	tcl${TCL_VERSION}-src
PKGNAME=	tcl-${TCL_VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Tool Command Language, a dynamic language
LICENSE=	2-clause-bsd

.include "../../lang/tcl/Makefile.version"

WRKSRC=			${WRKDIR}/tcl${TCL_VERSION}

USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}

CONFIGURE_ARGS+=	--prefix=${PREFIX}
INSTALL_TARGET=		install

# The test target gives better results when not run as root.
TEST_TARGET=		test

.include "options.mk"

# This is needed for SGI and maybe sun (according to tcl developers)
.if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.endif

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Minix"
CONFIGURE_ENV+=		ac_cv_func_opendir=yes
.endif

SUBST_CLASSES+=		tcl-config
SUBST_STAGE.tcl-config=	post-build
SUBST_FILES.tcl-config=	unix/tclConfig.sh
SUBST_SED.tcl-config+=	-e "s|${WRKSRC}/unix|${PREFIX}/lib|"
SUBST_SED.tcl-config+=	-e "s|${WRKSRC}|${PREFIX}/include/tcl|"

INSTALLATION_DIRS+=	include/tcl
INSTALLATION_DIRS+=	include/tcl/unix
INSTALLATION_DIRS+=	include/tcl/generic
INSTALLATION_DIRS+=	lib/tcl

pre-configure:
	cd ${WRKSRC}/unix && autoconf

post-install:
	if [ ! -f ${DESTDIR:Q}${PREFIX:Q}/bin/tclsh ] ; \
	then \
		cd ${DESTDIR:Q}${PREFIX:Q}/bin && ln -s tclsh8.4 tclsh ; \
	fi
	${INSTALL_DATA} ${WRKSRC}/unix/tclUnixPort.h \
		${DESTDIR:Q}${PREFIX:Q}/include/tcl/unix
.for f in	regex.h tcl.h tclCompile.h tclDecls.h tclIO.h		\
		tclInt.h tclIntDecls.h tclIntPlatDecls.h\
		tclPlatDecls.h tclPort.h tclRegexp.h
	${INSTALL_DATA} ${WRKSRC}/generic/${f} \
		${DESTDIR:Q}${PREFIX:Q}/include/tcl/generic
.endfor

PLIST_SUBST+=		SONUM=${TCL_SONUM}
PLIST_SUBST+=		BASEVER=${TCL_BASEVER}

.include "../../mk/bsd.pkg.mk"
