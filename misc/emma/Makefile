# $NetBSD: Makefile,v 1.8 1999/10/27 11:05:21 tron Exp $
#

DISTNAME=       emma-0.7-1
PKGNAME=	emma-0.7
WRKSRC=         ${WRKDIR}/emma-0.7
CATEGORIES=	misc
MASTER_SITES=   http://rainbow.mimuw.edu.pl/~la181249/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://rainbow.mimuw.edu.pl/~la181249/

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	gnome-libs-*:../../x11/gnome-libs
DEPENDS+=	python-*:../../lang/python

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
