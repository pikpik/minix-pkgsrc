# $NetBSD: Makefile,v 1.3 2001/02/16 14:38:24 wiz Exp $
#

DISTNAME=	g-wrap-0.9.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnucash.org/pub/g-wrap/source/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://web.mit.edu/chlee/www/Software/g-wrap/index.html
COMMENT=	tool for importing types, functions, and constants into guile

DEPENDS+=	guile>=1.3.4:../../lang/guile

GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	ac_cv_path_RSCHEME="nope"

USE_LIBTOOL=	# defined
LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
