# $NetBSD: Makefile,v 1.8 2001/04/28 23:59:18 jtb Exp $

DISTNAME=	chemtool-1.3
CATEGORIES=	biology
MASTER_SITES=	http://www.uni-ulm.de/~s_tvolk/chemtool/src/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.uni-ulm.de/~s_tvolk/chemtool.html
COMMENT=	Program for drawing organic molecules

USE_BUILDLINK_ONLY=	YES
MAKE_ENV+=	PKGLOCALEDIR="${PKGLOCALEDIR}"
MAKE_ENV+=	GTK_CONFIG="${BUILDLINK_CONFIG_WRAPPER.gtk}"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/chemtool
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/chemtool
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/chemtool
	cd ${WRKSRC} && ${INSTALL_DATA} README TODO 			\
		${PREFIX}/share/doc/chemtool/

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
