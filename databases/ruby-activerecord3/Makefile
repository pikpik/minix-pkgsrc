# $NetBSD: Makefile,v 1.3 2011/02/09 13:00:07 taca Exp $

DISTNAME=	activerecord-${RUBY_RAILS3_VERSION}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Object-relational mapper framework
LICENSE=	mit

RUBY_RAILS=	3

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-arel>=2.0.2<2.1:../../databases/ruby-arel
DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo>=0.3.23<0.4:../../time/ruby-tzinfo

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
