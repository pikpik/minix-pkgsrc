# $NetBSD: Makefile,v 1.4 2010/01/17 12:02:41 wiz Exp $
#

PKGREVISION=	5

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php4
CONFIGURE_ARGS+=	--disable-perl

PKG_DESTDIR_SUPPORT=	destdir

PYTHON_FOR_BUILD_ONLY=	yes

EXTRACT_USING=		bsdtar

.include "../../security/lasso/Makefile.common"
