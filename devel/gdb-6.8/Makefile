# $NetBSD$
#

DISTNAME=	gdb-6.8
CATEGORIES=	devel
MASTER_SITES=	ftp://sources.redhat.com/pub/gdb/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=     minix@minix3.org	
HOMEPAGE=	ftp://sources.redhat.com/pub/gdb/releases/
COMMENT=        GNU Debugger	
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=             gmake 
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=       yes
REPLACE_LOCALEDIR_PATTERNS+=    Make-in
GNU_CONFIGURE=          yes
CONFIGURE_ARGS+=        --disable-tui
CONFIGURE_ARGS+=        --libdir=${PREFIX}/lib/gdb-6.8
CONFIGURE_ARGS+=        --includedir=${PREFIX}/include/gdb-6.8
#INFO_FILES=             yes

pre-patch:
	${CP} ${FILESDIR}/i386minix.c ${WRKSRC}/bfd
	${CP} ${FILESDIR}/i386minix-nat.c ${WRKSRC}/gdb
	${CP} ${FILESDIR}/i386minix-tdep.c ${WRKSRC}/gdb
	${CP} ${FILESDIR}/minix.mh ${WRKSRC}/gdb/config/i386
	${CP} ${FILESDIR}/nm-minix.h ${WRKSRC}/gdb/config/i386

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
