# $NetBSD: Makefile,v 1.3 1999/04/15 20:39:47 tron Exp $
#

DISTNAME=       	CGI.pm-2.66
PKGNAME=        	p5-CGI-2.66
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		christos@netbsd.org

USE_PERL5=		YES

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
