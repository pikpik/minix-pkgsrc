# $NetBSD: Makefile,v 1.36 2000/10/28 00:36:38 mjl Exp $
#

ETHEREAL_VERSION=	0.8.14
DISTNAME=		ethereal-${ETHEREAL_VERSION}
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ethereal.com/pub/ethereal/ \
			ftp://ftp.sunet.se/pub/network/monitoring/ethereal/

MAINTAINER=		frueauf@netbsd.org
HOMEPAGE=		http://www.ethereal.com/

DEPENDS=		gtk+-1.2.*:../../x11/gtk
BUILD_DEPENDS+=		${PERL5}:../../lang/perl5-base

USE_X11=		yes
GNU_CONFIGURE=		yes
EVAL_PREFIX+=		GTKDIR=gtk+
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}"

PLIST_SUBST+=		ETHEREAL_VERSION=${ETHEREAL_VERSION}

.include "../../mk/bsd.pkg.mk"
