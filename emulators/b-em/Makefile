# $NetBSD: Makefile,v 1.3 2012/08/12 02:03:15 marino Exp $
#

DISTNAME=	B-emv2.2Linux
PKGNAME=	b-em-2.2
CATEGORIES=	emulators
MASTER_SITES=	http://b-em.bbcmicro.com/

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://b-em.bbcmicro.com/
COMMENT=	Freeware Acorn BBC Micro Emulator with 2nd processors
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

BEMDATADIR=	${PREFIX}/share/b-em/

SUBST_CLASSES+=		paths d2u
SUBST_MESSAGE.paths=	Fixing non-existing paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/linux.c src/win.c
SUBST_SED.paths=	-e 's,@BEMDATADIR@,${BEMDATADIR},g'

SUBST_MESSAGE.d2u=	Removing CR end-of-line markers
SUBST_STAGE.d2u=	post-extract
SUBST_FILES.d2u=	src/win.c src/linux.c
SUBST_FILTER_CMD.d2u=	${TR} -d '\r'

do-install:
	${INSTALL} -d ${DESTDIR}${PREFIX}/bin
	${INSTALL} -d ${DESTDIR}${BEMDATADIR}/roms
	${INSTALL} -d ${DESTDIR}${BEMDATADIR}/discs
	${INSTALL} -d ${DESTDIR}${BEMDATADIR}/tapes
	${INSTALL} -d ${DESTDIR}${BEMDATADIR}/ddnoise
	${INSTALL_PROGRAM} ${WRKSRC}/b-em ${DESTDIR}${PREFIX}/bin/b-em
	${CP}    ${WRKSRC}/cmos*.bin ${DESTDIR}${BEMDATADIR}/
	${CP} -R ${WRKSRC}/roms/*    ${DESTDIR}${BEMDATADIR}/roms
	${CP} -R ${WRKSRC}/discs/*   ${DESTDIR}${BEMDATADIR}/discs
	${CP} -R ${WRKSRC}/tapes/*   ${DESTDIR}${BEMDATADIR}/tapes
	${CP} -R ${WRKSRC}/ddnoise/* ${DESTDIR}${BEMDATADIR}/ddnoise
	${FIND} ${DESTDIR}${BEMDATADIR} -type f -exec chmod 644 {} \;

.include "../../devel/allegro/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../audio/freealut/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
