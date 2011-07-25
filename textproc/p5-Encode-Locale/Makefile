# $NetBSD: Makefile,v 1.16 2010/09/19 11:07:30 wiz Exp $

DISTNAME=	Encode-Locale-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Encode-Locale/
COMMENT=	Determine the locale encoding for Encode
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Encode/Locale/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
