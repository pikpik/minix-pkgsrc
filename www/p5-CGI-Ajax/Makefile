# $NetBSD: Makefile,v 1.15 2007/12/16 07:11:51 rhaen Exp $

DISTNAME=		CGI-Ajax-0.701
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CGI-Ajax//
COMMENT=		Call perl asynchronously from javascript

DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/CGI/Ajax/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
