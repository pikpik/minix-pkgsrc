# $NetBSD: Makefile,v 1.3 2004/03/08 19:27:53 jmmv Exp $
#

DISTNAME=	xdg-dirs-1.1
CATEGORIES=	misc gnome kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared XDG directories

CONFLICTS=	gnome2-dirs<=1.2

NO_BUILD=	# defined
NO_BUILDLINK=	# defined
NO_CONFIGURE=	# defined
NO_CHECKSUM=	# defined
NO_EXTRACT=	# defined
USE_LANGUAGES=	# empty
USE_PKGINSTALL=	yes
WRKSRC=		${WRKDIR}

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

_SORTED!=	${ECHO} ${XDG_DIRS} | ${TR} -s ' \t' '\n' | ${SORT}
MAKE_DIRS+=	${_SORTED:S/^/${PREFIX}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
