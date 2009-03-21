# $NetBSD: Makefile,v 1.4 2008/12/20 23:45:30 he Exp $
#

DISTNAME=	MooseX-Types-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Types/
COMMENT=	Organise your Moose types in libraries

DEPENDS+=	p5-Moose>=0.61:../../devel/p5-Moose
DEPENDS+=	p5-Sub-Install>=0.924:../../devel/p5-Sub-Install
DEPENDS+=	p5-namespace-clean>=0.08:../../devel/p5-namespace-clean
DEPENDS+=	p5-Carp-Clan>=6.00:../../devel/p5-Carp-Clan

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Types/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
