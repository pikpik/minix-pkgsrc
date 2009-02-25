# $NetBSD: Makefile,v 1.1.1.1 2008/08/23 18:24:01 seb Exp $
#

DISTNAME=	Hash-MoreUtils-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Hash-MoreUtils/
COMMENT=	Perl 5 module provides the stuff missing in Hash::Util

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Hash/MoreUtils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
