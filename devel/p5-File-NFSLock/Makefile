# $NetBSD: Makefile,v 1.4 2010/08/21 16:33:44 seb Exp $

DISTNAME=	File-NFSLock-1.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-NFSLock/
COMMENT=	NFS (or not) locking
LICENSE=	gnu-gpl-v2 OR artistic

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/File/NFSLock/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
