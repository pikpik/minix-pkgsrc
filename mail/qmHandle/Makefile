# $NetBSD: Makefile,v 1.3 2001/06/04 22:26:32 jtb Exp $
#

DISTNAME=	qmHandle-0.5.1
CATEGORIES=	mail
MASTER_SITES=	http://www.io.com/~mick/soft/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.io.com/~mick/soft/qmhandle.html
COMMENT=	tool to view and manage the qmail message queue

RESTRICTED=	"Contact author before reselling"

DEPENDS+=	qmail>=1.03:../../mail/qmail

WRKSRC=		${WRKDIR}

USE_PERL5=	YES
REPLACE_PERL=	qmHandle
NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qmHandle ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/qmHandle.README

.include "../../mk/bsd.pkg.mk"
