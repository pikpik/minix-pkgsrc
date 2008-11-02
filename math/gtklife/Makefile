# $NetBSD: Makefile,v 1.8 2006/03/04 21:30:03 jlam Exp $

DISTNAME=	gtklife-5.1
CATEGORIES=	math
MASTER_SITES=	http://ironphoenix.org/tril/gtklife/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ironphoenix.org/tril/gtklife/
COMMENT=	The game of life

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gtk2
CONFIGURE_ARGS+=--with-docdir=${PREFIX}/share/doc/gtklife
USE_TOOLS+=	gmake

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
