# $NetBSD: Makefile,v 1.4 2011/08/14 12:26:27 obache Exp $

DISTNAME=	Parallel-ForkManager-0.7.9
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parallel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Parallel-ForkManager/
COMMENT=	Simple parallel processing fork manager

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Parallel/ForkManager/.packlist
REPLACE_PERL+=		*/*.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
