# $NetBSD: Makefile,v 1.2 2002/06/01 18:21:34 cjep Exp $
#

DISTNAME=	rox-base-1.0.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	Shared ROX resources

DIST_SUBDIR=	rox

USE_BUILDLINK2=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

OWN_DIRS=	${PREFIX}/libexec/rox

post-extract:
	${FIND} ${WRKSRC} -name CVS -print | ${XARGS} ${RM} -rf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/rox
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/rox
	${CP} -Rf ${WRKSRC}/Choices ${PREFIX}/share/rox
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/rox

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
