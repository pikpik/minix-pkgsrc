# $NetBSD: Makefile,v 1.3 1999/12/28 21:45:28 rh Exp $
#

DISTNAME=	pth-1.3a2
PKGNAME=	${DISTNAME:S/-/-current-/}
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.org/gnu/pth/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/pth/pth.html

CONFLICTS=	pth-*

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-pthread

.include "../../mk/bsd.pkg.mk"
