# $NetBSD: Makefile,v 1.6 1998/06/22 12:52:31 agc Exp $
# FreeBSD Id: Makefile,v 1.6 1996/11/17 09:05:15 obrien Exp
#

DISTNAME=       buffer-1.17
CATEGORIES=	misc
MASTER_SITES=   ftp://ftp.sun.ac.za/pub/unix/misc/

MAINTAINER=	packages@netbsd.org

NO_WRKSUBDIR=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-DSYS5
MAKE_ENV+=	CC="${CC}" CPPFLAGS="${CPPFLAGS}"
.endif

.include "../../mk/bsd.pkg.mk"
