# $NetBSD: Makefile,v 1.8 2008/03/03 17:45:36 jlam Exp $

.include "Makefile.common"

PKGREVISION=	3
COMMENT=	Windowing toolkit based on libslang

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
NO_EXPORT_CPP=	yes
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin include lib

do-install:
	cd ${WRKSRC}; \
	 ${LIBTOOL} --mode=install ${INSTALL_PROGRAM} libnewt.la ${DESTDIR}${PREFIX}/lib;\
	 ${INSTALL_DATA} newt.h ${DESTDIR}${PREFIX}/include; \
	 ${LIBTOOL} --mode=install ${INSTALL} whiptail ${DESTDIR}${PREFIX}/bin

.include "../../devel/libslang/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
