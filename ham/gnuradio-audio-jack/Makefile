# $NetBSD: Makefile,v 1.3 2008/07/31 04:02:40 bjs Exp $

PKGNAME=	gnuradio-audio-jack-${VERSION}
COMMENT=	GNU Radio module for jack low latency audio server

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONF_FILES+=    ${EGDIR}/gr-audio-jack.conf ${PKG_SYSCONFDIR}/gr-audio-jack.conf
CONFIGURE_ARGS+=--enable-gr-audio-jack
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

PYTHON_PATCH_SCRIPTS+=	gr-audio-jack/src/python/qa_jack.py

.include "../../audio/jack/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
