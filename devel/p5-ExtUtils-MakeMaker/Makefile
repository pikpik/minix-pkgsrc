# $NetBSD: Makefile,v 1.16 2010/08/21 16:33:40 seb Exp $

DISTNAME=	ExtUtils-MakeMaker-6.59
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSTROUT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-MakeMaker/
COMMENT=	Write a Makefile for an extension module from a Makefile.PL
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Parse-CPAN-Meta>=1.4401:../../devel/p5-Parse-CPAN-Meta

PERL5_PACKLIST=		auto/ExtUtils/MakeMaker/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f -exec ${RM} {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
