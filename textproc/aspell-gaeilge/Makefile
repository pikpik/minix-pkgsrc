# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:18 tv Exp $

DISTNAME=	aspell5-ga-3.5-0
PKGNAME=	aspell-gaeilge-3.5.0
CATEGORIES=	textproc
MASTER_SITES=   ${MASTER_SITE_GNU:=aspell/dict/ga/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://borel.slu.edu/~kps/ispell/
COMMENT=	Irish language support for aspell

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
