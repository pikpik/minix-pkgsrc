# $NetBSD$
#

PKGNAME=	kaffe-nox11-1.1.4
COMMENT=	Virtual machine capable of running Java(tm) code (without X)

CONFIGURE_ARGS+=    --without-x

CONFLICTS=	kaffe-[0-9]*
PLIST_SUBST+=	WITH_X11='@comment '

.include "../kaffe/Makefile.common"
.include "../../mk/bsd.pkg.mk"

PREFIX=		${JVM_HOME}
