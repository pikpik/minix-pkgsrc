# $NetBSD: Makefile,v 1.6 2003/07/17 22:55:01 grant Exp $

DISTNAME=	ical-2.2.1
CATEGORIES=	time
MASTER_SITES=	http://members.nbci.com/majahj/ical/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://members.nbci.com/majahj/ical/
COMMENT=	Calendar application

USE_BUILDLINK2=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-tclconfig=${PREFIX}/lib \
		--with-tclsh=${PREFIX}/bin/tclsh \
		--with-tkconfig=${PREFIX}/lib

post-configure:
	${TOUCH} ${WRKDIR}/${DISTNAME}/Makefile \
	         ${WRKDIR}/${DISTNAME}/calendar/Makefile \
	         ${WRKDIR}/${DISTNAME}/startup.tcl \
	         ${WRKDIR}/${DISTNAME}/time/Makefile

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
