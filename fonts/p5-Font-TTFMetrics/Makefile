# $NetBSD: Makefile,v 1.6 2011/08/14 12:43:26 obache Exp $
#

DISTNAME=	Font-TTFMetrics-0.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Font-TTFMetrics/
COMMENT=	Perl parser for the True type font metric (TTF) files
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Font/TTFMetrics/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
