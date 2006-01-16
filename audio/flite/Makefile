# $NetBSD$
#

DISTNAME=	flite-1.3-release
PKGNAME=	${DISTNAME:S/-release//}
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/flite/packed/flite-1.3/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.speech.cs.cmu.edu/flite/
COMMENT=	Small and fast run-time synthesis engine

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
