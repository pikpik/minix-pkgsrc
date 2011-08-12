# $NetBSD: Makefile,v 1.4 2011/06/19 01:49:27 taca Exp $

DISTNAME=	launchy-2.0.5
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://copiousfreetime.rubyforge.org/launchy/
COMMENT=	Ruby class for launching applications
LICENSE=	isc

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.2.6<2.3:../../net/ruby-addressable

USE_RAKE=	YES

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
