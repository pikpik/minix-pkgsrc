# $NetBSD$
#

DISTNAME=		qmail-qfilter-1.5
CATEGORIES=		mail
MASTER_SITES=		http://untroubled.org/qmail-qfilter/

MAINTAINER=		zuntum@NetBSD.org
HOMEPAGE=		http://untroubled.org/qmail-qfilter/
COMMENT=		qmail-queue multi-filter front end

USE_BUILDLINK2=		yes

REPLACE_PERL=		samples/block-long-dates			\
			samples/deny-filetypes				\
			samples/rename-filetypes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qmail-qfilter ${PREFIX}/bin

	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/qmail-qfilter

	${INSTALL_SCRIPT} ${WRKSRC}/samples/block-long-dates		\
		${PREFIX}/share/examples/qmail-qfilter
	${INSTALL_SCRIPT} ${WRKSRC}/samples/deny-filetypes		\
		${PREFIX}/share/examples/qmail-qfilter
	${INSTALL_SCRIPT} ${WRKSRC}/samples/rename-filetypes		\
		${PREFIX}/share/examples/qmail-qfilter

.include "../../mk/bsd.pkg.mk"
