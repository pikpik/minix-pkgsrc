# $NetBSD$
#

DISTNAME=	llvm-2.6
SVN_TAG=	109091
CATEGORIES=	lang
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl:build chown groff
USE_LANGUAGES+=	c c++
MAKE_DIRS+=	etc/llvm
USE_LIBTOOL=	yes

CONFIGURE_ARGS=	--enable-bindings=none	# no OCaml, please!

INSTALLATION_DIRS=	bin lib libexec

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Minix"
CXXFLAGS+= -D_POSIX_SOURCE
CONFIGURE_ARGS+= --disable-jit 
CONFIGURE_ARGS+= --enable-targets=x86
CONFIGURE_ARGS+= --disable-shared
CONFIGURE_ARGS+= --disable-llvm-dynamic-plugins
CONFIGURE_ARGS+= --disable-threads
CONFIGURE_ARGS+= --disable-pic
CONFIGURE_ARGS+= --disable-llvmc-dynamic 
CONFIGURE_ARGS+= --disable-llvmc-dynamic-plugins
CONFIGURE_ARGS+= --disable-libtool-lock
CONFIGURE_ARGS+= --enable-optimized
CONFIGURE_ARGS+= --disable-assertions
CONFIGURE_ENV+= AR=ar AS=as LD=ld NM=nm
.else
# This should be changed!
CONFIGURE_ARGS+= --enable-targets=host-only
CONFIGURE_ARGS+= --disable-optimized
.endif

#CONF_FILES=	share/examples/llvm/c etc/llvm/c
#CONF_FILES+=	share/examples/llvm/c++ etc/llvm/c++
#CONF_FILES+=	share/examples/llvm/cpp etc/llvm/cpp
#CONF_FILES+=	share/examples/llvm/cxx etc/llvm/cxx
#CONF_FILES+=	share/examples/llvm/ll etc/llvm/ll
#CONF_FILES+=	share/examples/llvm/st etc/llvm/st

#.include "../../lang/ocaml/buildlink3.mk"
TEST_TARGET=	check unittests

post-extract:
	${MV} ${WRKDIR}/clang ${WRKDIR}/llvm/tools/clang

# Get it from Subversion repository:
SVN_REPOSITORIES=	llvm clang
SVN_ROOT.llvm=		http://llvm.org/svn/llvm-project/llvm/trunk
SVN_MODULE.llvm=	llvm
SVN_ROOT.clang=		http://llvm.org/svn/llvm-project/cfe/trunk
SVN_MODULE.clang=	clang

PKGNAME=		clang-2.7.99
WRKSRC=			$(WRKDIR)/$(SVN_MODULE.llvm)

CHECK_PORTABILITY_SKIP= utils/buildit/.svn/text-base/build_llvm.svn-base \
			utils/buildit/build_llvm


.include "../../wip/mk/svn-package.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
