# $NetBSD: Makefile,v 1.29 2006/02/05 23:08:22 joerg Exp $
#

DISTNAME=	pcb-${SNAPDATE}
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcb/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://pcb.sourceforge.net/
COMMENT=	Printed circuit board layout system

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	pcb-current-[0-9]*

SNAPDATE=		20050609
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		WISH=${TOOLS_PATH.wish}
USE_TOOLS+=		bison gm4:run gmake lex wish:run

# needed for XWarpPointer in action.c
LIBS+=		-lX11

INFO_FILES=	pcb.info

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
