# $NetBSD: Makefile,v 1.42 2007/12/31 00:08:22 obache Exp $

DISTNAME=	RMagick-2.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/29810/ \
		http://raa.ruby-lang.org/cache/rmagick/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby binding to ImageMagick

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_SETUP=		yes

CONFIGURE_ARGS+=	--doc-dir=${RUBY_DOCDIR}/RMagick
USE_TOOLS+=	gs

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/RMagick
	cd ${WRKSRC}/examples && \
		${PAX} -rw -pp -pm . ${RUBY_EXAMPLESDIR}/RMagick

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
