# $NetBSD: Makefile,v 1.1.1.1 2000/02/20 04:32:26 wiz Exp $
#

DISTNAME=	cftp-0.10
CATEGORIES=	net
MASTER_SITES=	ftp://sunsite.csd.smc.univie.ac.at/pub/nih/cftp/ \
		ftp://ftp.giga.or.at/pub/nih/cftp/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://sunsite.csd.smc.univie.ac.at/pub/nih/cftp/

GNU_CONFIGURE=	YES
INFO_FILES=	cftp.info

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cftp
	cd ${WRKSRC} && ${INSTALL_MAN} README bindings.desc \
		${PREFIX}/share/doc/cftp

.include "../../mk/bsd.pkg.mk"
