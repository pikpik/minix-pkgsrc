# New ports collection makefile for:    xgas
# Version required:     1.0
# Date created:         20 Oct 1996
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $NetBSD: Makefile,v 1.1.1.1 1997/10/11 21:55:09 hubertf Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1996/11/15 09:55:44 asami Exp
#

DISTNAME=	xgas
PKGNAME=        xgas-1.0
CATEGORIES=     misc
MASTER_SITES=   ftp://ftp.tut.ac.jp/.h3/X11/X11R6/contrib/programs/

MAINTAINER=     nakai@mlab.t.u-tokyo.ac.jp

USE_IMAKE=      yes

post-install:
	@chmod 755 ${PREFIX}/bin/xgas
	@chown bin.bin ${PREFIX}/bin/xgas

.include <bsd.port.mk>
