# $NetBSD: Makefile,v 1.20 2008/10/19 19:17:43 he Exp $
#

DISTNAME=	Apache-DBI-1.08
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
SVR4_PKGNAME=	p5adb
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache-DBI/
COMMENT=	DBI support for Apache+mod_perl
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Digest-SHA1>=2.01:../../security/p5-Digest-SHA1

PERL5_PACKLIST=		auto/Apache/DBI/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
