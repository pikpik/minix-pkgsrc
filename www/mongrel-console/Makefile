# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:25:46 jlam Exp $

DISTNAME=	mongrel_console-0.2.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/fauna/mongrel
COMMENT=	Mongrel & Rails IRB console
LICENSE=	# unknown

DEPENDS+=	${RUBY_PKGPREFIX}-mongrel>=1.0.2:../../www/mongrel

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
