# $NetBSD: Makefile,v 1.4 2001/11/26 06:49:37 jlam Exp $
#

DISTNAME=	Audio-CD-0.05
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5acd
CATEGORIES=	audio
MASTER_SITES=	http://home.wanadoo.nl/~jano/files/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://home.wanadoo.nl/~jano/disc-cover.html
COMMENT=	Audio-CD perl module for use with disc-cover

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Audio/CD/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../audio/libcdaudio/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
