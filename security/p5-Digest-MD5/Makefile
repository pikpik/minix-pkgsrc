# $NetBSD$
#

PKGNAME=       	p5-Digest-MD5-2.09
DISTNAME!=     	echo ${PKGNAME} | sed -e 's/^p5-//'
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	packages@netbsd.org

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
