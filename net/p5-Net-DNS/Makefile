# $NetBSD: Makefile,v 1.13 1999/04/15 20:39:46 tron Exp $
#

DISTNAME=		Net-DNS-0.12
PKGNAME=		p5-Net-DNS-0.12
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		hubertf@netbsd.org

USE_PERL5=		YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
