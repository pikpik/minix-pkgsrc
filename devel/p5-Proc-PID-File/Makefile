# $NetBSD: Makefile,v 1.3 2008/10/19 19:17:59 he Exp $
#

DISTNAME=		Proc-PID-File-1.27
PKGNAME=		p5-${DISTNAME}
#PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Proc-PID-File/
COMMENT=		Perl module to manage process-ID files
LICENSE=		gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Proc/PID/File/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
