# $NetBSD: Makefile,v 1.5 2004/02/22 20:48:16 jmmv Exp $
#

DISTNAME=	netbsd-www-1.0
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	grant@NetBSD.org
COMMENT=	Packages required to build the NetBSD.org web site

DEPENDS+=	docbook-website>=2.3nb3:../../textproc/docbook-website
DEPENDS+=	libxslt>=1.0.20:../../textproc/libxslt
DEPENDS+=	ImageMagick>=5.5.7.11nb1:../../graphics/ImageMagick
DEPENDS+=	xearth>=1.1:../../x11/xearth
DEPENDS+=	perl-[0-9]*:../../lang/perl5

EXTRACT_ONLY=	# defined
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined
NO_MTREE=	# defined

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
