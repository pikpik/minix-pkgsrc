# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:39 obache Exp $

DISTNAME=	Term-ShellUI-0.91
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-ShellUI/
COMMENT=	Fully-featured shell-like command line environment for Perl
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Term/ShellUI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
