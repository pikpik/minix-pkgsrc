# $NetBSD: Makefile,v 1.1.1.1 2011/08/12 13:09:03 taca Exp $
#

DIST_SUBDIR=	${CT_DIST_SUBDIR}
LICENSE=	gnu-lgpl-v3

CT_VERS=	210

pre-patch:
	${FIND} ${WRKSRC} -name '._*' -exec ${RM} '{}' \;

.include "../../www/contao/Makefile.example"
.include "../../www/contao/Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
