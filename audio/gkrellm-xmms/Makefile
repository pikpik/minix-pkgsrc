# $NetBSD: Makefile,v 1.5 2003/05/02 11:53:40 wiz Exp $

DISTNAME=	gkrellmms-0.5.6
PKGREVISION=	1
PKGNAME=	gkrellm-xmms-0.5.6
WRKSRC=		${WRKDIR}/gkrellmms
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://gkrellm.luon.net/gkrellmms.phtml
COMMENT=	gkrellm xmms plugin

USE_BUILDLINK2=	YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../audio/xmms/buildlink2.mk"
.include "../../sysutils/gkrellm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
