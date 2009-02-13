# $NetBSD: Makefile,v 1.10 2008/10/19 19:18:09 he Exp $
#

DISTNAME=	boolean-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=  ${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IN/INGY/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/perldoc?boolean
COMMENT=	Boolean support for Perl

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		#

PERL5_PACKLIST=	auto/boolean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
