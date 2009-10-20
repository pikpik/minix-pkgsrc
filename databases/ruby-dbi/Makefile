# $NetBSD: Makefile,v 1.1.1.1 2009/10/17 12:26:59 taca Exp $

DISTNAME=	dbi-0.4.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-dbi/
COMMENT=	Database independent interface for Ruby
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-deprecated>=2.0.0:../../devel/ruby-deprecated

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
