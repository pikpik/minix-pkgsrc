# $NetBSD: Makefile,v 1.17 2006/02/05 23:09:29 joerg Exp $
#

DISTNAME=	denemo-0.7.6
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=denemo/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://denemo.sourceforge.net/
COMMENT=	GUI musical score editor written in C/GTK+

DEPENDS+=	lilypond-[0-9]*:../../print/lilypond

GNU_CONFIGURE=	YES
USE_DIRS+=	xdg-1.4
USE_TOOLS+=	pkg-config

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
