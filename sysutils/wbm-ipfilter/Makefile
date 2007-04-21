# $NetBSD: Makefile,v 1.1.1.1 2006/05/16 04:02:54 jlam Exp $

WBM_NAME=	ipfilter

WBM_DEPEND_MODULES+=	net

COMMENT=	Webmin module for IPFilter configuration

post-extract:
	cp ${FILESDIR}/ipfilter_config-netbsd ${WRKSRC}/${WBM_NAME}/config-netbsd

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
