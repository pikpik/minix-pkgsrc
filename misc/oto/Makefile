# $NetBSD: Makefile,v 1.1 2002/05/11 11:39:13 cjep Exp $
#

DISTNAME=	oto-0.4
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.sourceforge.net/pub/sourceforge/oto/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/oto/
COMMENT=	list, modify OpenType font files

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/oto
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/oto

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/libgetopt/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
