# $NetBSD: Makefile,v 1.2 2010/01/29 19:37:48 joerg Exp $
#

DISTNAME=		gate-2.06
CATEGORIES=		editors
MASTER_SITES=		http://www.unixpapa.com/software/

MAINTAINER=		hugor@users.sourceforge.net
HOMEPAGE=		http://www.unixpapa.com/gate.html
COMMENT=		Lightweight text editor

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
BUILD_TARGET=		# empty

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=		getline
SUBST_STAGE.getline=	pre-configure
SUBST_MESSAGE.getline=	Fixing conflict with POSIX getline.
SUBST_FILES.getline=	gate.h line.c main.c spel.c subs.c
SUBST_SED.getline=	-e 's/getline/get_line/'

.include	"../../mk/bsd.pkg.mk"
