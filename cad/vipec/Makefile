# $NetBSD: Makefile,v 1.28 2002/09/20 21:13:39 jlam Exp $
#

DISTNAME=	ViPEC-3.1.3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vipec/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://vipec.sourceforge.net
COMMENT=	Network analyser for electrical networks

BUILD_DEPENDS+=		tmake-*:../../devel/tmake

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GMAKE=		yes

CONFLICTS+=		vipec-[0-9]*

post-patch:
	${SED} 's;@prefix@;${PREFIX};g' < ${FILESDIR}/vipec.sh.in > ${WRKDIR}/vipec.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/vipec.sh ${PREFIX}/bin/vipec
	${INSTALL_DATA} ${WRKSRC}/vipec.cfg ${PREFIX}/vipec

.include "../../x11/qt2-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
