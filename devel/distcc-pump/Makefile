# $NetBSD$

PKGNAME=	${DISTNAME:S/-/-pump-/}
COMMENT=	Accelerated remote compilation with distcc

.include "../../devel/distcc/Makefile.common"

PY_PATCHPLIST=		yes

# check patch-ae for build and install targets
BUILD_TARGET=		pump include-server
INSTALL_TARGET=		install-include-server

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
