# $NetBSD: Makefile,v 1.10 2012/11/22 12:04:20 ryoon Exp $
#

TB_VER=		10.0.11
PKGNAME=	thunderbird10-l10n-${TB_VER}
DISTNAME=	# empty
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZILLA_ESR:=thunderbird/releases/${TB_VER}esr/linux-i686/xpi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozillamessaging.com/en-US/thunderbird/
COMMENT=	Language packs for mail/thunderbird

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${XPI_FILES}

NO_BUILD=	yes

TB_LOCALES=	        ar ast be bg bn-BD br ca cs		\
                        da de el en-GB en-US es-AR es-ES et	\
                        eu fi fr fy-NL ga-IE gd gl he		\
                        hu id is it ja ko			\
                        lt nb-NO nl nn-NO			\
                        pa-IN pl pt-BR pt-PT rm ro ru si sk	\
                        sl sq sr sv-SE ta-LK tr uk vi		\
                        zh-CN zh-TW

EXTENSIONS_DIR=		${PREFIX}/lib/thunderbird10/extensions
XPI_FILES=		${TB_LOCALES:=.xpi}

.include "../../devel/xulrunner10/xpi.mk"
.include "../../mk/bsd.pkg.mk"
