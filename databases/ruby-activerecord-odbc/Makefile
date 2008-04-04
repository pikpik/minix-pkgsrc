# $NetBSD$

DISTNAME=	odbc-rails-1.4
PKGNAME=	${RUBY_PKGPREFIX}-activerecord-${DISTNAME:S/-rails//}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://odbc-rails.rubyforge.org/
COMMENT=	ActiveRecord ODBC adapter

DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=1.15:../../databases/ruby-activerecord
DEPENDS+=	${RUBY_PKGPREFIX}-odbc>=0.9991:../../databases/ruby-odbc

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
