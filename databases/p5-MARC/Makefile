# $NetBSD: Makefile,v 1.7 2002/10/06 22:31:10 seb Exp $
#

DISTNAME=	MARC-1.15
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mrc
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module for manipulating MARC (MAchine Readable Cataloging) data

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MARC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
