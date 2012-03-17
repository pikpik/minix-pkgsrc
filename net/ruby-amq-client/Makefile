# $NetBSD: Makefile,v 1.1.1.1 2011/12/15 14:48:58 taca Exp $

DISTNAME=	amq-client-0.9.2
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/ruby-amqp/amq-client
COMMENT=	Fully-featured, low-level AMQP 0.9.1 client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-amq-protocol>=0.9.0:../../net/ruby-amq-protocol

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
