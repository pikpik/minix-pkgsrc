# $NetBSD: Makefile,v 1.4 2000/03/16 13:50:13 wiz Exp $
#

DISTNAME=	sci.0.3.8
PKGNAME=	sci-0.3.8
CATEGORIES=	misc
MASTER_SITES=	http://linuxparts.com/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://linuxparts.com/software.html

WRKSRC=         ${WRKDIR}/sci

pre-build:
		-@${LN} -s ${WRKSRC}/makefile ${WRKSRC}/Makefile >/dev/null

pre-install:
		-@${GUNZIP_CMD} ${WRKSRC}/sci.1.gz
post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sci
		for i in app APP.README COPYING README allbut.awk edit.awk \
			maillist.awk template.sci template.sci.num sortd \
			whch scidata.out ; \
		do \
			${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/sci ; \
		done

.include "../../mk/bsd.pkg.mk"
