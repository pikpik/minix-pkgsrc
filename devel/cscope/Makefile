# $NetBSD: Makefile,v 1.17 2001/10/03 15:06:15 wiz Exp $
#

DISTNAME=	cscope-15.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cscope/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cscope.sourceforge.net/
COMMENT=	interactive C program browser

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-flex
AUTOMAKE_OVERRIDE=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_DEPENDS+=		flex-*:../../devel/flex
LEX=			${LOCALBASE}/bin/flex
.endif

CONFIGURE_ENV+=		LEX=${LEX}

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
