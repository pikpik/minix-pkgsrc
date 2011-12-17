# $NetBSD: Makefile,v 1.1.1.1 2011/12/16 12:15:16 taca Exp $

DISTNAME=	activesupport-${RUBY_RAILS_VERSION}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit of support libraries and Ruby core extensions 3.1
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json

RUBY_RAILS_SUPPORTED=	31

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
