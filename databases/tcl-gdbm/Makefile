# $NetBSD: Makefile,v 1.15 2004/10/03 00:13:24 tv Exp $
#

DISTNAME=	tclgdbm-0.10
PKGNAME=	tcl-gdbm-0.10
PKGREVISION=	1
CATEGORIES=	databases tcl
MASTER_SITES=	http://www.graphviz.org/pub/tclgdbm/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Tcl interface to gdbm - GNU database manager

GNU_CONFIGURE=		# defined
USE_BUILDLINK3=		yes
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CFLAGS+=		-I${LOCALBASE}/include		# gdbm.h
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
