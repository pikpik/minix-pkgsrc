# $NetBSD$
#

DISTNAME=		ec-fonts-mftraced-1.0.8
CATEGORIES=		fonts
MASTER_SITES=		http://lilypond.org/download/fonts/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://lilypond.org/
COMMENT=		EC PostScript Type1 fonts with TFMs for TeX

DEPENDS+=		teTeX>=2.0.2:../../print/teTeX

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
MAKEFILE=		GNUmakefile

.include "../../mk/bsd.pkg.mk"
