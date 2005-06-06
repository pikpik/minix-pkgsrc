# $NetBSD: Makefile,v 1.4 2005/06/06 03:07:25 jlam Exp $

DISTNAME=	vmpsd-1.3
PKGNAME= 	openvmps-1.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vmps/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://vmps.sourceforge.net/
COMMENT=	GPL implementation of the VMPS protocol

WRKSRC=		${WRKDIR}/vmpsd

GNU_CONFIGURE=	YES
USE_PKGINSTALL=	YES

EGDIR=		${PREFIX}/share/examples/openvmps
RCD_SCRIPTS=	vmpsd
RCD_SCRIPT_WRK.vmpsd= ${WRKDIR}/vmpsd.rcd #conflict with ${WRKSRC}

CONF_FILES=	${EGDIR}/vlan.db ${PKG_SYSCONFDIR}/vlan.db

.include "../../mk/bsd.pkg.mk"
