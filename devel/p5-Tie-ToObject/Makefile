# $NetBSD: Makefile,v 1.14 2007/02/22 19:26:23 wiz Exp $

DISTNAME=	Tie-ToObject-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-ToObject/
COMMENT=	Tie to an existing object

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Tie/ToObject/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
