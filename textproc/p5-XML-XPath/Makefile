# $NetBSD: Makefile,v 1.5 2001/11/26 06:50:26 jlam Exp $

DISTNAME=	XML-XPath-1.08
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xxp
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://sergeant.org
COMMENT=	XML XPath software

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/XPath/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
