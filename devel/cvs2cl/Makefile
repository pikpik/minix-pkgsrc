# $NetBSD: Makefile,v 1.1.1.1 1999/09/03 06:25:32 sakamoto Exp $
#

DISTNAME=	cvs2cl-1.117
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	# Nothing

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.red-bean.com/~kfogel/cvs2cl.shtml

USE_PERL5=	YES
NO_BUILD=	YES
NO_PATCH=	YES
EXTRACT_CMD=	${ECHO}

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${LOCALBASE}/bin/${DISTNAME:C/-.*$//}

.include "../../mk/bsd.pkg.mk"
