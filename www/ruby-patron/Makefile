# $NetBSD$

DISTNAME=	patron-0.4.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://toland.github.com/patron/
COMMENT=	Ruby HTTP client library based on libcurl
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GEM_BUILD=	gemspec

.include "../../www/curl/buildlink3.mk"
.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
