# $NetBSD: Makefile,v 1.16 2006/07/19 22:42:52 wiz Exp $
#

DISTNAME=	Text-Balanced-v2.0.0
PKGNAME=	p5-${DISTNAME:S/-v2/-2/1}
SVR4_PKGNAME=	p5tba
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Balanced/
COMMENT=	Extract delimited text sequences from strings

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

PERL5_PACKLIST=		auto/Text/Balanced/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
