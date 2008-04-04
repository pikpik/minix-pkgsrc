# $NetBSD: Makefile,v 1.10 2008/02/09 06:31:59 minskim Exp $

DISTNAME=	rails-2.0.2
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Framework for developing database-backed web applications

DEPENDS+=	rake>=0.8.1:../../devel/rake
DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.0.2nb1:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=2.0.2nb1:../../databases/ruby-activerecord
DEPENDS+=	${RUBY_PKGPREFIX}-activeresource>=2.0.2nb1:../../www/ruby-activeresource
DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=2.0.2nb1:../../www/ruby-actionpack
DEPENDS+=	${RUBY_PKGPREFIX}-actionmailer>=2.0.2nb1:../../mail/ruby-actionmailer

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
