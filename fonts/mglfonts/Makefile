# $NetBSD$

DISTNAME=       fontkit-nobdf
PKGNAME=        mglfonts-0.1
CATEGORIES=     graphics
MASTER_SITES=   http://www.at.sakura.ne.jp/~suz/arc/

MAINTAINER=     fk200329@fsinet.or.jp
HOMEPAGE=	http://www.netbsd.org/Ports/hpcmips/mgl2.html

#HF#DEPENDS= 	mgl>=0.1.9a:../../graphics/mgl

#HF# .include "../../mk/bsd.prefs.mk"

post-extract:
	${MV} -f ${WRKDIR}/fontkit ${WRKDIR}/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
