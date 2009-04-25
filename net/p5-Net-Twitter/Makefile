# $NetBSD: Makefile,v 1.2 2008/10/19 19:18:33 he Exp $
#

DISTNAME=	Net-Twitter-2.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	peter@boku.net
HOMEPAGE=	http://search.cpan.org/dist/Net-Twitter/
COMMENT=	Perl interface to twitter.com
LICENSE=	artistic-2.0 # OR gpl-v2+

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-JSON-Any>=1.19:../../converters/p5-JSON-Any
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=	auto/Net/Twitter/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
