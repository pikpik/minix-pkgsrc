# $NetBSD: Makefile,v 1.14 2004/12/20 11:31:13 grant Exp $
#

NAME=			CGI-Lite-2.02
DISTNAME=       	${NAME}
PKGNAME=        	p5-${NAME}
SVR4_PKGNAME=		p5cgl
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		bad@NetBSD.org
COMMENT=		Simple perl5 module for writing forms-based CGI programs

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
