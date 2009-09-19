# $NetBSD: Makefile,v 1.10 2008/10/19 19:18:01 he Exp $
#

DISTNAME=		Test-Weaken-3.002000
PKGNAME=		p5-${DISTNAME:S/002000/002.000/}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Weaken/
COMMENT=		Test that freed memory objects were, indeed, freed
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Weaken/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
