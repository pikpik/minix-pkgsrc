# $NetBSD: Makefile,v 1.14 1999/12/02 15:57:28 rh Exp $
#

DISTNAME=	Net-Telnet-3.01
PKGNAME=	p5-Net-Telnet-3.01
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	packages@netbsd.org

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
