# $NetBSD: Makefile,v 1.6 2001/11/26 06:49:45 jlam Exp $
#

DISTNAME=	AtExit-2.01
PKGNAME=	p5-AtExit-2.01
SVR4_PKGNAME=	p5ate
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AtExit/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Provides an ANSI C style atexit() function to Perl programs

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_ARCHLIB}/auto/AtExit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
