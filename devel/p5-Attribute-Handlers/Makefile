# $NetBSD: Makefile,v 1.2 2002/06/10 02:35:49 shell Exp $

DISTNAME=	Attribute-Handlers-0.77
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ah
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Attribute/}

MAINTAINER=	packages@netbsd.org
# HOMEPAGE=	
COMMENT=	Simpler definition of attribute handlers

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Attribute/Handlers/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
