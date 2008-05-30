# $NetBSD: Makefile,v 1.10 2007/11/15 07:23:16 hiramatsu Exp $
#

DISTNAME=	Array-RefElem-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Array::RefElem
COMMENT=	Set up array elements as aliases

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Array/RefElem/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
