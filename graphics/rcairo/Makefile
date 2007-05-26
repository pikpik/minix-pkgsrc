# $NetBSD: Makefile,v 1.13 2007/04/01 01:58:38 obache Exp $

DISTNAME=	rcairo-1.4.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics ruby
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://cairographics.org/rcairo/
COMMENT=	Ruby bindings for cairo

USE_TOOLS+=	pkg-config

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0

.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
