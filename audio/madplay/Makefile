# $NetBSD: Makefile,v 1.6 2000/11/14 01:40:15 wiz Exp $
#

DISTNAME=	mad-0.12.2b
PKGNAME=	${DISTNAME:S/mad/madplay/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/} \
		ftp://ftp.mars.org/pub/mpeg/

MAINTAINER=	simonb@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/mad/

BUILD_DEPENDS+= msgfmt:../../devel/gettext

GNU_CONFIGURE=	YES
USE_LIBINTL=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
