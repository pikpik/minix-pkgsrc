# $NetBSD: Makefile,v 1.12 1999/06/21 04:53:14 jlam Exp $

DISTNAME=	WMMail.app-0.63a
PKGNAME=	wmmail-0.63a
CATEGORIES=	mail x11
MASTER_SITES=	http://www.eecg.utoronto.ca/~chanb/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.eecg.utoronto.ca/~chanb/wmmail.html

DEPENDS+=	windowmaker-0.60.0:../../x11/windowmaker

USE_X11BASE=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-PL-incs="-I${LOCALBASE}/include" \
			--with-PL-libs="-L${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
