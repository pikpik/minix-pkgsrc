# $NetBSD: Makefile,v 1.15 2001/06/20 03:22:17 jlam Exp $

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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_DEPENDS+=		flex-*:../../devel/flex
LEX=			${LOCALBASE}/bin/flex
.endif

CONFIGURE_ENV+=		LEX=${LEX}

# touch some carefully selected auto* tools generated files to avoid
# unnecessary regen of them after the pkg's patch had been applied
pre-configure:
	${TOUCH} ${WRKSRC}/aclocal.m4
	${TOUCH} ${WRKSRC}/stamp-h.in
	${TOUCH} ${WRKSRC}/Makefile.in ${WRKSRC}/contrib/Makefile.in \
		${WRKSRC}/doc/Makefile.in ${WRKSRC}/src/Makefile.in

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
