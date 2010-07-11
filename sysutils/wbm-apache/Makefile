# $NetBSD: Makefile,v 1.8 2009/05/16 17:10:40 kefren Exp $

WBM_NAME=	apache

COMMENT=	Webmin module for configuring Apache servers

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../sysutils/webmin/wbm.mk"

CONF_FILES+=	${WBM_EGDIR}/${WBM_NAME}/site \
		${PKG_SYSCONFDIR}/${WBM_NAME}/site

post-build:
	${TOUCH} ${TOUCH_ARGS} ${WRKDIR}/site

post-install:
	${INSTALL_DATA} ${WRKDIR}/site ${DESTDIR}${WBM_EGDIR}/${WBM_NAME}/site

.include "../../mk/bsd.pkg.mk"
