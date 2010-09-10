# $NetBSD: Makefile,v 1.2 2008/04/30 18:02:02 jlam Exp $

DISTNAME=	acts_as_versioned-0.2.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ar-versioned.rubyforge.org/
COMMENT=	Simple versioning for ActiveRecord
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=1.10.1:../../databases/ruby-activerecord

# Note: acts_as_versioned-0.6.0 supports only rails3.

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
