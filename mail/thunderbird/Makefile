# $NetBSD: Makefile,v 1.2 2004/04/26 13:56:09 taya Exp $

MOZILLA=	thunderbird
MOZILLA_BIN=	thunderbird-bin
MOZ_VER=	0.6
EXTRACT_SUFX=	.tar.bz2
DISTNAME=	thunderbird-source-${MOZ_VER}
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/thunderbird/releases/${MOZ_VER}/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/thunderbird/releases/${MOZ_VER}/

HOMEPAGE=	http://www.mozilla.org/projects/thunderbird/
COMMENT=	Redesign of the Mozilla mail client

CONFIGURE_ENV+=	MOZ_THUNDERBIRD=1
MAKE_ENV+=	MOZ_THUNDERBIRD=1

CONFIGURE_ARGS+=	--enable-extensions=wallet,spellcheck,xmlextras

.include "../../www/mozilla/Makefile.common"
