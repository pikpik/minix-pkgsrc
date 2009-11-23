# $NetBSD$

DISTNAME=	polyglot-0.2.9
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://polyglot.rubyforge.org/
COMMENT=	Registry of file types to load with its improved version of 'require'
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	hoe>=2.3.2:../../devel/hoe

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
