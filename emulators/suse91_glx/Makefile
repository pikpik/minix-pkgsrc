# $NetBSD: Makefile,v 1.9 2006/06/30 15:37:22 salo Exp $

DISTNAME=	suse_glx-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	Linux compatibility package for OpenGL/Mesa

EMUL_MODULES.linux=	base x11

# This symlink is managed by ldconfig(8).
CHECK_FILES_SKIP+=	${EMULDIR}/usr/${LINUX_LIBSUBDIR}/libglide3.so.3

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
