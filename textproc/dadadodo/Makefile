# $NetBSD$
#

DISTNAME=		dadadodo-1.04
CATEGORIES=		textproc
MASTER_SITES=		http://www.jwz.org/dadadodo/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.jwz.org/dadadodo/
COMMENT=		Analyse texts for word probabilities and generate random sentences
# near enough
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin share/doc/dadadodo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dadadodo ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dadadodo

.include "../../mk/bsd.pkg.mk"
