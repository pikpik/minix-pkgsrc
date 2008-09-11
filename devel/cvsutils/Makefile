# $NetBSD$
#

DISTNAME=		cvsutils-0.2.5
CATEGORIES=		devel
MASTER_SITES=		http://www.red-bean.com/cvsutils/releases/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.red-bean.com/cvsutils/
COMMENT=		CVS utilities to facilitate working

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:run

REPLACE_PERL=		*.pl
REPLACE_SH=		*.sh

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR} &&\ cd ${WRKSRC} &&	\
		${INSTALL_DATA} README NEWS ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
