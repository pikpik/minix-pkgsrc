# $NetBSD: Makefile,v 1.7 2003/07/22 04:14:27 martti Exp $

DISTNAME=	Apache-SSI-2.16
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ass
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module to implement Server Side Includes

DEPENDS+=	p5-HTML-SimpleParse>=0.06:../../www/p5-HTML-SimpleParse

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/SSI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
