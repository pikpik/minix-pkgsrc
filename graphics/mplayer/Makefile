# $NetBSD: Makefile,v 1.19 2002/03/13 17:37:13 fredb Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/MP/mp/}
PKGREVISION=	2
MASTER_SITES=	http://mp.dev.hu/MPlayer/releases/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/DOCS/mplayer.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer
	${INSTALL_DATA} ${WRKSRC}/etc/codecs.conf ${PREFIX}/share/mplayer
	${CP} -R ${WRKSRC}/DOCS ${PREFIX}/share/mplayer

.include "../../audio/lame/buildlink.mk"
.include "../../devel/SDL/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../misc/libdvdread/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
