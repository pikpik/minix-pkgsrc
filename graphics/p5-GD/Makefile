# $NetBSD: Makefile,v 1.2 1999/09/03 17:35:20 kim Exp $
#

DISTNAME=	GD-1.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/GD/GD.html

DEPENDS+=	gd-1.7.3:../../graphics/gd

USE_PERL5=	yes

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
