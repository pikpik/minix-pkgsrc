# $NetBSD: Makefile,v 1.12 2001/06/12 20:33:01 jlam Exp $
#

DISTNAME=		splay-0.8.2
CATEGORIES=		audio
MASTER_SITES=		# empty

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://splay.sourceforge.net/
COMMENT=		Audio player/decoder that decodes MPEG Layer I,II,III and WAV files

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--without-xsplay --without-pthread
LIBS+=			-lossaudio

.include "../../mk/bsd.pkg.mk"
