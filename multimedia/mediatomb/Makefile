# $NetBSD: Makefile,v 1.69 2006/10/09 12:52:34 joerg Exp $

DISTNAME=	mediatomb-0.11.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mediatomb/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://mediatomb.cc/
COMMENT=	UPnP MediaServer with a web user interface

GNU_CONFIGURE=	yes

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

PREFER.bind=	pkgsrc	# we need the package for the lwres lib

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../net/bind9/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
