# $NetBSD$

DISTNAME=	Log-Dispatch-1.77
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl module for logging messages to multiple outputs

USE_PERL5=      # defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Log/Dispatch/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
