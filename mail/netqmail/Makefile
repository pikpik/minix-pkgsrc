# $NetBSD: Makefile,v 1.1.1.1 2004/07/21 22:42:04 schmonz Exp $
#

PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://qmail.org/netqmail/
COMMENT=	Unofficial distribution of qmail that includes basic patches

CONFLICTS+=	qmail-[0-9]*

USE_BUILDLINK3=	yes

# netqmail is a modification of the qmail source.
RESTRICTED=	"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_PACKAGE=	"needs work to function properly as a binary package"

APPLY_NETQMAIL=	\
	${PATCH} ${PATCH_DIST_ARGS} < ../${DISTNAME}.patch;		\
	cd ..; ${MV} ${QMAIL_VERS} ${DISTNAME}

.include "../../mail/qmail/Makefile.common"

.include "../../mk/bsd.pkg.mk"
