# $NetBSD: Makefile,v 1.4 2002/01/26 06:51:17 martti Exp $

DISTNAME=		Net-IRC-0.73
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5nir
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		damon@brodiefamily.org
HOMEPAGE=		http://theoryx5.uwinnipeg.ca/CPAN/data/Net-IRC/Connection.html
COMMENT=		Net::IRC - Perl Internet Relay Chat (IRC) Module

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/IRC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
