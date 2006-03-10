# $NetBSD: Makefile,v 1.18 2006/03/04 21:30:41 jlam Exp $
#

DISTNAME=	gworkspace-0.7.1
PKGREVISION=	3
CATEGORIES=	sysutils gnustep
MASTER_SITES=	http://www.gnustep.it/enrico/gworkspace/	\
		http://www.imago.ro/gworkspace/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnustep.it/enrico/gworkspace/
COMMENT=	GNUstep Workspace manager

CONFLICTS+=	GWLib-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME:S/gw/GW/}
USE_TOOLS+=	gs:run file:run sh:run
CONFIGURE_ARGS+=	--with-sh=${TOOLS_PATH.sh:Q}
CONFIGURE_ARGS+=	--with-file=${TOOLS_PATH.file:Q}

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
