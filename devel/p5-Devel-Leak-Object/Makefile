# $NetBSD: Makefile,v 1.2 2008/10/19 19:17:51 he Exp $

DISTNAME=	Devel-Leak-Object-0.92
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Devel::Devel::Leak
COMMENT=	perl module to detect leaks of objects

PERL5_PACKLIST= auto/Devel/Leak/Object/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
