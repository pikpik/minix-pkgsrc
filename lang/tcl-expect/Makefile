# $NetBSD: Makefile,v 1.25 2009/08/20 15:24:58 jwise Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGNAME=	tcl-expect-${EXPECT_VERSION}
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extensions to Tcl to support scripting of interactive programs
LICENSE=	public-domain

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--without-x

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR:Q}

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
