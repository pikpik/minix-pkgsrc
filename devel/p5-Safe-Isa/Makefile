# $NetBSD: Makefile,v 1.9 2013/01/26 13:31:10 rhaen Exp $

DISTNAME=	Safe-Isa-1.000002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSTROUT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Safe-Isa/
COMMENT=	Call isa, can, does and DOES safely on things that may not be objects
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Safe-Isa/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
