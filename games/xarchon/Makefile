# $NetBSD: Makefile,v 1.9 2000/06/30 10:04:46 agc Exp $
#

DISTNAME=	xarchon-0.50
CATEGORIES=	games x11
MASTER_SITES=	http://xarchon.seul.org/ \
		ftp://xarchon.seul.org/pub/xarchon/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://xarchon.seul.org/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	esound-*:../../audio/esound

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-xpm-prefix=${XPM_PREFIX} \
		--with-gtk-prefix=${GTK_PREFIX} \
		--with-esd-prefix=${LOCALBASE}

GTK_PREFIX!=	${PKG_INFO} -qp gtk+ | ${AWK} '{print $$2}'
XPM_PREFIX!=	${PKG_INFO} -qp xpm | ${AWK} '{print $$2}'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	CC="${CC}"
.endif

.include "../../mk/bsd.pkg.mk"
