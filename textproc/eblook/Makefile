# $NetBSD: Makefile,v 1.10 2003/08/09 11:27:46 seb Exp $
#

DISTNAME=	eblook-1.6
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/edict/eblook/dist/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/edict/eblook/
COMMENT=	Interactive command-line interface for EPWING electric dictionaries

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
INFO_FILES=	eblook.info

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/eb/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
