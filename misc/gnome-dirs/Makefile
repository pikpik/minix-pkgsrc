# $NetBSD: Makefile,v 1.11 2005/04/11 21:46:34 tv Exp $
#

DISTNAME=	gnome-dirs-1.5
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v1 and v2) directories

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
USE_PKGINSTALL=	yes
USE_X11BASE=	yes
NO_CHECKSUM=	# defined
NO_EXTRACT=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

MAKE_DIRS+=	${GNOME_DIRS:O:S/^/${PREFIX}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
