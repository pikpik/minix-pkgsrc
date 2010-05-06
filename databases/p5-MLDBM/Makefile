# $NetBSD: Makefile,v 1.26 2009/05/31 20:26:42 he Exp $
#

DISTNAME=		MLDBM-2.04
PKGNAME=		p5-${DISTNAME}
#PKGREVISION=		3
SVR4_PKGNAME=		p5mld
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/MLDBM/
COMMENT=		Store multi-level Perl hash structure in single level tied hash
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MLDBM/.packlist
PERL5_MODULE_TYPE=	Module::Build

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
