# $NetBSD: Makefile,v 1.6 2007/10/08 08:47:09 obache Exp $

WBM_NAME=	apache
PKGREVISION=	2

COMMENT=	Webmin module for configuring Apache servers

.include "../../sysutils/webmin/wbm.mk"

CONF_FILES_PERMS+=	${WBM_EGDIR}/${WBM_NAME}/site			\
			${PKG_SYSCONFDIR}/${WBM_NAME}/site		\
			${ROOT_USER} ${ROOT_GROUP} 0644

post-build:
	${TOUCH} ${TOUCH_ARGS} ${WRKDIR}/site

post-install:
	${INSTALL_DATA} ${WRKDIR}/site ${WBM_EGDIR}/${WBM_NAME}/site

.include "../../mk/bsd.pkg.mk"
