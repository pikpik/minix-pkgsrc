# $NetBSD$
#

DISTNAME=	XML-Parser-2.23
PKGNAME=	p5-XML-Parser-2.23
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://wwwx.netheaven.com/~coopercc/xmlparser/intro.html

USE_PERL5=	YES

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
