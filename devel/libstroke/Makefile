# $NetBSD: Makefile,v 1.20 2006/07/19 19:14:38 jlam Exp $
#

DISTNAME=		libstroke-0.5.1
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		http://www.etla.net/libstroke/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.etla.net/libstroke/
COMMENT=		Stroke translation library

PKG_INSTALLATION_TYPES= overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake

CONFIGURE_ENV+=		ac_cv_path_GTK_CONFIG=no

BUILDLINK_DEPMETHOD.libX11?=	build

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
