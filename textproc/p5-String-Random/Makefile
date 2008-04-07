# $NetBSD: Makefile,v 1.9 2007/03/19 16:36:42 tv Exp $
#

DISTNAME=		String-Random-0.22
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/String-Random/
COMMENT=		Generate random strings based on a pattern

PERL5_PACKLIST=		auto/String/Random/.packlist
PERL5_MODULE_TYPE=      Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
