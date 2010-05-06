# $NetBSD: Makefile,v 1.7 2009/07/08 14:28:28 joerg Exp $

DISTNAME=	netperf-2.4.5
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.netperf.org/netperf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netperf.org/
COMMENT=	Rick Jones' network performance benchmarking package

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
INFO_FILES=		yes

CFLAGS.IRIX+=		-DIRIX

INSTALLATION_DIRS=	${PKGMANDIR}/man1

# The sources assume <malloc.h> exists.  Create a fake one for platforms
# that don't have it.
post-wrapper:
	if ${TEST} ! -f /usr/include/malloc.h; then		\
		${ECHO} "#include <stdlib.h>"			\
			> ${BUILDLINK_DIR}/include/malloc.h;	\
	fi

.include "../../mk/bsd.pkg.mk"
