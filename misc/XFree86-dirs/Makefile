# $NetBSD: Makefile,v 1.1.1.1 2004/03/28 21:55:48 xtraeme Exp $
#

DISTNAME=	XFree86-dirs-1.0
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared XFree86 directories

NO_BUILD=		# defined
NO_BUILDLINK=		# defined
NO_CHECKSUM=		# defined
NO_CONFIGURE=		# defined
NO_EXTRACT=		# defined
NO_XFREE86_TARGETS=	# defined
USE_LANGUAGES=		# empty
USE_PKGINSTALL=		yes
WRKSRC=			${WRKDIR}

XFREE86_ONLY_DIRS=	# defined
.include "../../mk/bsd.prefs.mk"
.include "dirs.mk"

_SORTED!=	${ECHO} ${XFREE86_DIRS} | ${TR} -s ' \t' '\n' | ${SORT}
MAKE_DIRS+=	${_SORTED:S/^/${X11ROOT}\//}

do-install:	# nothing

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
