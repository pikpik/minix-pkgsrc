# $NetBSD: Makefile,v 1.17 2010/01/30 16:28:00 heinz Exp $

.include "../../devel/gettext/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-m4-/}
SVR4_PKGNAME=	gttm4
COMMENT=	Autoconf/automake m4 files for GNU NLS library
LICENSE=	gnu-gpl-v2

NO_BUILD=		yes
NO_CONFIGURE=		yes

INSTALLATION_DIRS+=	share/aclocal

do-install:
	${INSTALL_DATA} ${WRKSRC}/gettext-runtime/m4/*.m4 \
		${DESTDIR}${PREFIX}/share/aclocal
	${INSTALL_DATA} ${WRKSRC}/gettext-tools/m4/*.m4 \
		${DESTDIR}${PREFIX}/share/aclocal

.include "../../mk/bsd.pkg.mk"
