# $NetBSD$
#

DISTNAME=	xdg-x11-dirs-${XDG_DIRS_VERSION}
CATEGORIES=	misc gnome kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared XDG directories under the X11 tree

USE_X11BASE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${X11PREFIX} == ${LOCALBASE}
DEPENDS+=		xdg-dirs>=1.1:../../misc/xdg-dirs
XDG_DIRS_REGISTER=	no
.else
XDG_DIRS_REGISTER=	yes
.endif

.include "../../misc/xdg-dirs/Makefile.common"
.include "../../mk/bsd.pkg.mk"
