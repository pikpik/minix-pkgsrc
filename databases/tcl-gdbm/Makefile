# $NetBSD: Makefile,v 1.4 2000/06/13 10:40:25 wiz Exp $
#

DISTNAME=	tclgdbm-0.8
PKGNAME=	tcl-gdbm-0.8
CATEGORIES=	databases tcl
MASTER_SITES=	http://www.graphviz.org/pub/tclgdbm/

MAINTAINER=	bouyer@netbsd.org

DEPENDS+=	tcl-8.3.2:../../lang/tcl80
DEPENDS+=	gdbm>=1.7.3:../../databases/gdbm

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
