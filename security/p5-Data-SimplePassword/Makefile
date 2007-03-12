# $NetBSD: Makefile,v 1.7 2006/10/03 08:52:58 rillig Exp $
#

DISTNAME=		Data-SimplePassword-0.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Data-SimplePassword/
COMMENT=		Simple random password generator

DEPENDS+=        	p5-Crypt-Random-[0-9]*:../../security/p5-Crypt-Random

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/SimplePassword/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
