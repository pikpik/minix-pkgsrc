# $NetBSD: Makefile,v 1.10 2003/03/03 04:17:36 jschauma Exp $

DISTNAME=	xgas
PKGNAME=        xgas-1.0
PKGREVISION=	1
CATEGORIES=     x11
MASTER_SITES=   ftp://ftp.tut.ac.jp/.h3/X11/X11R6/contrib/programs/

MAINTAINER=     nakai@mlab.t.u-tokyo.ac.jp
COMMENT=	Animated simulation of an ideal gas

USE_IMAKE=      yes

post-install:
	@${CHMOD} 755 ${PREFIX}/bin/xgas
	@${CHOWN} bin:bin ${PREFIX}/bin/xgas

.include "../../mk/bsd.pkg.mk"
