# $NetBSD: Makefile,v 1.11 2006/03/04 21:29:05 jlam Exp $
#

DISTNAME=	Device-Modem-1.48
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dmd
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module to talk to modem devices connected via serial port

DEPENDS+=	p5-Device-SerialPort>=0.19:../../comms/p5-Device-SerialPort

PERL5_PACKLIST=		auto/Device/Modem/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
