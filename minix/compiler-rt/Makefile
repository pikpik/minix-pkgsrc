# Original by Brooks Davis taken from FreeBSD and modified by beng@

DISTNAME=	compiler-rt-r${SVNREV}
SVNREV=		147747
PKGNAME=	compiler-rt-3.1
PKGREVISION=	${SVNREV}00	
MAINTAINER=	ben@minix3.org
COMMENT=	libgcc replacement
MASTER_SITES=        ${MASTER_SITE_MINIX}
CATEGORIES=	minix

BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

#WRKSRC=                 ${WRKDIR}/$(SVN_REPOSITORIES)

INSTALL_DIRS= ${WRKDIR}/build
CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=../${DISTNAME}
BUILD_DIRS=		${WRKDIR}/build
INSTALL_DIRS=		${WRKDIR}/build

CMAKE_SOURCE_PATH=	${WRKSRC}

.include "../../mk/bsd.prefs.mk"

USE_CMAKE=	yes
USE_GCC=	4.2+
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	VERBOSE=1
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	include/Block.h \
		include/Block_private.h \
		lib/libBlocksRuntime.so

.if ${MACHINE_ARCH} == "i386"
CFLAGS+=	-march=i486
.elif ${MACHINE_ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

SUBST_CLASSES=fixtest
SUBST_STAGE.fixtest=post-patch
SUBST_MESSAGE.fixtest=Removing broken tests
SUBST_FILES.fixtest=test/CMakeLists.txt
SUBST_SED.fixtest+=	-e 's/\(MACRO_ADD_CHECK_TEST( powixf2_test\)/\# \1/'
SUBST_SED.fixtest+=	-e 's/\(MACRO_ADD_CHECK_TEST( clear_cache_test\)/\# \1/'
SUBST_SED.fixtest+=	-e 's/\(MACRO_ADD_CHECK_TEST( enable_execute_stack_test\)/\# \1/'

post-extract:
	${MV} ${WRKDIR}/compiler-rt  ${WRKDIR}/${DISTNAME}
	${MKDIR} ${WRKDIR}/build

regression-test:
	cd ${BUILD_DIRS} && make test

do-install:
	${MKDIR} ${PREFIX}/compiler-rt/lib/
	${INSTALL_LIB} ${BUILD_DIRS}/lib/libCompilerRT-Generic.a ${PREFIX}/compiler-rt/lib/
	${INSTALL_LIB} ${BUILD_DIRS}/lib/libCompilerRT-Generic.a ${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
