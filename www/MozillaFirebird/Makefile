# $NetBSD: Makefile,v 1.15 2003/07/13 13:53:51 wiz Exp $

MOZILLA=	MozillaFirebird
MOZILLA_BIN=	MozillaFirebird-bin
MOZ_VER=	0.6.1
EXTRACT_SUFX=	.tar.bz2
DISTNAME=       MozillaFirebird-source-${MOZ_VER}
#MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITES=	ftp://ftp.mozilla.org/pub/firebird/releases/${MOZ_VER}/

HOMEPAGE=	http://www.mozilla.org/projects/firebird/
COMMENT=	Lightweight gecko-based web browser

CONFIGURE_ENV+=	MOZ_PHOENIX=1
MAKE_ENV+=	MOZ_PHOENIX=1

CONFIGURE_ARGS+=	--disable-mailnews
CONFIGURE_ARGS+=	--disable-composer

.include	"../../www/mozilla/Makefile.common"
