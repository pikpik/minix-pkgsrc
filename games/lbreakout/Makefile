# $NetBSD: Makefile,v 1.11 2001/10/24 22:10:56 jlam Exp $
#

DISTNAME=	lbreakout-010315
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	breakout-style arcade game

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-sound

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
