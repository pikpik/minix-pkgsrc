# $NetBSD: Makefile,v 1.7 2003/07/17 21:31:39 grant Exp $
#

DISTNAME=	libscsi-1.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.emsi.priv.at/pub/netbsd/contrib/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	FreeBSD SCSI user library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_ENV=	LIBDIR=${PREFIX}/lib MANDIR=${PREFIX}/man NOPIC=1 NOPROFILE=1

MANCOMPRESSED_IF_MANZ=	yes

INSTALLATION_DIRS=	include lib man/cat3 man/man3

.include "../../mk/bsd.pkg.mk"
