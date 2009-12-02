# $NetBSD$

DISTNAME=	net-scp-1.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	net security

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://rubyforge.org/projects/net-ssh/
COMMENT=	Secure copy for Ruby
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=1.99.1:../../security/ruby-net-ssh

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
