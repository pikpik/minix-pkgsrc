# $NetBSD: Makefile,v 1.14 2000/11/01 03:41:28 itojun Exp $

DISTNAME=	bison-1.28
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=bison/}

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/bison/bison.html

BUILD_DEPENDS+=	msgfmt:../../devel/gettext

GNU_CONFIGURE=	yes

INFO_FILES=	bison.info

USE_LIBINTL=	YES
CPPFLAGS+=	-Dunix				# for $TMPDIR parsing
CONFIGURE_ARGS+=--without-included-gettext

.include "../../mk/bsd.pkg.mk"
