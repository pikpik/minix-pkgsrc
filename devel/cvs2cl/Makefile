# $NetBSD: Makefile,v 1.8 2004/01/20 12:13:28 agc Exp $
#

DISTNAME=	cvs2cl-1.117
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	# Nothing

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.red-bean.com/~kfogel/cvs2cl.shtml
COMMENT=	CVS-log-message-to-ChangeLog conversion script

EXTRACT_CMD=	${ECHO}
WRKSRC=		${WRKDIR}
NO_BUILDLINK=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_PERL5=	# defined

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} \
		${LOCALBASE}/bin/${DISTNAME:C/-.*$//}

.include "../../mk/bsd.pkg.mk"
