# $NetBSD: Makefile,v 1.4 2001/11/28 05:20:41 jlam Exp $

DISTNAME=	gtkyahoo-0.18.2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkyahoo/} \
		http://www.unixtools.org/gtkyahoo/dist/

MAINTAINER=	ken@246gt.com
HOMEPAGE=	http://www.unixtools.org/gtkyahoo/
COMMENT=	GTK+ client for Yahoo! Messenger

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-libyahoo="${BUILDLINK_PREFIX.libyahoo}"

pre-configure:
	${RM} -rf ${WRKSRC}/libyahoo

.include "../../chat/libyahoo/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
