# $NetBSD: Makefile,v 1.6 1999/10/11 00:14:43 jlam Exp $
#

DISTNAME=	libxml-1.8.5
CATEGORIES=	textproc devel lang gnome
MASTER_SITES=	ftp://rpmfind.net/pub/veillard/ \
		${MASTER_SITE_GNOME:=stable/sources/libxml/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://xmlsoft.org/

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	zlib-*:../../devel/zlib
.endif

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
