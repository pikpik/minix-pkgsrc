# $NetBSD: Makefile,v 1.28 2008/07/27 17:06:57 joerg Exp $
#

DISTNAME=	GNUMail-1.2.0pre3
CATEGORIES=	mail gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.collaboration-world.com/gnumail/
COMMENT=	GNUstep clone of NeXT's Mail.app application

LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	destdir

USE_LANGUAGES=	objc

WRKSRC=		${WRKDIR}/GNUMail
NO_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
MAKE_FILE=	GNUmakefile

.include "../../mail/Pantomime/buildlink3.mk"
.include "../../misc/Addresses/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
