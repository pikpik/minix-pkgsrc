# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:12 tv Exp $
#

DISTNAME=		gnetman-22Dec04
PKGNAME=		gnetman-20041222
CATEGORIES=		cad
MASTER_SITES=		http://www.viasic.com/opensource/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.viasic.com/opensource/
COMMENT=		Advanced Netlister and Netlist Manipulation Database for gEDA

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

post-extract:
	${RM} ${WRKSRC}/src/include/tcl.h
	${RM} ${WRKSRC}/src/include/tk.h

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
