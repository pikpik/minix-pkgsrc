# $NetBSD$

DISTNAME=	Scalar-List-Utils-1.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5slu
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Scalar/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/author/GBARR/Scalar-List-Utils-1.12/
COMMENT=	Selection of general-utility scalar subroutines

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/List/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
