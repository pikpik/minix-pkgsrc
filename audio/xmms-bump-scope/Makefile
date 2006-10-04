# $NetBSD: Makefile,v 1.14 2006/03/04 21:28:59 jlam Exp $
#

DISTNAME=	bump_scope-0.0.3
PKGNAME=	xmms-bump-scope-0.0.3
PKGREVISION=	5
CATEGORIES=	xmms audio
MASTER_SITES=	http://zinx.xmms.org/xmms/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zinx.xmms.org/xmms/
COMMENT=	Moving light embossing oscilloscope

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

MAKE_ENV+=	plugindir=${PREFIX}/lib/xmms/Visualization

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
