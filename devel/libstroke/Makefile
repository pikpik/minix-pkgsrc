# $NetBSD: Makefile,v 1.4 2000/08/14 17:56:05 wiz Exp $
#

DISTNAME=		libstroke-0.3
PKGNAME=		libstroke-0.3nb1
CATEGORIES=		devel
MASTER_SITES=		http://www.etla.net/libstroke/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.etla.net/libstroke/

DEPENDS+=		tcl-8.3.2:../../lang/tcl

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

CONFIGURE_ENV+=		X_CFLAGS="-I${LOCALBASE}/include"

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
