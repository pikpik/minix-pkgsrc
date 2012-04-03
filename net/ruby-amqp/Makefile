# $NetBSD: Makefile,v 1.7 2011/12/15 14:52:01 taca Exp $

DISTNAME=	amqp-0.9.4
CATEGORIES=	net

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/ruby-amqp/amqp
COMMENT=	AMQP client implementation in Ruby/EventMachine
LICENSE=	ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

# ruby-amq-client depends on ruby-eventmachine and ruby-amq-protocol 
#DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0:../../devel/ruby-eventmachine
#DEPENDS+=	${RUBY_PKGPREFIX}-amq-protocol>=0.9.0:../../net/ruby-amq-protocol
DEPENDS+=	${RUBY_PKGPREFIX}-amq-client>=0.9.2<0.10:../../net/ruby-amq-client

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
