# $NetBSD$
#

PKGNAME=	clang_new
CATEGORIES=	minix
MASTER_SITES=	${MASTER_SITE_MINIX}
SVNREV=		145807
DISTNAME=	llvm-clang-klee-r${SVNREV}

USE_PYTHON=	yes
PYTHON_FOR_BUILD_ONLY= yes
REPLACE_PYTHON=	utils/llvm-build/llvm-build \
	utils/lit/lit.py 	\
	test/Scripts/macho-dumpx	\
	test/Scripts/coff-dump.py	\
	test/Scripts/elf-dump	\
	utils/Target/ARM/analyze-match-table.py	\
	utils/Misc/zkill	\
	utils/lit/lit/ProgressBar.py	\
	utils/lit/lit/main.py.orig	\
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

CONFLICTS= clang*

MAINTAINER=	ben@minix3.org
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure
DEPENDS+=       binutils>=2.17nb3:../../devel/binutils
DEPENDS+=       compiler-rt-r145807:../../minix/compiler-rt_new

USE_DESTDIR=no

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

TEST_TARGET=	check unittests

KLEE=${WRKDIR}/llvm/klee

post-extract:
	${MV} ${WRKDIR}/clang ${WRKDIR}/llvm/tools/clang
	${MV} ${WRKDIR}/klee ${KLEE}

post-build:
	#cd ${KLEE} && ./configure --prefix=${PREFIX} --with-llvm=${WRKDIR}/llvm
	#cd ${KLEE} && gmake ENABLE_OPTIMIZED=1

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/llvm/tools/clang/tools/scan-build/* ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-build/ccc-analyzer \
		${WRKSRC}/tools/clang/tools/scan-build/c++-analyzer \
		${WRKSRC}/tools/clang/tools/scan-build/scan-build \
		${WRKSRC}/tools/clang/tools/scan-view/scan-view \
		${PREFIX}/bin
	${MKDIR} ${PYSITELIB}
	${MKDIR} ${PYSITELIB}/Resources
	${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-view/*.py \
		${PYSITELIB}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/tools/scan-view/Resources/* \
		${PYSITELIB}/Resources	
	${MKDIR} ${PREFIX}/share	
	${INSTALL_DATA} ${WRKSRC}/tools/clang/tools/scan-build/scanview.css ${PREFIX}/share	
	${INSTALL_DATA} ${WRKSRC}/tools/clang/tools/scan-build/sorttable.js ${PREFIX}/share	
	#cd ${KLEE} && gmake install

WRKSRC=			${WRKDIR}/llvm

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
