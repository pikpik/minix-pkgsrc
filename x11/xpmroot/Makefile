#
# New packages collection makefile for:	xpmroot
# Version required:	2.0.46
# Date created:		24 Mar 1998
# Whom:			tron@netbsd.org
#
# $NetBSD$
#

DISTNAME=	fvwm-2.0.46
PKGNAME=	xpmroot-1.01
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/sources/2.0.x/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/sources/2.0.x/ \
		ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/

MAINTAINER=	tron@netbsd.org

LIB_DEPENDS=	Xpm.4.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
CAT1= 		xpmroot.0

WRKSRC=		${WRKDIR}/fvwm-2.0.46/xpmroot

.include <bsd.port.mk>
