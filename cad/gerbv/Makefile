# $NetBSD$
#

DISTNAME=	gerbv-0.0.5
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gerbv/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://gerbv.sourceforge.net
COMMENT=	Gerber file viewer

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

DEPENDS+=	guile>=1.4:../../lang/guile

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
