# $NetBSD: Makefile,v 1.7 2003/01/27 19:43:59 jmmv Exp $
#

DISTNAME=	gq-0.3.0
PKGREVISION=	1
CATEGORIES=	databases net
MASTER_SITES=	http://biot.com/gq/download/ \
		${MASTER_SITE_SOURCEFORGE:=gqclient/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://biot.com/gq/
COMMENT=	GTK-based LDAP client

DEPENDS+=	gnome1-dirs>=1.0:../../misc/gnome1-dirs

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../databases/openldap/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
