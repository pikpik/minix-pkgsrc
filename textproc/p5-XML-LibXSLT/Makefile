# $NetBSD: Makefile,v 1.11 2006/02/05 23:11:04 joerg Exp $
#

DISTNAME=	XML-LibXSLT-1.61
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xlt
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	adam@migus.org
HOMEPAGE=	http://search.cpan.org/dist/XML-LibXSLT/
COMMENT=	Perl interface to the libxslt library

DEPENDS+=	p5-XML-LibXML>=1.60:../../textproc/p5-XML-LibXML

PERL5_PACKLIST=	auto/XML/LibXSLT/.packlist

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
