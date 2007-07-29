# $NetBSD: Makefile,v 1.7 2006/06/30 15:37:22 salo Exp $

DISTNAME=	suse_locale-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators

CONFLICTS=	linux-locale-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package with locale files

EMUL_MODULES.linux=	base

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
