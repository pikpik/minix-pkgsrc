# $NetBSD: Makefile,v 1.6 2001/02/16 14:38:28 wiz Exp $
#

DISTNAME=		gmp-3.1.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gmp/}

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gmp/gmp.html
COMMENT=		Library for arbitrary precision arithmetic

BUILD_DEPENDS+=		${PREFIX}/bin/gm4:../../devel/m4

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
M4=			${PREFIX}/bin/gm4

.include "../../mk/bsd.pkg.mk"
