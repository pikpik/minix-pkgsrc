# $NetBSD$

DISTNAME=	ruby-debug-ide-0.1.10
PKGNAME=	${RUBYGEM_PKGPREFIX}-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://debug-commons.rubyforge.org/
COMMENT=	IDEs interface to ruby-debug

DEPENDS+=	${RUBYGEM_PKGPREFIX}-ruby-debug-base-[0-9]*:../../devel/ruby-debug-base

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
