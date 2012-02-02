# $NetBSD$
#

PKGNAME=	clang-3.1
CATEGORIES=	minix
MASTER_SITES=	${MASTER_SITE_MINIX}
SVNREV=		146353
PKGREVISION=	2
DISTNAME=	llvm-clang-klee-r${SVNREV}

USE_PYTHON=	yes
PYTHON_FOR_BUILD_ONLY= yes
PY_PATCHPLIST= yes
REPLACE_PYTHON=	utils/llvm-build/llvm-build \
	utils/lit/lit.py 	\
	test/Scripts/macho-dumpx	\
	test/Scripts/coff-dump.py	\
	test/Scripts/elf-dump	\
	utils/Target/ARM/analyze-match-table.py	\
	utils/Misc/zkill	\
	utils/lit/lit/ProgressBar.py	\
	utils/lit/lit/main.py	\
	utils/llvm-lit/llvm-lit.in	\
	utils/clang-parse-diagnostics-file	\
	tools/clang/www/builtins.py	\
	tools/clang/bindings/python/examples/cindex/cindex-dump.py	\
	tools/clang/bindings/python/examples/cindex/cindex-includes.py	\
	tools/clang/utils/analyzer/*.py	\
	tools/clang/utils/analyzer/ubiviz	\
	tools/clang/utils/ABITest/ABITestGen.py	\
	tools/clang/utils/C++Tests/LLVM-Code-Symbols/check-symbols	\
	tools/clang/utils/TestUtils/deep-stack.py	\
	tools/clang/utils/CIndex/completion_logger_server.py	\
	tools/clang/utils/CaptureCmd	\
	tools/clang/utils/CmpDriver	\
	tools/clang/utils/token-delta.py	\
	tools/clang/utils/FuzzTest	\
	tools/clang/utils/SummarizeErrors	\
	tools/clang/utils/FindSpecRefs	\
	tools/clang/tools/scan-build/set-xcode-analyzer	\
	tools/clang/tools/scan-view/scan-view	\
	klee/scripts/klee-gcc	\
	klee/tools/ktest-tool/ktest-tool	\
	klee/tools/klee-stats/klee-stats

# Avoid dependency on lang/gcc44
MINIX_GCC_NODEP=yes

CONFLICTS+= clang-[0-9]*

MAINTAINER=	ben@minix3.org
HOMEPAGE=	http://llvm.org/
COMMENT=	c compiler: llvm, clang and klee packaged together
DEPENDS+=       binutils>=2.17nb3:../../devel/binutils
DEPENDS+=       compiler-rt>=3.1:../../minix/compiler-rt

PKG_DESTDIR_SUPPORT=destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl:build chown groff
USE_LANGUAGES=  c c++
_USE_GCC_SHLIB=	no
MAKE_DIRS+=	etc/llvm
USE_LIBTOOL=	yes

CONFIGURE_ARGS=	--enable-bindings=none	# no OCaml, please!

INSTALLATION_DIRS=	bin lib libexec

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Minix"
CXXFLAGS+= -D_POSIX_SOURCE
CONFIGURE_ARGS+= --disable-shared
CONFIGURE_ARGS+= --disable-llvm-dynamic-plugins
CONFIGURE_ARGS+= --disable-threads
CONFIGURE_ARGS+= --disable-pic
CONFIGURE_ARGS+= --disable-llvmc-dynamic 
CONFIGURE_ARGS+= --disable-llvmc-dynamic-plugins
CONFIGURE_ARGS+= --disable-libtool-lock
CONFIGURE_ARGS+= --enable-optimized
CONFIGURE_ARGS+= --disable-assertions
.else
# This should be changed!
CONFIGURE_ARGS+= --enable-targets=host-only
CONFIGURE_ARGS+= --disable-optimized
.endif

SUBST_CLASSES+=         python
SUBST_STAGE.python=     pre-configure
SUBST_FILES.python=     klee/configure
SUBST_SED.python=       -e "s,python -c ,${PYTHONBIN} -c ,"

.if ${OPSYS} == "Minix"
SUBST_CLASSES+=         sharedlibrary
SUBST_STAGE.sharedlibrary=     pre-configure
SUBST_FILES.sharedlibrary=     runtime/libprofile/Makefile tools/clang/tools/libclang/Makefile 
SUBST_SED.sharedlibrary=       -e 's/SHARED_LIBRARY.*1/\#&/' -e 's/LINK_LIBS_IN_SHARED.*1/\#&/'
.endif

TEST_TARGET=	check unittests

KLEE=${WRKDIR}/llvm/klee

post-extract:
	${MV} ${WRKDIR}/clang ${WRKDIR}/llvm/tools/clang
	${MV} ${WRKDIR}/klee ${KLEE}

post-build:
	cd ${KLEE} && CPPFLAGS=-DUSE_KLEE_LIB_DIR=1 ./configure --prefix=${PREFIX} --with-llvm=${WRKDIR}/llvm --with-stp=${PREFIX}
	cd ${KLEE} && gmake ENABLE_OPTIMIZED=1 LLVMCC_OPTION=clang ENABLE_BUILT_CLANG=1

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/llvm/tools/clang/tools/scan-build/* ${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-build/ccc-analyzer \
		${WRKSRC}/tools/clang/tools/scan-build/c++-analyzer \
		${WRKSRC}/tools/clang/tools/scan-build/scan-build \
		${WRKSRC}/tools/clang/tools/scan-view/scan-view \
		${DESTDIR}${PREFIX}/bin
	${MKDIR} ${DESTDIR}${PYSITELIB}
	${MKDIR} ${DESTDIR}${PYSITELIB}/Resources
	${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-view/*.py \
		${DESTDIR}${PYSITELIB}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-view/Resources/* \
		${DESTDIR}${PYSITELIB}/Resources	
	${MKDIR} ${DESTDIR}${PREFIX}/share	
	${INSTALL_DATA} ${WRKSRC}/tools/clang/tools/scan-build/scanview.css ${DESTDIR}${PREFIX}/share	
	${INSTALL_DATA} ${WRKSRC}/tools/clang/tools/scan-build/sorttable.js ${DESTDIR}${PREFIX}/share	
	cd ${KLEE} && gmake DESTDIR=${DESTDIR} install

WRKSRC=			${WRKDIR}/llvm

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../minix/stp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
