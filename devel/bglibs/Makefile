# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:18 tv Exp $
#

DISTNAME=		bglibs-1.024
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/bglibs/
COMMENT=		Collection of libraries by Bruce Guenter

BUILD_TARGET=		all
INSTALL_TARGET=		install

DJB_RESTRICTED=		NO

DJB_CONFIG_CMDS=							\
	${ECHO} ${DJB_CONFIG_PREFIX}/include/bglibs > conf-include;	\
	${ECHO} ${DJB_CONFIG_PREFIX}/lib/bglibs > conf-lib;

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
