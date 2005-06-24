# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:29 tv Exp $

DISTNAME=	Class-Inspector-1.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Inspector/
COMMENT=	Provides information about Classes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/Inspector/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
