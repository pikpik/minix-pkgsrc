# $NetBSD: Makefile,v 1.8 2008/10/19 19:17:46 he Exp $
#

DISTNAME=	SQL-Abstract-1.50
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sqa
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SQL-Abstract/
COMMENT=	Generate SQL from Perl data structures

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

PERL5_PACKLIST=		auto/SQL/Abstract/.packlist

post-patch:
	-rm -f ${WRKSRC}/lib/SQL/.Abstract.pm.swp

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
