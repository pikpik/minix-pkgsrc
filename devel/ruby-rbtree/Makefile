# $NetBSD: Makefile,v 1.1.1.1 2007/04/21 10:20:05 wiz Exp $

DISTNAME=	rbtree-0.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geocities.co.jp/SiliconValley-PaloAlto/3388/rbtree/README.html
COMMENT=	Sorted associative collection using Red-Black Trees for Ruby

GEM_BUILD=	gemspec
GEM_CLEANBUILD=	Makefile *.o mkmf.log

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
