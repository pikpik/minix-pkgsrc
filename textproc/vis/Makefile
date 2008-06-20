# $NetBSD: Makefile,v 1.6 2005/12/05 20:51:08 rillig Exp $
#

DISTNAME=	vis-0.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.astron.com/pub/people/christos/

MAINTAINER=	christos@NetBSD.org
COMMENT=	Convert strings from/to a visual format

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q}	\
		MANOWN=${MANOWN:Q} MANGRP=${MANGRP:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
