# $NetBSD: Makefile,v 1.12 2003/07/21 17:01:12 martti Exp $

DISTNAME=       buffer-1.17
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.gwdg.de/pub/linux/jurix/source/system/backup/ \
		ftp://ftp.fu-berlin.de/unix/linux/mirrors/jurix.jura.uni-sb.de/source/system/backup/

MAINTAINER=	tron@NetBSD.org
COMMENT=	Buffer sporadic binary I/O for faster tape use

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-DSYS5
MAKE_ENV+=	CC="${CC}"
.endif

.include "../../mk/bsd.pkg.mk"
