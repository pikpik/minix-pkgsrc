# $NetBSD: Makefile,v 1.1.1.1 2002/05/06 21:44:43 seb Exp $
#

.include "../htmldoc/Makefile.common"

PKGNAME=	htmldoc-x11-${HTMLDOC_VERSION}
COMMENT=	Converts HTML to indexed HTML, PDF and/or PostScript (GUI available)

CONFLICTS=		htmldoc-[0-9]*

USE_X11=		# defined
CONFIGURE_ARGS+=	--with-gui --with-x

.include "../../x11/fltk/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
