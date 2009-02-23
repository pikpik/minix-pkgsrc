# $NetBSD$
#

DISTNAME=	accessors-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SP/SPURKIS/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/accessors/
COMMENT=	Perl module - create accessor methods in caller's package

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/accessors/.packlist
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
