# $NetBSD: Makefile,v 1.8 2000/08/28 18:20:37 jlam Exp $
#

DISTNAME=	ControlX10-CM11-2.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ControlX10/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://members.aol.com/Bbirthisel/alpha.html

DEPENDS+=	p5-Device-SerialPort>=0.070:../../comms/p5-Device-SerialPort

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/ControlX10/CM11/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
