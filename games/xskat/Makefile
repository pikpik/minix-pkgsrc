# $NetBSD: Makefile,v 1.15 2008/07/14 12:56:04 joerg Exp $

DISTNAME=	xskat-4.0
#PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.xskat.de/

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.if defined(WITH_ALTENBURGER_CARDS)
DISTFILES+=	xskat-cards.tar.gz
.endif

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xskat.de/xskat.html
COMMENT=	Play the card game Skat

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if defined(DEFAULT_IRC_SERVER)
MAKE_ENV+=	IRC_SERVER=${DEFAULT_IRC_SERVER:Q}
.else
MAKE_ENV+=	IRC_SERVER=irc.fu-berlin.de
.endif

.if defined(WITH_ALTENBURGER_CARDS)
post-extract:
	cp ${WRKDIR}/xskat-cards.c ${WRKSRC}/cards.c
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
