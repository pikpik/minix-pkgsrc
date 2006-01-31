# $NetBSD: Makefile,v 1.6 2005/08/06 06:19:39 jlam Exp $

DISTNAME=      	Kwiki-Edit-RequireUserName-0.02
PKGNAME=       	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/JPEREGR/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki plugin to require a user name to edit

DEPENDS+=	p5-Kwiki>=0.37nb1:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Edit/RequireUserName/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
