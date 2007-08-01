# $NetBSD: Makefile,v 1.4 2006/10/04 21:53:17 wiz Exp $
#

DISTNAME=	pconsole-1.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.ka.sara.nl/home/walter/pconsole/

MAINTAINER=	frueauf@NetBSD.org
HOMEPAGE=	http://www.ka.sara.nl/home/walter/pconsole/
COMMENT=	Parallel console tool to access several host via one input tty

GNU_CONFIGURE=	yes

USE_TOOLS+=	ksh:run

REPLACE_KSH=	pconsole.sh.in

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	pconsole.sh.in
SUBST_VARS.path=	PREFIX X11PREFIX

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pconsole
	cd ${WRKSRC} && ${INSTALL_DATA} \
	 	README.pconsole ${PREFIX}/share/doc/pconsole

.include "../../mk/bsd.pkg.mk"
