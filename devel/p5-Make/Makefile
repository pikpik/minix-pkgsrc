# $NetBSD: Makefile,v 1.3 2001/11/26 06:49:52 jlam Exp $

DISTNAME=	Make-1.00
PKGNAME=	p5-Make-1.00
SVR4_PKGNAME=	p5mak
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Make/}

MAINTAINER=	packages@netbd.org
HOMEPAGE=	http://www.ni-s.u-net.com/
COMMENT=	Perl5 module implementing 'make' in Perl

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Make/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
