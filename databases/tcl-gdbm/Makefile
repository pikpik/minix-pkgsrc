# $NetBSD: Makefile,v 1.13 2004/03/08 19:52:50 minskim Exp $
#

DISTNAME=	tclgdbm-0.10
PKGNAME=	tcl-gdbm-0.10
CATEGORIES=	databases tcl
MASTER_SITES=	http://www.graphviz.org/pub/tclgdbm/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Tcl interface to gdbm - GNU database manager

DEPENDS+=	tcl>=8.4:../../lang/tcl
DEPENDS+=	gdbm>=1.8.3:../../databases/gdbm

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CFLAGS+=		-I${LOCALBASE}/include		# gdbm.h

.include "../../mk/bsd.pkg.mk"
