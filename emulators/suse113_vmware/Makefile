# $NetBSD$

DISTNAME=	suse_vmware-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES=	grep-2.5.4-7.1.${SUSE_ARCH}.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package to help run VMware

EMUL_MODULES.linux=	base x11
RPMIGNOREPATH=		usr

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
