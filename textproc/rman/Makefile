# $NetBSD: Makefile,v 1.13 2000/04/18 04:02:20 fredb Exp $
# FreeBSD Id: Makefile,v 1.17 1997/12/08 15:45:27 tg Exp
#

DISTNAME=	rman
PKGNAME=	rman-3.0.9
CATEGORIES=	textproc
MASTER_SITES=	ftp://polyglot.sourceforge.net/pub/polyglotman/ \
		http://polyglotman.sourceforge.net/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://polyglotman.sourceforge.net/

WRKSRC=		${WRKDIR}/${PKGNAME}

post-install:
	strip ${PREFIX}/bin/rman

.include "../../mk/bsd.pkg.mk"
