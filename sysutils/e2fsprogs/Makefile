# $NetBSD: Makefile,v 1.12 2006/04/07 19:54:16 jlam Exp $
#

DISTNAME=	e2fsprogs-1.39
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=e2fsprogs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://e2fsprogs.sourceforge.net/
COMMENT=	Second extended file system (ext2fs) management programs

GNU_CONFIGURE=	yes
USE_TOOLS+=	makeinfo
INFO_FILES=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=--disable-fsck
.endif

.include "../../mk/bsd.pkg.mk"
