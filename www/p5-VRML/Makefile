# $NetBSD$
#

PKGNAME=	p5-VRML-1.04
DISTNAME!=	echo ${PKGNAME} | sed -e 's/^p5-//'
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=VRML/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gfz-potsdam.de/~palm/software/VRML/doc/VRML.pm.html

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
