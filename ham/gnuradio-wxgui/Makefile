# $NetBSD: Makefile,v 1.9 2006/08/06 05:16:50 kristerw Exp $

PKGNAME=	gnuradio-wxgui-${VERSION}
COMMENT=	GUI framework for GNU Radio based on wxPython

PYTHON_PATCH_SCRIPTS+=	gr-wxgui/src/python/fftsink.py
PYTHON_PATCH_SCRIPTS+=	gr-wxgui/src/python/form.py
PYTHON_PATCH_SCRIPTS+=	gr-wxgui/src/python/powermate.py
PYTHON_PATCH_SCRIPTS+=	gr-wxgui/src/python/scopesink.py
PYTHON_PATCH_SCRIPTS+=	gr-wxgui/src/python/slider.py
PYTHON_PATCH_SCRIPTS+=	gr-wxgui/src/python/waterfallsink.py

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONF_FILES+=    ${EGDIR}/gr-wxgui.conf ${PKG_SYSCONFDIR}/gr-wxgui.conf
CONFIGURE_ARGS+=--enable-gr-wxgui

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
