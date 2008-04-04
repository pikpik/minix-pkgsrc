# $NetBSD: Makefile,v 1.1.1.1 2007/09/21 10:14:37 taca Exp $
#

DISTNAME=	rubysdl-1.3.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rubysdl/SDL/}
PKGREVISION=	1
CATEGORIES=	devel audio graphics

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.kmc.gr.jp/~ohai/rubysdl.en.html
COMMENT=	Ruby extension library to use SDL library

GEM_BUILD=	gemspec
GEM_CLEANBUILD=	Makefile *.o sdl.${RUBY_DLEXT} mkmf.log

.include "../../misc/rubygems/rubygem.mk"

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
