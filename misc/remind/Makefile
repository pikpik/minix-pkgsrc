# $NetBSD: Makefile,v 1.1.1.1 1999/03/02 06:14:48 kim Exp $

DISTNAME=	remind-03.00.19
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.doe.carleton.ca/pub/remind-3.0/
EXTRACT_SUFX=	.tgz

.include "../../mk/bsd.pkg.mk"

PKGNAME!=	${ECHO} ${DISTNAME} | ${SED} -e 's/0\([0-9]\)/\1/g'

MAINTAINER=	kim@tac.nyc.ny.us

GNU_CONFIGURE=	yes
