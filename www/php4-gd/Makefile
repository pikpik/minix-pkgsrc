# $NetBSD$

.include "../../www/php4/Makefile.module"

MODNAME=		gd
CATEGORIES+=		graphics

DEPENDS+=		gd-*:../../graphics/gd

EVAL_PREFIX+=		GDDIR=gd
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${GDDIR}

USE_X11=		# defined

.include "../../mk/bsd.pkg.mk"
