# $NetBSD$

DISTNAME=	stringex-1.1.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/rsl/stringex
COMMENT=	Some (hopefully) useful extensions to Rubys String class
LICENSE=	mit

MAKE_ENV+=	RUBYOPT="-Ku"

# Encoding problem: need to be fixed.
RUBY_BUILD_RDOC=	NO
RUBY_BUILD_RI=		NO

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
