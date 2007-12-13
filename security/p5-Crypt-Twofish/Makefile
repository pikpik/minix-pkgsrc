# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:36 jlam Exp $
#

DISTNAME=		Crypt-Twofish-2.12
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ctw
PKGREVISION=		3
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-Twofish/
COMMENT=		Perl5 module for the Twofish symmetric key algorithm

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_TOOLS+=		perl
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Crypt/Twofish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
