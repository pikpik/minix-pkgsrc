# $NetBSD: Makefile,v 1.7 1998/08/20 15:16:45 tsarna Exp $

DISTNAME=	bison-1.27
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=/bison/}

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/bison/bison.html

GNU_CONFIGURE=	yes
# needed for $TMPDIR parsing
CFLAGS+=	-Dunix

INFO_FILES=	bison.info

.include "../../mk/bsd.pkg.mk"
