# $NetBSD: Makefile,v 1.2 2001/02/17 17:37:38 wiz Exp $
#

DISTNAME=	Text-Balanced-1.85
PKGNAME=	p5-Text-Balanced-1.85
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	
COMMENT=	Extract delimited text sequences from strings

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Text/Balanced/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
