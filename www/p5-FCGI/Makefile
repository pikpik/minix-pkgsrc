# $NetBSD: Makefile,v 1.7 1998/06/22 13:14:31 agc Exp $
#

DISTNAME=       	FCGI-0.42
PKGNAME=        	p5-FCGI-0.42
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	FCGI

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.fastcgi.com/

USE_PERL5=		YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
