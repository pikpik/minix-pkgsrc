# $NetBSD: Makefile,v 1.3 1999/08/31 02:27:51 kim Exp $
#

DISTNAME=		ssync-1.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us

DEPENDS+=		netname-*:../../net/netname
DEPENDS+=		osname-*:../../sysutils/osname
DEPENDS+=		rsync-2.3.1:../../net/rsync
DEPENDS+=		srsh-*:../../net/srsh

NO_CONFIGURE=		yes
ALL_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
