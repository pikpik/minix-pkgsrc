# $NetBSD: Makefile,v 1.3 2001/07/28 21:11:25 tron Exp $

DISTNAME=	gtk_wicontrol-0.16
CATEGORIES=	net
MASTER_SITES=	http://www.izawa.sh/software/gtk_wicontrol/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.izawa.sh/software/gtk_wicontrol/
COMMENT=	GTK+-based Wavelan status meter

ONLY_FOR_PLATFORM=	*BSD-*-*

USE_BUILDLINK2=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
