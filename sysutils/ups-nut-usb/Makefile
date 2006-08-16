# $NetBSD$

.include "../../sysutils/ups-nut/Makefile.common"

PKGNAME=		${DISTNAME:S/nut/ups-nut-usb/}
COMMENT=		Network UPS Tools USB drivers

DEPENDS+=		ups-nut-2.*:../../sysutils/ups-nut

BUILD_TARGET=		all usb
INSTALL_TARGET=		install-usb

BUILD_DEFS+=		NUT_STATEDIR

CONFIGURE_ARGS+=	--with-drvpath=${NUT_DRVDIR:Q}

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
