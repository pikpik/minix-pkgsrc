# $NetBSD$
#

DISTNAME=	freepats-20040611
CATEGORIES=	audio
MASTER_SITES=	http://freepats.opensrc.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://freepats.opensrc.org/
COMMENT=	Free patches (audio samples) for TiMidity

WRKSRC=		${WRKDIR}/freepats
NO_CONFIGURE=	yes
NO_BUILD=	yes

MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

post-patch:
	${ECHO} "dir ${PREFIX}/share/freepats" >${WRKSRC}/timidity.cfg
	${CAT} ${WRKSRC}/freepats.cfg >>${WRKSRC}/timidity.cfg

do-install:
	cd ${WRKDIR} && ${PAX} -rw -pe freepats ${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
