# $NetBSD: Makefile,v 1.87 2005/12/05 20:51:01 rillig Exp $
#

DISTNAME=		strace-4.5.14
CATEGORIES=		sysutils
MASTER_SITES=		http://voxel.dl.sourceforge.net/sourceforge/strace/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		christos@NetBSD.org
HOMEPAGE=		http://www.liacs.nl/~wichert/strace/
COMMENT=		Trace system calls

WRKSRC=			${WRKDIR}/${DISTNAME}/${SRCBALL_NAME}
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.pkg.mk"
