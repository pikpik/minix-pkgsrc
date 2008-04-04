# $NetBSD: Makefile,v 1.4 2007/05/27 04:10:52 obache Exp $
#

DISTNAME=		cairo-1.5.1
PKGNAME=		${RUBY_PKGPREFIX}-r${DISTNAME}
CATEGORIES=		graphics

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://cairographics.org/rcairo/
COMMENT=		Ruby bindings for cairo

USE_TOOLS+=		pkg-config
GEM_BUILD=		gemspec
GEM_CLEANBUILD=		Makefile src/*.o src/cairo.${RUBY_DLEXT} mkmf.log

.include "../../misc/rubygems/rubygem.mk"

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
