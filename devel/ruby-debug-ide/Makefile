# $NetBSD: Makefile,v 1.5 2010/09/07 17:20:25 taca Exp $

DISTNAME=	ruby-debug-ide-0.4.10
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/debug-commons/
COMMENT=	IDEs interface to ruby-debug
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-debug-base-[0-9]*:../../devel/ruby-debug-base

RUBY_VERSION_SUPPORTED= 18

pre-configure:
	${RM} -fr ${WRKSRC}/ext

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
