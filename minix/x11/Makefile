# $NetBSD$

DISTNAME=X11R${XORG_VER}
PKGNAME=	x11-${XORG_VER}
XORG_VER=	6.8.2
CATEGORIES=	minix x11
MASTER_SITES= ${MASTER_SITE_MINIX}
EXTRACT_SUFX= .tar.gz

MAINTAINER=	gautam.bt@gmail.com
HOMEPAGE= http://www.x.org/
COMMENT=	X11 from bigports

X11R6_SUBPREFIX=	X11R6
X11R6_PREFIX=	${PREFIX}/${X11R6_SUBPREFIX}

NO_CONFIGURE=	yes
BUILD_TARGET=	World

USE_TOOLS+=	perl
MAKE_FLAGS+=	"BOOTSTRAPCFLAGS=-DMINIX3GCCDEVEL"

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-extract
SUBST_MESSAGE.path=	Adjusting path.
SUBST_FILES.path=	config/cf/minix3.cf x11.pc programs/xdm/config/Xsession
SUBST_FILES.path+=	config/imake/imakemdep.h config/imake/imake.c Makefile
SUBST_SED.path=		-e "s|/usr/X11R6-gcc|${X11R6_PREFIX}|g"
SUBST_SED.path+=	-e "s|/usr/X11R6|${X11R6_PREFIX}|g"
SUBST_SED.path+=	-e "s|/usr/gnu/bin/gcc|gcc|g"

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && ${FIND} ${X11R6_SUBPREFIX} \( -type f -o -type l \) -print | ${SORT};

post-extract:
	${CP} ${FILESDIR}/util.S ${WRKSRC}/programs/Xserver/hw/xfree86/os-support/minix3/
	${CP} ${FILESDIR}/assyntax.h ${WRKSRC}/programs/Xserver/hw/xfree86/os-support/assyntax.h

post-install:
	${CP} ${WRKSRC}/x11.pc ${X11R6_PREFIX}/lib/pkgconfig/x11.pc
	${RM} -r ${X11R6_PREFIX}/lib/X11/doc/PDF
#	${MV} "${X11R6_PREFIX}/bin" "${X11R6_PREFIX}/bin.all" 
#	${MKDIR} "${X11R6_PREFIX}/bin"
#	${MV} ${X11R6_PREFIX}/bin.all/xmkmf ${X11R6_PREFIX}/bin.all/imake \
#		  ${X11R6_PREFIX}/bin.all/makedepend ${X11R6_PREFIX}/bin
#	${RM} -r ${X11R6_PREFIX}/bin.all

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
