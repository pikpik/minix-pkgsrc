# $NetBSD: Makefile,v 1.4 2001/02/17 18:08:53 wiz Exp $
#

DISTNAME=       chipmunk-1.4
CATEGORIES=	misc
MASTER_SITES=   http://www.bitwizard.nl/chipmunk/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.bitwizard.nl/chipmunk/index.html
COMMENT=	shell-like tool for hardware debugging

ONLY_FOR_PLATFORM=	NetBSD-*-i386

.include "../../devel/readline/Makefile.readline"

ALL_TARGET=	chipmunk
MAKE_ENV+=	CONFIG_OPTIONS="${CPPFLAGS}"
MAKE_ENV+=	EXTRA_LIBS=-li386

CPPFLAGS+=	-I${WRKINCDIR}
LDFLAGS+=	-L${WRKLIBDIR}

pre-configure: link-readline-headers link-readline-libs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chipmunk ${PREFIX}/sbin/chipmunk

.include "../../mk/bsd.pkg.mk"
