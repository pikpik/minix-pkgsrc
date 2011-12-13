# $NetBSD: Makefile,v 1.7 2011/08/12 15:17:01 taca Exp $

DISTNAME=	activemodel-${RUBY_RAILS_VERSION}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.1.2:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.5.0:../../devel/ruby-i18n

RUBY_RAILS_SUPPORTED=	3

OVERRIDE_GEMSPEC+=	builder>=2.1.2 i18n>=0.5.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
