# $NetBSD$
#

DISTNAME=	p4web
HOMEPAGE=	http://www.perforce.com/perforce/products/p4web.html
COMMENT=	Perforce SCM Web client

P4BINONLY=	# defined

.include "../../devel/p4/Makefile.common"

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		${PREFIX}/bin/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
