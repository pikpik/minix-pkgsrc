# $NetBSD: Makefile,v 1.4 2008/10/19 19:17:51 he Exp $
#

DISTNAME=	Date-Simple-3.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	geeogeegeeoh@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~yves/Date-Simple/
COMMENT=	A simple date object
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Date/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
