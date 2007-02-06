# $NetBSD: Makefile,v 1.12 2006/03/04 21:29:21 jlam Exp $
#

DISTNAME=	File-NFSLock-1.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	NFS (or not) locking

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/File/NFSLock/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
