# $NetBSD$
#

DISTNAME=       cucipop-1.31
CATEGORIES=     mail
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/cucipop/

MAINTAINER=	packages@netbsd.org

LICENSE=	shareware

post-patch:
	@(cd ${WRKSRC};							\
	for f in config.h cucipop.8 makevpopdb.8; do			\
		${SED} -e 's|@prefix@|${PREFIX}|g' $$f > $$f.fixed &&	\
		${MV} $$f.fixed $$f;					\
	done)

.include "../../mk/bsd.pkg.mk"
