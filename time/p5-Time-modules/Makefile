# $NetBSD: Makefile,v 1.2 2009/01/19 18:00:59 abs Exp $

DISTNAME=	Time-modules-2006.0814
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-modules/
COMMENT=	Miscellaneous date parsing and formatting
LICENSE=	public-domain

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Time-modules/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
