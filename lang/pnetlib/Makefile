# $NetBSD$
#

.include "${.CURDIR}/Makefile.common"

USE_X11=		yes

CONFIGURE_ARGS+=	--enable-xft
CONFIGURE_ARGS+=	--with-x

PLIST_SUBST+=		WITH_X11=

CONFLICTS=		pnetlib-nox11-[0-9]*

.include "../../fonts/Xft2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
