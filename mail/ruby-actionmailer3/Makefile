# $NetBSD: Makefile,v 1.6 2011/06/11 03:24:05 taca Exp $

DISTNAME=	actionmailer-${RUBY_RAILS_VERSION}
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Email composition, delivery, and receiving framework
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-mail>=2.2.19<2.3:../../mail/ruby-mail

RUBY_RAILS_SUPPORTED=	3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
