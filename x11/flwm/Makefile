# $NetBSD$
#

DISTNAME=	flwm-0.25
CATEGORIES=	x11
MASTER_SITES=	http://flwm.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://flwm.sourceforge.net/

DEPENDS+=	fltk-*:../../x11/fltk

USE_X11BASE=	# defined

GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	X_LIBS="-lGL" CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-I${X11PREFIX}/include

.include "../../mk/bsd.pkg.mk"
