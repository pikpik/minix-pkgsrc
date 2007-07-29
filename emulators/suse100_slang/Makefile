# $NetBSD: Makefile,v 1.4 2007/04/19 15:30:22 xtraeme Exp $

DISTNAME=	suse_slang-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
DISTFILES=	slang-1.4.9-127.${SUSE_ARCH}.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for S-Lang

EMUL_MODULES.linux=	base

# This symlink is managed by ldconfig(8).
CHECK_FILES_SKIP+=	${EMULDIR}/usr/${LINUX_LIBSUBDIR}/libslang.so.1

post-install:
	cd ${EMULDIR}/usr/lib && ${LN} -fs libslang-utf8.so.1 libslang.so.1

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
