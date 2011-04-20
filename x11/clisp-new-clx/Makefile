# $NetBSD$
#

CLISP_MODULE=	clx/new-clx

PKGNAME=	clisp-new-clx-$(CLISP_VERSION)
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	hans@netbsd.org
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP New CLX module

MAKE_JOBS_SAFE=	no

.include "../../lang/clisp/module.mk"

post-configure:
	(cd ${WRKSRC}/modules && ${CC} ${CPPFLAGS} ${CFLAGS} -o ccmp2c ../utils/ccmp2c.c)

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
