# $NetBSD: Makefile,v 1.8 2004/10/03 00:18:18 tv Exp $
#

DISTNAME=	aspell6-en-6.0-0
PKGNAME=	aspell-english-6.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/en/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	English language support for aspell

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
