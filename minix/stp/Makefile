# $NetBSD$
#

DISTNAME=	stp-r${SVNREV}
PKGNAME=	stp-1.0
WORKDIR=	stp
PKGREVISION=	${SVNREV}
SVNREV=		1434
CATEGORIES=	minix
MASTER_SITES=	http://www.minix3.org/distfiles-minix/
WRKSRC=         ${WRKDIR}/stp

USE_TOOLS+=	perl bash gmake bison
USE_LANGUAGES=	c c++
HAS_CONFIGURE=	yes

# Put bash where /bin/bash is hardcoded
REPLACE_BASH=	scripts/liblinks.sh	\
		tests/generated_tests/runMulDivRem.sh	\
		unit_test/unit_test.sh

REPLACE_PERL= scripts/run_tests.pl	\
		src/AST/genkinds.pl	\
		tests/crypto-tests/tea.pl	\
		tests/generated_tests/run-experiments.pl	\
		tests/generated_tests/testgen.pl	\
		tests/generated_tests/extract.pl

SUBST_CLASSES+=      bash
SUBST_STAGE.bash=    post-extract
SUBST_FILES.bash=    scripts/Makefile.common
SUBST_SED.bash=      -e 's,SHELL=.*bash,SHELL=${TOOLS_PATH.bash},'

SUBST_CLASSES+=      bison
SUBST_STAGE.bison=    post-extract
SUBST_FILES.bison=    src/parser/Makefile
SUBST_SED.bison=      -e 's,YACC=.*bison,YACC=${TOOLS_PATH.bison},'

# Recommended by KLEE documentation
BUILD_MAKE_FLAGS=	OPTIMIZE=-O2 CFLAGS_M32= install 

CONFIGURE_SCRIPT=	 scripts/configure 
CONFIGURE_ARGS= --with-prefix=${PREFIX}

MAINTAINER=	ben@minix3.org
HOMEPAGE=	http://sites.google.com/site/stpfastprover/
COMMENT=	C++ constraint solver library
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
.include "../../lang/perl5/buildlink3.mk"

