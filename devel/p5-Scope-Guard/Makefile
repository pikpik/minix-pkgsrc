# $NetBSD: Makefile,v 1.3 2009/06/13 06:46:46 rillig Exp $

DISTNAME=	Scope-Guard-0.12
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Scope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Scope-Guard/
COMMENT=	Lexically scoped resource management

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Scope/Guard/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
