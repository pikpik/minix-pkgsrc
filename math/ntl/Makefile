# $NetBSD: Makefile,v 1.7 2001/06/20 10:19:27 jtb Exp $

DISTNAME=		ntl-5.3.1
CATEGORIES=		math devel
MASTER_SITES=		http://www.shoup.net/ntl/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.shoup.net/ntl/
COMMENT=		C++ library for doing number theory

DEPENDS+=		gmp>=3.1.1:../../devel/gmp

WRKSRC=			${WRKDIR}/${DISTNAME}/src

NO_CONFIGURE=		# defined
USE_LIBTOOL=		yes
MAKEFILE=		makefile

.include "../../devel/gmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
