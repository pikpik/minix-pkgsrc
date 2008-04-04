# $NetBSD: Makefile,v 1.6 2006/01/03 14:57:52 taca Exp $

DISTNAME=	cmd-0.7.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/cmd/
COMMENT=	Library for building line-oriented command interpreters

DEPENDS+=	${RUBY_PKGPREFIX}-readline-[0-9]*:../../devel/ruby-readline

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
