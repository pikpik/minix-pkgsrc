# $NetBSD: Makefile,v 1.2 2001/07/27 20:32:01 agc Exp $
#

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
PKGDIR=			${.CURDIR}/../../shells/tcsh/pkg

CONFLICTS=		tcsh-[0-9]*

.include "../../shells/tcsh/Makefile"

WRKSRC:=		${WRKDIR}/${PKGNAME}
PKGNAME:=		static-${PKGNAME}
COMMENT:=		Statically-linked version of the ${COMMENT}

LDFLAGS+=		-static
