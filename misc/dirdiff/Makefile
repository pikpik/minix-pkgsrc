# $NetBSD: Makefile,v 1.6 2004/10/03 00:12:58 tv Exp $
#

DISTNAME=	dirdiff-1.6
PKGREVISION=	2
CATEGORIES=	misc tk80
MASTER_SITES=	http://samba.org/ftp/paulus/

DEPENDS=	tk>=8.3.4:../../x11/tk

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://samba.org/ftp/paulus/
COMMENT=	Displays differences between directories

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
