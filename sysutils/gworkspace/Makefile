# $NetBSD: Makefile,v 1.27 2008/06/21 23:04:11 joerg Exp $
#

DISTNAME=	gworkspace-0.8.6
CATEGORIES=	sysutils gnustep
MASTER_SITES=	http://www.gnustep.it/enrico/gworkspace/	\
		http://www.imago.ro/gworkspace/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnustep.it/enrico/gworkspace/
COMMENT=	GNUstep Workspace manager

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	destdir

CONFLICTS+=	GWLib-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME:S/gw/GW/}
USE_TOOLS+=	gs:run file:run sh:run
USE_LANGUAGES=	objc
CONFIGURE_ARGS+=	--with-sh=${TOOLS_PATH.sh:Q}
CONFIGURE_ARGS+=	--with-file=${TOOLS_PATH.file:Q}
MAKE_FILE=	GNUmakefile
MAKE_JOBS_SAFE=	no

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
