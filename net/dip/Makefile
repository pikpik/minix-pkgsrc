# $NetBSD: Makefile,v 1.11 2003/07/17 22:51:05 grant Exp $

DISTNAME=	bsddip-1.02
CATEGORIES=	net
#
# the actual master site is almost out of reach for everybody
#MASTER_SITES=	ftp://sun.rz.tu-clausthal.de/pub/bsddip/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Dialup IP program

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

NO_CONFIGURE=	yes
MANCOMPRESSED_IF_MANZ=	yes

.include "../../mk/bsd.pkg.mk"
