# $NetBSD: Makefile,v 1.3 2001/11/26 06:50:14 jlam Exp $
#

DISTNAME=		Crypt-DES_EDE3-0.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5de3
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module for Triple-DES EDE encryption/decryption

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/DES_EDE3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
