# $NetBSD: Makefile,v 1.3 1998/09/22 06:11:35 garbled Exp $
# FreeBSD Id: Makefile,v 1.6 1996/11/18 11:22:35 asami Exp
#

DISTNAME=	bcc
PKGNAME=	bcc-95.3.12
CATEGORIES=	devel

MAINTAINER=	tsarna@netbsd.org

NOT_FOR_ARCHS=	alpha	#Severe LP64 problems

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=	yes
.endif

.include "../../mk/bsd.pkg.mk"
