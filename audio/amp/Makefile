# Makefile for:		amp
# Version required:	0.7.6
#
# $NetBSD: Makefile,v 1.3 1998/01/08 17:11:15 agc Exp $
#

DISTNAME=	amp-0.7.6
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.rasip.fer.hr/pub/mpeg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mycroft@NetBSD.ORG

GNU_CONFIGURE=	yes

MAN1=		amp.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/amp ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/amp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
