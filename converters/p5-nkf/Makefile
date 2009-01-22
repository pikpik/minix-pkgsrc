# $NetBSD: Makefile,v 1.16 2008/10/19 19:17:42 he Exp $
#

.include "../../converters/nkf/Makefile.common"

PKGNAME=	p5-nkf-2.09
SVR4_PKGNAME=	p5nkf
CATEGORIES=	japanese converters perl5

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Perl library for Network Kanji code conversion Filter

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c

PERL5_CONFIGURE_DIRS=	NKF.mod
BUILD_DIRS=		${PERL5_CONFIGURE_DIRS}
PERL5_PACKLIST=		auto/NKF/.packlist

SUBST_CLASSES+=		sp
SUBST_STAGE.sp=		pre-configure
SUBST_FILES.sp=		nkf.c
SUBST_SED.sp=		-e 's/SP/SPSP/g'

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
