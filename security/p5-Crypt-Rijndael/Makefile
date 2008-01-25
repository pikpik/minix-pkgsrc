# $NetBSD: Makefile,v 1.14 2006/03/04 21:30:36 jlam Exp $
#

DISTNAME=		Crypt-Rijndael-1.05
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5crj
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-Rijndael/
COMMENT=		Perl5 module of the Rijndael symmetric key algorithm

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Crypt/Rijndael/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
