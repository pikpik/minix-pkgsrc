# $NetBSD: Makefile,v 1.7 2002/09/10 16:06:39 wiz Exp $
#

DISTNAME=	gtkdiff-1.6.0
PKGREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	http://www.ainet.or.jp/~inoue/software/gtkdiff/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.ainet.or.jp/~inoue/software/gtkdiff/index-e.html
COMMENT=	diff front-end program using GNOME

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
