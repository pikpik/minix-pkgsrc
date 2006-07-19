# $NetBSD: Makefile,v 1.15 2006/03/04 21:30:50 jlam Exp $

DISTNAME=	XML-RSS-1.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xrs
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-RSS/
COMMENT=	XML-RSS helps to create and update RSS files

DEPENDS+=	p5-XML-Parser>=2.29:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Test-Manifest>=0.9:../../devel/p5-Test-Manifest

PERL5_PACKLIST=		auto/XML/RSS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
