# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:32 tv Exp $
#

DISTNAME=	aspell-fo-0.2.24
PKGNAME=	${DISTNAME:C/-fo-/-faroese-/}
CATEGORIES=	textproc
MASTER_SITES=	http://fo.speling.org/filer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fo.speling.org/
COMMENT=	Faroese language support for aspell

USE_TOOLS+=	perl
REPLACE_PERL=	unsq

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
