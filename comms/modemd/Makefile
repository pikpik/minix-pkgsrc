# New ports collection makefile for:	modemd
# Version required:	970221
# Date created:		12 December 1997
# Whom:			tsarna@endicor.com
#
# $NetBSD$

DISTNAME=	modemd-970221
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.vix.com/pub/modemd/

MAINTAINER=	tsarna@endicor.com

# Do not list MAN/CAT pages here. It will confuse if MANZ is set.
# The pkg uses BSD-style-Makefiles itself, so it does the right thing.

pre-install:
	${MKDIR} ${PREFIX}/share/examples/modemd

.include <bsd.port.mk>
