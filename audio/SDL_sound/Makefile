# $NetBSD: Makefile,v 1.7 2004/02/14 17:21:32 jlam Exp $
#

DISTNAME=		SDL_sound-1.0.1
CATEGORIES=		audio
MASTER_SITES=		http://icculus.org/SDL_sound/downloads/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://icculus.org/SDL_sound/
COMMENT=		SDL library to handle the decoding of different file formats

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/smpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
