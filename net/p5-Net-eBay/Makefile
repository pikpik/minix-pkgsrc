# $NetBSD: Makefile,v 1.7 2006/03/04 21:30:22 jlam Exp $

DISTNAME=		Net-eBay-0.40
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://www.net-ebay.org/
COMMENT=		Perl Interface to XML based eBay API

DEPENDS+=              p5-Crypt-SSLeay-[0-9]*:../../security/p5-Crypt-SSLeay
DEPENDS+=              p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay
DEPENDS+=              p5-XML-Dumper-[0-9]*:../../textproc/p5-XML-Dumper
DEPENDS+=              p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=              p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/Net/eBay/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
