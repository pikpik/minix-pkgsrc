# $NetBSD: Makefile,v 1.37 2009/07/22 09:25:02 wiz Exp $

DISTNAME=	binutils-2.21.1
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://directory.fsf.org/project/binutils/
COMMENT=	GNU binary utilities

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	avr-binutils<2.13.2.1nb1

NOT_FOR_PLATFORM=	Darwin-*-* Interix-*-*

USE_PKGLOCALEDIR=	yes
REPLACE_LOCALEDIR_PATTERNS+=	Make-in

USE_TOOLS+=		makeinfo perl
TEXINFO_REQD=		4.0
MAKEFLAGS+=		TEXINFO_LOCALE=no

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-lib-path='/lib:/usr/lib'
BINUTILS_PROGRAM_PREFIX?=	gnu-
CONFIGURE_ARGS+=	--program-prefix=${BINUTILS_PROGRAM_PREFIX:Q}
PLIST_SUBST+=		BINUTILS_PROGRAM_PREFIX=${BINUTILS_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		BINUTILS_PROGRAM_PREFIX
BINUTILS_PREFIX=	${PREFIX}/${MACHINE_GNU_PLATFORM}

PLIST_SRC=	${PKGDIR}/PLIST.common
PLIST_SRC+=	${WRKDIR}/PLIST_DYNAMIC

INFO_FILES=	# PLIST

# gprof (XXX: and others?) cannot be built on all platforms
#
PLIST_VARS+=	gprof
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "IRIX" &&  ${OPSYS} != "Minix"
PLIST.gprof=	yes
.endif

# Prevent the need to run texi2pod.pl and pod2man hence
# the need for perl as build dependency.
#
post-configure:
.for f in ld/ldver.texi ld/ld.1 gas/doc/gasver.texi gas/doc/as.1
	if [ -f ${WRKSRC}/${f} ]; then					\
		touch ${WRKSRC}/${f};					\
	fi
.endfor

post-install:
	cd ${DESTDIR}${PREFIX} && find ${MACHINE_GNU_PLATFORM}/lib/ldscripts -type f -print	\
		| sort -r						\
		> ${WRKDIR}/PLIST_DYNAMIC

.include "../../mk/bsd.pkg.mk"
