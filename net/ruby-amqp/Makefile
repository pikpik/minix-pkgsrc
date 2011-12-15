# $NetBSD: Makefile,v 1.6 2011/09/12 13:29:22 taca Exp $

DISTNAME=	amqp-0.8.4
CATEGORIES=	net

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/ruby-amqp/amqp
COMMENT=	AMQP client implementation in Ruby/EventMachine
LICENSE=	ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-amq-client>=0.8.7<0.9:../../net/ruby-amq-client

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
