# $NetBSD: Makefile,v 1.2 2001/11/01 15:28:44 damon Exp $

DISTNAME=	etherape-0.8.2
CATEGORIES=	gnome net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=etherape/}

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://etherape.sourceforge.net/
COMMENT=	graphical network monitor

USE_GMAKE=		#defined
USE_X11BASE=		#defined
HAS_CONFIGURE=		#defined
CONFIGURE_ARGS+=	--prefix ${PREFIX}
PLIST_SUBST+=		MKDIR='${MKDIR}'

.include "../../devel/libglade/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
