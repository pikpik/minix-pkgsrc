# $NetBSD: Makefile,v 1.1.1.1 2003/09/14 20:27:50 gson Exp $
#

DISTNAME=	Set-IntSpan-1.07
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sis
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Set-IntSpan/
COMMENT=	Perl5 module for managing sets of integers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Set/IntSpan/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
