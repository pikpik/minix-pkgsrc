# $NetBSD: Makefile,v 1.5 2004/04/27 06:05:57 snj Exp $
#

DISTNAME=		IO-Interface-0.98
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ioi
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~lds/IO-Interface-0.98/
COMMENT=		IO-Interface - get and set interface characteristics

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Interface/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
