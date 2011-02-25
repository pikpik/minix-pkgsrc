# $NetBSD$
#

PKGNAME=	clang-2.9-trunk
CATEGORIES=	minix
MASTER_SITES=	http://www.minix3.org/distfiles-minix/
SVNREV=		125950
DISTNAME=	llvm-clang-r${SVNREV}

MAINTAINER=	ben@minix3.org
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

WRKSRC=			${WRKDIR}/llvm

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
