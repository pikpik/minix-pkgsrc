# New ports collection makefile for:	logo
# Version required:	4.6
# Date created:		18 Feb 1999
# Whom:			proff
#
# $NetBSD$

DISTNAME=	ucblogo-4.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
# otherwise ./configure guesses -L incorrectly
CONFIGURE_ENV+=	LIBS=-L/usr/X11R6/lib
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
