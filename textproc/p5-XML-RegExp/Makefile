# $NetBSD$
#

DISTNAME=	XML-RegExp-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/TJMATHER/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Provide regular expressions for some XML tokens

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/RegExp/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
