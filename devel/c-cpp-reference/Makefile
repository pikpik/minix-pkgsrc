# $NetBSD: Makefile,v 1.3 2002/03/13 17:36:47 fredb Exp $
#

DISTNAME=	c_cpp_reference-2.0.2
PKGNAME=	${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	ftp://ftp.e-technik.fh-muenchen.de/pub/unix/ide/KDevelop/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.kdevelop.org/
COMMENT=	C and C++ reference for the KDE IDE

DEPENDS+=	kdevelop-base>=2.1.1:../kdevelop-base

USE_GMAKE=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../x11/kde3/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
