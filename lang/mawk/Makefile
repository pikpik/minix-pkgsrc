# $NetBSD: Makefile,v 1.8 2001/02/17 09:07:19 agc Exp $
#

DISTNAME=       mawk-1.3.3
CATEGORIES=	lang
MASTER_SITES=   ftp://ftp.whidbey.net/pub/brennan/ \
		ftp://ftp.fu-berlin.de/pub/unix/languages/mawk/

MAINTAINER=	agc@netbsd.org
COMMENT=	Mike Brennan's fast awk clone

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=              CPPFLAGS=
.endif

.include "../../mk/bsd.pkg.mk"
