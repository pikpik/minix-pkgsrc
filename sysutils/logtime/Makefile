# $NetBSD$
#

DISTNAME=		logtime-1.0
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us

DEPENDS+=		sh-utils-*:../../sysutils/sh-utils

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		yes
NO_PATCH=		yes

MAKE_PARAMS+=		PREFIX=${PREFIX}
MAKE_PARAMS+=		GDATE=${LOCALBASE}/bin/gdate

ALL_TARGET=		all ${MAKE_PARAMS}
INSTALL_TARGET=		install ${MAKE_PARAMS}

.include "../../mk/bsd.pkg.mk"
