# $NetBSD: Makefile,v 1.27 2001/02/17 17:51:44 wiz Exp $
# FreeBSD Id: Makefile,v 1.16 1997/07/13 18:49:29 max Exp
#

DISTNAME=	gv-3.5.8
CATEGORIES=	print
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/gv/unix/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wwwthep.physik.uni-mainz.de/~plass/gv/
COMMENT=	PostScript and PDF previewer

DEPENDS+=	ghostscript-[6-9]*:../../print/ghostscript

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

# We need Xaw3d to build.
.if (${XAW_TYPE} == standard)
XAW_TYPE=	3d
.endif

post-extract:
	${MV} ${WRKSRC}/doc/gv.man ${WRKSRC}/source/

post-install:
	@(cd ${WRKSRC}; ${MAKE} install.doc)

.include "../../mk/xaw.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
