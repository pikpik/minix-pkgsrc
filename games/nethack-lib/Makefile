# $NetBSD$
#

DISTNAME=		nethack-3.2.2
PKGNAME=		nethack-lib-3.2.2
CATEGORIES=		games
MASTER_SITES=		http://pinky.wtower.com/nethack/sources/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.win.tue.nl/games/roguelike/nethack/

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	sys/unix/setup.sh
ALL_TARGET=		datastuff
INSTALL_TARGET=		manpages install-dat

post-patch:
	@${MV} ${WRKSRC}/include/config.h foo
	@${SED} -e 's@XXXLOCALBASEXXX@$(LOCALBASE)@g' <foo> ${WRKSRC}/include/config.h
	@${RM} -f foo

.include "../../mk/bsd.pkg.mk"
