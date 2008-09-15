# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:18:41 jlam Exp $

DISTNAME=	test-spec-0.9.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://test-spec.rubyforge.org/test-spec/
COMMENT=	BDD interface over Test::Unit

GEM_BUILD=	gemspec

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
