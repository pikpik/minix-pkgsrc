# $NetBSD: Makefile,v 1.3 2001/11/26 06:50:16 jlam Exp $
#

DISTNAME=		Crypt-Twofish-2.12
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ctw
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module for the Twofish symmetric key algorithm

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/Twofish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
