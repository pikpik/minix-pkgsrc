# $NetBSD: Makefile,v 1.2 2004/01/29 06:22:46 xtraeme Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		XFree86-docs-${XF_VER}
PKGREVISION=		1
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XFREE}
DISTFILES+=		X430src-1.tgz X430src-6.tgz

MAINTAINER=		xfree86@blef.org
HOMEPAGE=		http://www.xfree86.org/
COMMENT=		XFree86 Documentation

BUILD_DEPENDS=		imake>=4.3.0:../../x11/imake

USE_BUILDLINK2=		yes
NO_XFREE86_TARGETS=	# defined
WRKSRC=			${WRKDIR}/xc/doc/specs

pre-configure:
	@${SED} \
		-e "s|@PREFIX@|${X11ROOT}|g" \
		-e "s|@MAKE@|${MAKE_PROGRAM}|g" \
		-e "s|@IMAKE@|${IMAKE}|g" \
		${FILESDIR}/host.def > ${WRKSRC}/host.def

do-configure:
	( cd ${WRKSRC}; \
	${IMAKE} -DUseInstalled -I. -I${X11ROOT}/lib/X11/config \
		-DTOPDIR=../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend )

.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
