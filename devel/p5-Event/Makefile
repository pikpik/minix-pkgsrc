# $NetBSD: Makefile,v 1.4 2002/01/12 17:47:20 explorer Exp $

DISTNAME=	Event-0.83
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5eve
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JP/JPRIT/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Event library for Perl

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Event/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
