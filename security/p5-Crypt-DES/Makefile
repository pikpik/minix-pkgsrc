# $NetBSD: Makefile,v 1.3 2001/11/26 06:50:14 jlam Exp $
#

DISTNAME=		Crypt-DES-2.03
PKGNAME=		p5-Crypt-DES-2.03
SVR4_PKGNAME=		p5des
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
COMMENT=		XS-based DES implementation for Perl

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/DES/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
