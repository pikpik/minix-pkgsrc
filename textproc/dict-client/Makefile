# $NetBSD: Makefile,v 1.13 2004/05/04 23:46:36 snj Exp $

DISTNAME=       dictd-1.8.0
PKGNAME=        dict-client-1.8.0
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=   ftp://ftp.dict.org/pub/dict/

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.dict.org/
COMMENT=	Dictionary Service Protocol client

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes

ALL_TARGET=	dict
INSTALL_TARGET=	install.dict

FILESDIR=	${.CURDIR}/../../textproc/dict-server/files
PATCHDIR=	${.CURDIR}/../../textproc/dict-server/patches
DISTINFO_FILE=	${.CURDIR}/../../textproc/dict-server/distinfo

CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
