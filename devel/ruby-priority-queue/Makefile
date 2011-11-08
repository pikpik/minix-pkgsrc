# $NetBSD: Makefile,v 1.6 2011/02/21 16:01:15 taca Exp $

DISTNAME=	PriorityQueue-0.1.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/PriorityQueue/priority-queue/}
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/priority-queue/
COMMENT=	Fibonacci-heap priority-queue implementation for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

pre-configure:
	${CP} ${FILESDIR}/gemspec ${GEM_SPECFILE}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
