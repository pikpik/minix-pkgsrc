# $NetBSD: Makefile,v 1.3 2010/08/21 16:35:16 seb Exp $

DISTNAME=		File-MMagic-XS-0.09006
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/File-MMagic/
COMMENT=		File Type With XS (a la mod_mime_magic)
LICENSE=		${PERL5_LICENSE}

MAKE_JOBS_SAFE=		no

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/File/MMagic/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
