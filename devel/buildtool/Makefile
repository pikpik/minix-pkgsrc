# $NetBSD: Makefile,v 1.1.1.1 2002/10/21 08:16:06 agc Exp $
#

DISTNAME=	buildtool-0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buildtool/}

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://buildtool.sourceforge.net/
COMMENT=	Portable BSD-like build infrastructure

USE_BUILDLINK2=	yes

TEXINFO_REQD=	4.0
INFO_FILES=	buildtool.info

PKG_SYSCONFSUBDIR=	buildtool

do-configure:
	@cd ${WRKSRC} && ${CONFIGURE_ENV} ./configure -p ${LOCALBASE} \
	    -c ${PKG_SYSCONFDIR}

.include "../../mk/texinfo.mk"

.include "../../mk/bsd.pkg.mk"
