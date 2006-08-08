# $NetBSD: Makefile,v 1.15 2006/03/04 21:30:51 jlam Exp $
#

DISTNAME=	raptor-1.4.10
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://librdf.org/raptor/
COMMENT=	RDF Parser Toolkit written in C

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

PKGCONFIG_OVERRIDE+=	raptor.pc.in
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
