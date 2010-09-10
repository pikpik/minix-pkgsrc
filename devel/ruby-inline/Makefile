# $NetBSD: Makefile,v 1.3 2009/11/23 13:50:06 fhajny Exp $

DISTNAME=	RubyInline-3.8.6
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/^Ruby//:tl}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zenspider.com/ZSS/Products/RubyInline/
COMMENT=	Embed C/C++ code directly in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ZenTest>=4.3:../../devel/ZenTest

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
