# $NetBSD: Makefile,v 1.2 1998/04/15 10:38:17 agc Exp $

DISTNAME=	modemd-970221
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.vix.com/pub/modemd/

MAINTAINER=	tsarna@endicor.com

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=	yes
.endif

pre-install:
	${MKDIR} ${PREFIX}/share/examples/modemd

.include "../../mk/bsd.pkg.mk"
