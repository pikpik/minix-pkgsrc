# $NetBSD$
#

DISTNAME=	ctags-5.0.1
PKGNAME=	ex${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctags/}

MAINTAINER=	seb@pbox.org
HOMEPAGE=	http://ctags.sourceforge.net/
COMMENT=	Exuberant (feature-filled) tagfile generator for vi, emacs and clones

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-macro-patterns
CONFIGURE_ARGS+=	--disable-etags

.include "../../mk/bsd.pkg.mk"
