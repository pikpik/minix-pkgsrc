# $NetBSD: Makefile,v 1.13 2008/10/19 19:17:58 he Exp $
#

DISTNAME=	PAR-Dist-0.40
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5moi
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PAR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PAR-Dist/
COMMENT=	Perl module toolkit to create and manipulate PAR distributions

BUILD_DEPENDS+=	p5-Archive-Zip>0:../../archivers/p5-Archive-Zip

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/PAR/Dist/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
