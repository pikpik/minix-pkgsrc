# $NetBSD: Makefile,v 1.1.1.1 2002/07/01 12:31:35 wiz Exp $
#

DISTNAME=	XML-Handler-YAWriter-0.23
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xhy
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@netbsd.org
COMMENT=	another Perl module for writing XML documents

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Handler/YAWriter/.packlist
REPLACE_PERL=		xmlpretty

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
