# $NetBSD: Makefile,v $

DISTNAME=	Net-ManageSieve-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-ManageSieve/
COMMENT=	ManageSieve Protocol Client

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/ManageSieve/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
