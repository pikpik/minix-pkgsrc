# $NetBSD: Makefile,v 1.9 2007/01/07 09:13:55 rillig Exp $

DISTNAME=	zombies-1.0
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.thistledown.com.au/software/ \
		ftp://melanoma.cs.rmit.edu.au/pub/simonb/

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://www.thistledown.com.au/software/
COMMENT=	Simple robots-like game where you destroy the zombies

INSTALLATION_DIRS_FROM_PLIST=	yes
BUILD_DEFS+=		VARBASE
MAKE_ENV+=	VARBASE=${VARBASE}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
