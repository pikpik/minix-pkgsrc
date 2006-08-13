# $NetBSD$

DISTNAME=	Crypt-PasswdMD5-1.3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~luismunoz/${DISTNAME}/
COMMENT=	Provides interoperable MD5-based crypt() functions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Crypt/PasswdMD5/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
