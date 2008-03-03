# $NetBSD: Makefile,v 1.2 2005/06/16 06:57:47 jlam Exp $
#

DISTNAME=	p4web
HOMEPAGE=	http://www.perforce.com/perforce/products/p4web.html
COMMENT=	Perforce SCM Web client

PKG_DESTDIR_SUPPORT=	user-destdir

P4BINONLY=	# defined

.include "../../devel/p4/Makefile.common"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/bin/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
