# $NetBSD: Makefile,v 1.2 2000/03/27 08:54:58 tron Exp $

DISTNAME=		gcc-2.95.2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gcc/gcc.html

BUILD_DEPENDS+=		${LOCALBASE}/bin/bison:../../devel/bison

# TODO:
# - rename binaries to avoid conflicts with base distribution
# - improve directory structure
# - support more platforms

# NetBSD-arm32 is the only tested platform so far. If you got it
# working on other platforms please add them.
ONLY_FOR_PLATFORM=	NetBSD-*-arm32

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${SRCDIR}/configure
CONFIGURE_ARGS+=	--with-gnu-as --with-gnu-ld

SRCDIR=			${WRKDIR}/${DISTNAME}
WRKSRC=			${WRKDIR}/objdir

post-extract:
	${MKDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
