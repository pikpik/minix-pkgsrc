# $NetBSD: Makefile,v 1.5 2005/04/11 21:45:59 tv Exp $

DISTNAME=		gpspoint-2.030521
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		http://gpspoint.dnsalias.net/gpspoint2/download/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://gpspoint.dnsalias.net/gpspoint2/
COMMENT=		Program to download and upload waypoints to and from your GPS device

DEPENDS+=		dialog>=0.6:../../misc/dialog

USE_PKGLOCALEDIR=       yes
USE_LIBTOOL=            yes
GNU_CONFIGURE=          yes

REPLACE_INTERPRETER+=	bash
_REPLACE.bash.old=	/bin/bash
_REPLACE.bash.new=	${SH:Q}
_REPLACE_FILES.bash=	src/mgpspoint

.include "../../mk/bsd.pkg.mk"
