# $NetBSD: Makefile,v 1.6 2002/01/30 21:44:57 mjl Exp $
#

DISTNAME=	XML-RegExp-0.03
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xre
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Provide regular expressions for some XML tokens

CONFLICTS+=	p5-libxml-enno-[0-9]*

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/RegExp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
