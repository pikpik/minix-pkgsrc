# $NetBSD: Makefile,v 1.10 2001/05/14 17:09:26 drochner Exp $
#

.include "../qt2-libs/Makefile.common"

PKGNAME=		qt2-designer-${QTVERSION}
COMMENT=		Visual (WYSIWYG) QT GUI builder

USE_BUILDLINK_ONLY=		yes
BUILDLINK_DEPENDS.qt2-libs=	qt2-libs-${QTVERSION}

ALL_TARGET=		sub-tools

CONFIGURE_ENV+=		QTDIR="${BUILDLINK_DIR}/qt2"
MAKE_ENV+=		QTDIR="${BUILDLINK_DIR}/qt2"

do-install:
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/tools/designer/util/libqutil.la ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/tools/designer/uic/uic ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/tools/designer/designer/designer ${QTPREFIX}/bin

.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
