# $NetBSD$

DISTNAME=	gocr-0.37
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jocr/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/jocr
COMMENT=	GOCR is s set set of OCR tools

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAKE_ENV+=	LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

.include "../../mk/bsd.pkg.mk"
