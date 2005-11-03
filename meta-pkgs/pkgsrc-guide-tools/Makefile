# $NetBSD: Makefile,v 1.16 2005/09/28 19:16:18 rillig Exp $
#

DISTNAME=	pkgsrc-guide-tools-1.0
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tv@NetBSD.org
COMMENT=	Packages required to build the pkgsrc Guide

_GUIDE_DEPTYPE=	run

.include "../../doc/guide/Makefile.common"

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:
	@${DO_NADA}

.include "../../mk/bsd.pkg.mk"
