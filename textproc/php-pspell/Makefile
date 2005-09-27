# $NetBSD$

MODNAME=		pspell
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP extension for pspell support


CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.aspell}

.include "../../lang/php/ext.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
