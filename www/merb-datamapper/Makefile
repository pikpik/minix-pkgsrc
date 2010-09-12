# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:23:53 jlam Exp $

DISTNAME=	merb_datamapper-1.1.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	databases www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/merb/merb_datamapper
COMMENT=	Merb plugin for the DataMapper ORM
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=0.10.2:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-dm-migrations>=0.10.2:../../databases/ruby-dm-migrations

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
