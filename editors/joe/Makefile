# $NetBSD: Makefile,v 1.10 2001/02/16 14:40:50 wiz Exp $
#

DISTNAME=	joe2.8
PKGNAME=	joe-2.8nb1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.std.com/src/editors/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	explorer@netbsd.org
COMMENT=	Joe's own editor

ALL_TARGET=	joe
WRKSRC=		${WRKDIR}/joe

CFLAGS+=	-DTERMINFO

.include "../../mk/bsd.pkg.mk"
