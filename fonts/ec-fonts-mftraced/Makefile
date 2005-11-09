# $NetBSD: Makefile,v 1.5 2005/05/22 20:07:59 jlam Exp $
#

DISTNAME=		ec-fonts-mftraced-1.0.8
CATEGORIES=		fonts
MASTER_SITES=		http://lilypond.org/download/fonts/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://lilypond.org/
COMMENT=		EC PostScript Type1 fonts with TFMs for TeX

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
MAKEFILE=		GNUmakefile
MAKE_ENV+=		PKG_LOCALTEXMFPREFIX=${PKG_LOCALTEXMFPREFIX}

post-install:
	${PREFIX}/bin/mktexlsr

.include "../../fonts/mftrace/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
