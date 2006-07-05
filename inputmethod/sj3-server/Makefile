# $NetBSD: Makefile,v 1.7 2005/09/28 18:22:11 rillig Exp $

DISTNAME=	sj3-server-2.0.1.20
PKGREVISION=	3
CATEGORIES=	japanese inputmethod
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	SJ3 Japanese input method server

DEPENDS+=	sj3-server-bin>=2.0.1.20nb6:../../inputmethod/sj3-server-bin
DEPENDS+=	sj3-dict>=2.0.1.20nb3:../../inputmethod/sj3-dict

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	YES
NO_BUILD=	YES
NO_CHECKSUM=	YES

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
