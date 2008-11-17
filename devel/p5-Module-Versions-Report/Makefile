# $NetBSD: Makefile,v 1.10 2008/10/19 19:17:57 he Exp $

DISTNAME=	Module-Versions-Report-1.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Versions-Report/
COMMENT=	Extension to report versions of all modules in memory

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Module-Versions-Report/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
