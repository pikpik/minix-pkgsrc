# $NetBSD: Makefile,v 1.6 2001/11/30 14:23:02 mjl Exp $
#

DISTNAME=	Text-CSV_XS-0.23
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tcx
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	packages@netbsd.org
# HOMEPAGE=	http://
COMMENT=	Routines for composition and decomposition of comma-separated values

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/CSV_XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
