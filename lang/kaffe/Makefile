# $NetBSD$
#

PKGNAME=	kaffe-${KAFFE_VERSION}
COMMENT=	Virtual machine capable of running Java(tm) code

USE_X11=	yes

CONFLICTS=	kaffe-nox11-[0-9]*
PLIST_SUBST+=	WITH_X11=

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"

PREFIX=		${JVM_HOME}
