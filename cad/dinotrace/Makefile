# $NetBSD: Makefile,v 1.1.1.1 2000/03/14 19:52:47 dmcmahill Exp $
#

DISTNAME=	dinotrace-9.0k
CATEGORIES=	cad
MASTER_SITES=	http://www.ultranet.com/~wsnyder/veripool/ftp/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE= 	http://www.ultranet.com/~wsnyder/veripool/dinotrace/

INFO_FILES=	dinotrace.info

GNU_CONFIGURE=	YES

USE_MOTIF=	YES

#avoid having this installed later
post-patch:
	${RM} ${WRKSRC}/dinotrace.info.orig

.include "../../mk/bsd.pkg.mk"
