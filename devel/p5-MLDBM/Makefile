# $NetBSD: Makefile,v 1.3 2000/02/28 01:04:12 dmcmahill Exp $
#

DISTNAME=		MLDBM-2.00
PKGNAME=		p5-MLDBM-2.00
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/MLDBM/MLDBM.html

DEPENDS+= 		p5-Data-Dumper-*:../../devel/p5-Data-Dumper

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MLDBM/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
