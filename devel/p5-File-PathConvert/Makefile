# $NetBSD: Makefile,v 1.6 2002/03/15 12:11:10 martti Exp $
#

DISTNAME=	File-PathConvert-0.9
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fpc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/File-PathConvert/
COMMENT=	Convert paths and URLs from absolute to relative and vice versa

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/PathConvert/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
