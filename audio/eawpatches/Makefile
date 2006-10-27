# $NetBSD: Makefile,v 1.16 2006/10/04 20:44:18 wiz Exp $
#

DISTNAME=	eawpats12_full
PKGNAME=	eawpatches-12
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	adam@NetBSD.org
COMMENT=	Eric A. Welsh' patches (audio samples) for TiMidity

RESTRICTED=	Some patches are copyrighted, some marked no-commercial-use
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
LICENSE=	generic-nonlicense

USE_TOOLS+=	gzcat tar
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

do-install:
	cd ${PREFIX}/share && \
		gzcat ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | tar xf -
	${SED}  -e "s@/home/user/eawpats@${PREFIX}/share/eawpats@" \
		< ${PREFIX}/share/eawpats/linuxconfig/timidity.cfg \
		> ${PREFIX}/share/eawpats/timidity.cfg
	${RM} -r ${PREFIX}/share/eawpats/linuxconfig \
		${PREFIX}/share/eawpats/winconfig

.include "../../mk/bsd.pkg.mk"
