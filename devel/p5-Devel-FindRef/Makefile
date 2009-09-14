# $NetBSD: Makefile,v 1.1.1.1 2009/08/29 22:23:43 seb Exp $
#

DISTNAME=	Devel-FindRef-1.422
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-FindRef/
COMMENT=	Perl 5 module to track down references
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Devel/FindRef/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
