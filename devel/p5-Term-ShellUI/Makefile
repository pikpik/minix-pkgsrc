# $NetBSD: Makefile,v $

DISTNAME=	Term-ShellUI-0.86
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-ShellUI/
COMMENT=	Fully-featured shell-like command line environment for Perl

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Term/ShellUI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
