# $NetBSD: Makefile,v 1.1.1.1 2002/03/19 14:48:25 mjl Exp $
#

DISTNAME=	Parse-RecDescent-1.80
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	packages@netbsd.org
COMMENT=		generate recursive-descent parsers

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Parse/RecDescent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
