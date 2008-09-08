# $NetBSD$

DISTNAME=	libv4l-0.4.3
CATEGORIES=	graphics
MASTER_SITES=	http://people.atrpms.net/~hdegoede/

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://people.atrpms.net/~hdegoede/
COMMENT=	Video4Linux userspace library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake

.if exists(/usr/include/sys/videoio.h)
do-install:
	cd ${WRKSRC} && ${GMAKE} install PREFIX=${PREFIX}
.else
NO_BUILD=	yes
do-install:	# nothing
.endif

.include "../../mk/bsd.pkg.mk"
