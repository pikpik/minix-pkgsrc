# $NetBSD: Makefile,v 1.26 2004/05/28 00:54:50 lukem Exp $
#

DISTNAME=		enscript-1.6.3
PKGREVISION=		1
CATEGORIES=		print
MASTER_SITES=		http://www.iki.fi/mtr/genscript/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://people.ssh.fi/mtr/genscript/
COMMENT=		ASCII-to-PostScript filter

DEPENDS+=		papersize-[0-9]*:../../print/papersize

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_PKGINSTALL=		yes
USE_GNU_TOOLS+=		make

CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"

EGDIR=			${PREFIX}/share/examples/enscript
CONF_FILES=		${EGDIR}/enscript.cfg ${PKG_SYSCONFDIR}/enscript.cfg

.include "../../mk/bsd.prefs.mk"
.if defined(PAPERSIZE)
CONFIGURE_ARGS+=--with-media="${PAPERSIZE}"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
