# $NetBSD$
#

PKGNAME=	clang-2.9
CATEGORIES=	minix
MASTER_SITES=	http://www.minix3.org/distfiles-minix/
SVNREV=		125950
DISTNAME=	llvm-clang-r${SVNREV}
PKGREVISION=	5

# Avoid dependency on lang/gcc44
MINIX_GCC_NODEP=yes

MAINTAINER=	ben@minix3.org
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure
DEPENDS+=       binutils>=2.17nb3:../../devel/binutils
DEPENDS+=       compiler-rt>=3.1:../../minix/compiler-rt

CONFLICTS+= clang-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

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

#.include "../../lang/ocaml/buildlink3.mk"

TEST_TARGET=	check unittests

post-extract:
	${MV} ${WRKDIR}/clang ${WRKDIR}/llvm/tools/clang

WRKSRC=			${WRKDIR}/llvm

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
