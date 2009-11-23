# $NetBSD: Makefile,v 1.2 2008/06/22 16:01:43 taca Exp $

DISTNAME=	RubyInline-3.8.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/^Ruby//:tl}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zenspider.com/ZSS/Products/RubyInline/
COMMENT=	Embed C/C++ code directly in Ruby
LICENSE=	mit

DEPENDS+=	hoe>=1.5.1:../../devel/hoe
DEPENDS+=	ZenTest>=0:../../devel/ZenTest

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
