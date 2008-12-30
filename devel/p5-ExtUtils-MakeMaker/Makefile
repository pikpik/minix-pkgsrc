# $NetBSD: Makefile,v 1.8 2008/11/05 23:54:48 he Exp $
#

DISTNAME=	ExtUtils-MakeMaker-6.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-MakeMaker/
COMMENT=	Write a Makefile for an extension module from a Makefile.PL

DEPENDS+=	p5-UNIVERSAL-isa>=0:../../devel/p5-UNIVERSAL-isa

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/ExtUtils/MakeMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
