# $NetBSD: Makefile,v 1.34 2001/10/17 12:47:19 dmcmahill Exp $
#

DISTNAME=		tgif-4.1.42
CATEGORIES=		graphics
MASTER_SITES=		ftp://bourbon.usc.edu/pub/tgif/free-of-charge/

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://bourbon.usc.edu:8001/tgif/tgif.html
COMMENT=		Fully-featured X11 drawing program

USE_IMAKE=		yes
USE_X11=		yes

USE_PTHREAD=	native pth
.include "../../mk/bsd.prefs.mk"

post-patch::
	@${RM} -f ${WRKSRC}/Tgif.tmpl
	@${CP} ${WRKSRC}/Tgif.tmpl-netbsd ${WRKSRC}/Tgif.tmpl

.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
