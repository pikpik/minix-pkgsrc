# $NetBSD: Makefile,v 1.1.1.1 1999/05/18 16:13:37 bad Exp $
#

DISTNAME=	XML-Parser-2.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://wwwx.netheaven.com/~coopercc/xmlparser/intro.html

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/Parser/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
