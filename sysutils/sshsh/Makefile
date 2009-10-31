# $NetBSD: Makefile,v 1.4 2004/12/03 15:15:10 wiz Exp $
#

DISTNAME=		sshsh-1.0
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Run a new shell with an SSH identity

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
BUILD_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
