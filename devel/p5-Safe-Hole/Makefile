# $NetBSD: Makefile,v 1.3 2001/11/26 06:49:53 jlam Exp $
#

DISTNAME=	Safe-Hole-0.08
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sho
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Safe/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://theoryx5.uwinnipeg.ca/CPAN/data/Safe-Hole/Hole.html
COMMENT=	Exec subs in the original package from within a Safe object

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Safe/Hole/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
