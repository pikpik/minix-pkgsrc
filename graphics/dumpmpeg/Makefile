# $NetBSD$
#

DISTNAME=	dumpmpeg-0.6
CATEGORIES=	graphics
MASTER_SITES=	http://prdownloads.sourceforge.net/dumpmpeg/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/dumpmpeg
COMMENT=	Splits mpeg stream into single images

DEPENDS+=	smpeg>=0.4.3:../../devel/smpeg
DEPENDS+=	SDL>=1.2.0:../../devel/SDL

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-sdl-prefix=${LOCALBASE} \
		--with-smpeg-prefix=${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
