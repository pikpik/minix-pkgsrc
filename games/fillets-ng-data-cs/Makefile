# $NetBSD$
#

DISTNAME=	fillets-ng-data-cs-0.5.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fillets/}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://fillets.sf.net/
COMMENT=	Fish Fillets NG data files (Czech audio)

DEPENDS+=	fillets-ng-data>=0.5.1:../../games/fillets-ng-data

NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/games/fillets-ng
	cd ${WRKSRC} && \
		${PAX} -rw -pm sound ${PREFIX}/share/games/fillets-ng/

.include "../../mk/bsd.pkg.mk"
