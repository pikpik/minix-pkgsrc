# $NetBSD: Makefile,v 1.8 2002/08/31 01:19:08 mjl Exp $
#

DISTNAME=	DBIx-SearchBuilder-0.61
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dxs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	packages@netbsd.org
COMMENT=	extension for easy SQL SELECT Statement generation

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBIx/SearchBuilder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
