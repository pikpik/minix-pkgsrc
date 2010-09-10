# $NetBSD: Makefile,v 1.2 2009/06/12 14:02:30 taca Exp $

DISTNAME=	activemerchant-1.7.2
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://activemerchant.org/
COMMENT=	Ruby library for credit card processing
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=1.4.1:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.0.0:../../textproc/ruby-builder

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
