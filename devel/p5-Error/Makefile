# $NetBSD: Makefile,v 1.6 2001/11/26 06:49:54 jlam Exp $

DISTNAME=	Error-0.15
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5err
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Error/}

MAINTAINER=	cjs@netbsd.org
COMMENT=	Perl extension module for try/throw/catch exception handling.

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Error/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
