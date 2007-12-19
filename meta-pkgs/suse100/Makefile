# $NetBSD: Makefile,v 1.9 2007/10/25 22:00:57 jlam Exp $

DISTNAME=	suse-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators meta-pkgs
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SUSE-based Linux binary emulation environment

EMUL_MODULES.linux=	aspell base compat cups expat fontconfig	\
			freetype2 gdk-pixbuf glx gtk gtk2 jpeg locale	\
			motif openssl png slang tiff vmware x11 xml2
EMUL_PKG_FMT=		plain

META_PACKAGE=	yes

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
