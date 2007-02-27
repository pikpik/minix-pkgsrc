# $NetBSD: Makefile,v 1.15 2006/05/02 03:35:35 jlam Exp $

DISTNAME=	AppConfig-1.64
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5apc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AD/ADAMK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AppConfig/
COMMENT=	Perl5 module for parsing config files and command line arguments

DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/AppConfig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
