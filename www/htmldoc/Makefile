# $NetBSD: Makefile,v 1.17 2002/05/06 21:42:37 seb Exp $
#

.include "${.CURDIR}/Makefile.common"

PKGNAME=	htmldoc-${HTMLDOC_VERSION}
COMMENT=	Converts HTML to indexed HTML, PDF and/or PostScript

CONFLICTS=		htmldoc-x11-[0-9]*

CONFIGURE_ARGS+=	--without-gui --without-x

.include "../../mk/bsd.pkg.mk"
