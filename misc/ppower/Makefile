# $NetBSD: Makefile,v 1.6 2006/10/25 12:44:26 dsainty Exp $
#

DISTNAME=	ppower-0.1.5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ppower/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://ppower.sourceforge.net/
COMMENT=	X10 controller software for the CM11A interface

PKG_DESTDIR_SUPPORT=	user-destdir

#LICENSE=       	GPL

GNU_CONFIGURE=		YES
USE_TOOLS+=		lex

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/ppower
CONF_FILES+=		${EGDIR}/ppower.conf ${PKG_SYSCONFDIR}/ppower.conf

INSTALLATION_DIRS=	share/examples/ppower

post-install:
	${INSTALL_DATA} \
		${WRKSRC}/etc/ppower.conf ${DESTDIR}${PREFIX}/share/examples/ppower

.include "../../mk/bsd.pkg.mk"
