# $NetBSD: Makefile,v 1.6 2001/11/26 06:50:12 jlam Exp $
#

DISTNAME=	Net-Telnet-3.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nte
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module to use telnet

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/Telnet/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
