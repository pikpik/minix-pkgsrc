# $NetBSD: Makefile,v 1.3 2005/11/03 17:00:38 tv Exp $
#

DISTNAME=	netgroup-0.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.astron.com/pub/netgroup/

MAINTAINER=	christos@NetBSD.org
COMMENT=	Netgroup membership listing and testing functions

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	Interix-*-* # no netgroups

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALL_TARGET=	inst-all
INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
